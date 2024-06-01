//
// Created by Jakub Sap on 01/06/2024.
//

#include "separate_chaining.h"

// Write code for the SeparateChaining class here

template <typename T>
SeparateChaining<T>::SeparateChaining() {
    // Initialize the hash table
    table.resize(10);
}

template <typename T>
SeparateChaining<T>::SeparateChaining(int size) {
    // Initialize the hash table
    table.resize(size);
}

template <typename T>
void SeparateChaining<T>::insert(T key) {
    // Get the hash value of the key
    int index = hash(key);

    // Insert the key into the list at the hash value
    table[index].push_back(key);
}

template <typename T>
bool SeparateChaining<T>::search(T key) {
    // Get the hash value of the key
    int index = hash(key);

    // Search for the key in the list at the hash value
    auto it = std::find(table[index].begin(), table[index].end(), key);

    // Return true if the key is found, false otherwise
    return it != table[index].end();
}

template <typename T>
void SeparateChaining<T>::remove(T key) {
    // Get the hash value of the key
    int index = hash(key);

    // Remove the key from the list at the hash value
    table[index].remove(key);
}

template <typename T>
void SeparateChaining<T>::display() {
    // Iterate over each list in the table
    for (int i = 0; i < table.size(); i++) {
        std::cout << i << ": ";
        for (auto it = table[i].begin(); it != table[i].end(); it++) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
}

template <typename T>
int SeparateChaining<T>::hash(T key) {
    // Use the modulo operator to get the hash value
    return key % table.size();
}