//
// Created by Jakub Sap on 01/06/2024.
//

#include <iostream>
#include <vector>
#include "separate_chaining.h"

HashTable::HashTable(int size) {
    table = std::vector<Node*>(size, nullptr);
}

int HashTable::hashFunction(int key) {
    return key % table.size();
}

void HashTable::insert(int key) {
    int index = hashFunction(key);  // Obliczenie indeksu
    Node* newNode = new Node(key);

    if(table[index] == nullptr) {
        table[index] = newNode;
    } else {
        Node* temp = table[index];
        while(temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

bool HashTable::deleteKey(int key) {
    int index = hashFunction(key);
    Node* temp = table[index];
    Node* prev = nullptr;

    while(temp != nullptr && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == nullptr) {
        return false;
    }

    if(prev == nullptr) {
        table[index] = temp->next;
    } else {
        prev->next = temp->next;
    }

    delete temp;
    return true;
}

void HashTable::display() {
    for(int i = 0; i < table.size(); i++) {
        std::cout << i << ": ";
        Node* temp = table[i];
        while(temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
}

