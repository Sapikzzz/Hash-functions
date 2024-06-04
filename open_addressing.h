//
// Created by Jakub Sap on 01/06/2024.
//

#ifndef OPEN_ADDRESSING_H
#define OPEN_ADDRESSING_H

#include <vector>

class oaTable {
private:
    std::vector<int> table;
    int size;
    int capacity;

    int hashFunction(int key);

public:
    oaTable(int capacity);
    void insert(int key);
    void deleteKey(int key);
    void display();
};

#endif //OPEN_ADDRESSING_H
