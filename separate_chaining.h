//
// Created by Jakub Sap on 01/06/2024.
//

#ifndef SEPARATE_CHAINING_H
#define SEPARATE_CHAINING_H

// Write code for the SeparateChaining class here

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>
#include <stdexcept>

template <typename T>
class SeparateChaining {
public:
    SeparateChaining();
    SeparateChaining(int size);
    void insert(T key);
    bool search(T key);
    void remove(T key);
    void display();
private:
    std::vector<std::list<T>> table;
    int hash(T key);
};

#endif //SEPARATE_CHAINING_H
