//
// Created by Jakub Sap on 01/06/2024.
//

#ifndef CUCKOO_HASHING_H
#define CUCKOO_HASHING_H

#include <vector>


class CuckooHash {
private:
    std::vector<std::vector<int>> table;
    int num_buckets;

    int hash1(int key) const;
    int hash2(int key) const;
    int insert_helper(int key, unsigned int loop_count);

    int MAX_LOOPS = 50;

public:
    CuckooHash(unsigned int size);
    ~CuckooHash();

    int insert(int key);
    int remove(int key);
    void display() const;
};

#endif //CUCKOO_HASHING_H
