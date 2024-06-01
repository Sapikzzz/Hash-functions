//
// Created by Jakub Sap on 01/06/2024.
//

#include "cuckoo_hashing.h"
#include <iostream>
#include <random>

CuckooHash::CuckooHash(int capacity, int numHashFunctions): size(0), numHashFunctions(numHashFunctions) {
    table.resize(numHashFunctions);
    for (int i = 0; i < numHashFunctions; i++) {
        table[i].resize(capacity);
    }
}

int CuckooHash::hashFunction(int key, int i) const {
    // Simple hash function: key % table size
    // In practice, use better hash functions
    return (key + i) % table[i].size();
}

bool CuckooHash::rehash() {
    std::vector<int> oldKeys;
    for (int i = 0; i < numHashFunctions; i++) {
        for (int j = 0; j < table[i].size(); j++) {
            if (table[i][j] != -1) {
                oldKeys.push_back(table[i][j]);
            }
        }
    }

    // Create a new table with double the capacity
    std::vector<std::vector<int>> newTable(numHashFunctions, std::vector<int>(table[0].size() * 2, -1));
    size = 0;

    // Re-insert all keys into the new table
    for (int key : oldKeys) {
        if (!insert(key)) {
            return false; // Failed to rehash
        }
    }

    table.swap(newTable);
    return true;
}

void CuckooHash::insert(int key) {
    int i = 0;
    while (i < MAX_ITERATIONS) {
        for (int j = 0; j < numHashFunctions; j++) {
            int index = hashFunction(key, j);
            if (table[j][index] == -1) {
                table[j][index] = key;
                size++;
                return;
            }
        }

        // Displace an existing key and insert the new key
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, numHashFunctions - 1);
        int r = dis(gen);
        int index = hashFunction(key, r);
        int displacedKey = table[r][index];
        table[r][index] = key;
        key = displacedKey;
        i++;
    }

    // Failed to insert after MAX_PROBES, rehash the table
    if (rehash()) {
        insert(key);
    } else {
        std::cout << "Failed to insert " << key << std::endl;
    }
}

bool CuckooHash::search(int key) {
    for (int i = 0; i < numHashFunctions; i++) {
        int index = hashFunction(key, i);
        if (table[i][index] == key) {
            return true;
        }
    }
    return false;
}

bool CuckooHash::deleteKey(int key) {
    for (int i = 0; i < numHashFunctions; i++) {
        int index = hashFunction(key, i);
        if (table[i][index] == key) {
            table[i][index] = -1;
            size--;
            return true;
        }
    }
    return false;
}

void CuckooHash::display() {
    for (int i = 0; i < numHashFunctions; i++) {
        std::cout << "Table " << i << ": ";
        for (int j = 0; j < table[i].size(); j++) {
            if (table[i][j] == -1) {
                std::cout << "- ";
            } else {
                std::cout << table[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
}