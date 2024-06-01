#include <iostream>
#include "separate_chaining.h"

using namespace std;

int main() {
    HashTable scTable(7);   // Hash table for separate chaining

    for(int i =0; i < 2000; i++) {
        scTable.insert(i);
    }

    scTable.display();

    return 0;
}