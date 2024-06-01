//
// Created by Jakub Sap on 01/06/2024.
//

#ifndef CUCKOO_HASHING_H
#define CUCKOO_HASHING_H

#include <vector>

const int MAX_ITERATIONS = 1000;

class CuckooHash {
private:
    std::vector<std::vector<int>> table;
    int size;
    int numHashFunctions;

    int hashFunction(int key, int i) const;
    bool rehash();

public:
    CuckooHash(int capacity, int numHashFunctions);
    void insert(int key);
    bool search(int key);
    bool deleteKey(int key);
    void display();
};

#endif //CUCKOO_HASHING_H
