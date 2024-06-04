//
// Created by Jakub Sap on 01/06/2024.
//

#ifndef SEPARATE_CHAINING_H
#define SEPARATE_CHAINING_H

#include <vector>
#include <list>

struct Node {   // Node dla listy jednokierunkowej
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class scTable {
private:
    std::vector<Node*> table;
    int size;
public:
    scTable(int size);    // Konstruktor używany do inicjalizacji tablicy o podanej wielkosci
    int hashFunction(int key);  // Funkcja obliczająca indeks na podstawie wielkosci tablicy
    void insert(int key);
    void deleteKey(int key);
    void display();
};

#endif //SEPARATE_CHAINING_H
