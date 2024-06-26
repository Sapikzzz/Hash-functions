//
// Created by Jakub Sap on 01/06/2024.
//

#include "open_addressing.h"
#include <iostream>

oaTable::oaTable(int capacity) : capacity(capacity) {
    size = 0;
    table = std::vector<int>(capacity, -1);  // Initialize with -1 (empty)
}

int oaTable::hashFunction(int key) {
    return key % capacity;
}

void oaTable::insert(int key) {
    if (size == capacity) {
        std::cout << "Hash table is full, cannot insert " << key << std::endl;
        return;
    }

    int index = hashFunction(key);
    int probe = 0;

    // Linear probing
    while (table[(index + probe) % capacity] != -1) {
        probe++;
    }

    table[(index + probe) % capacity] = key;
    size++;
}


void oaTable::deleteKey(int key) {
    int index = hashFunction(key);
    int probe = 0;

    // Linear probing
    while (table[(index + probe) % capacity] != -1) {
        if (table[(index + probe) % capacity] == key) {
            table[(index + probe) % capacity] = -2;
            size--;
        }
        probe++;
    }

}

void oaTable::display() {
    for (int i = 0; i < capacity; i++) {
        std::cout << i << ": " << table[i] << std::endl;
    }
}