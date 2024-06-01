#include <iostream>
#include "separate_chaining.h"
#include "open_addressing.h"
#include "cuckoo_hashing.h"

using namespace std;

int main() {
    scTable scTable(7);   // Hash table for separate chaining
    oaTable oaTable(10);   // Hash table for open addressing
    CuckooHash cuckooHash(10, 2);

    for(int i =0; i < 2000; i++) {
        scTable.insert(i);
    }

    oaTable.insert(7);
    oaTable.insert(36);
    oaTable.insert(18);
    oaTable.insert(62);



    scTable.display();
    oaTable.display();
    return 0;
}