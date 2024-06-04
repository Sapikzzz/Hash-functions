//
// Created by Jakub Sap on 01/06/2024.
//

#include "cuckoo_hashing.h"
#include <iostream>
#include <random>

CuckooHash::CuckooHash(unsigned int size)
        : table(2, std::vector<int>(size, -1)), num_buckets(size) {}

CuckooHash::~CuckooHash() {}

int CuckooHash::insert(int key) {
    return insert_helper(key, 0);
}

int CuckooHash::remove(int key) {
    unsigned int hash1_val = hash1(key);
    unsigned int hash2_val = hash2(key);

    if (table[0][hash1_val] == key) {
        table[0][hash1_val] = -1;
        return 0; // Key removed successfully
    }

    if (table[1][hash2_val] == key) {
        table[1][hash2_val] = -1;
        return 0; // Key removed successfully
    }

    return -2; // Key not found
}

int CuckooHash::hash1(int key) const {
    return key % num_buckets;
}

int CuckooHash::hash2(int key) const {
    return (key / num_buckets) % num_buckets;
}

int CuckooHash::insert_helper(int key, unsigned int loop_count) {
    if (loop_count > MAX_LOOPS)
        return -1; // Maximum iterations reached, could not insert key

    unsigned int hash1_val = hash1(key);
    unsigned int hash2_val = hash2(key);

    if (table[0][hash1_val] == key || table[1][hash2_val] == key) {
        return 0; // Key already present
    }

    if (table[0][hash1_val] == -1) {
        table[0][hash1_val] = key;
        return 0; // Key inserted successfully
    }

    if (table[1][hash2_val] == -1) {
        table[1][hash2_val] = key;
        return 0; // Key inserted successfully
    }

    // Displace existing key and place the new key in its place
    int displaced_key = table[0][hash1_val];
    table[0][hash1_val] = key;

    // Try to insert the displaced key in the other table
    return insert_helper(displaced_key, loop_count + 1);
}

void CuckooHash::display() const {
    std::cout << "Table 1:" << std::endl;
    for (unsigned int i = 0; i < num_buckets; ++i) {
        if (table[0][i] == -1) {
            std::cout << "[" << i << "]: " << "empty" << std::endl;
        } else {
            std::cout << "[" << i << "]: " << table[0][i] << std::endl;
        }
    }

    std::cout << "Table 2:" << std::endl;
    for (unsigned int i = 0; i < num_buckets; ++i) {
        if (table[1][i] == -1) {
            std::cout << "[" << i << "]: " << "empty" << std::endl;
        } else {
            std::cout << "[" << i << "]: " << table[1][i] << std::endl;
        }
    }
}