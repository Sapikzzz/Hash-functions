//
// Created by Jakub Sap on 01/06/2024.
//

#include <iostream>
#include <vector>
#include "separate_chaining.h"


scTable::scTable(int size) {
    table = std::vector<Node*>(size, nullptr);
}

int scTable::hashFunction(int key) {
    return key % table.size();
}

void scTable::insert(int key) {
    int index = hashFunction(key);
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

void scTable::deleteKey(int key) {
    int index = hashFunction(key);
    Node* temp = table[index];
    Node* prev = nullptr;

    while(temp != nullptr && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == nullptr) {
        std::cout << "Key not found" << std::endl;
        return;
    }

    if(prev == nullptr) {
        table[index] = temp->next;
    } else {
        prev->next = temp->next;
    }

    delete temp;
}

void scTable::display() {
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

