#include <iostream>
#include "separate_chaining.h"
#include "open_addressing.h"
#include "cuckoo_hashing.h"
#include <chrono>

using namespace std;

int main() {
    scTable scTable(3);   // Hash table for separate chaining
    oaTable oaTable(10);   // Hash table for open addressing
    CuckooHash cuckooHash(10, 2);

    // Take time for insert
    for(int i = 0; i < 3000; i=i+3) {
        scTable.insert(i);
    }
    auto start = chrono::high_resolution_clock::now();
    scTable.insert(3003);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds >(end - start);
    cout << "Time taken for insert in separate chaining: " << duration.count() << " nanoseconds" << endl;

    for(int i = 3003; i < 6000; i=i+3) {
        scTable.insert(i);
    }

    auto start1 = chrono::high_resolution_clock::now();
    scTable.insert(6003);
    auto end1 = chrono::high_resolution_clock::now();
    auto duration1 = chrono::duration_cast<chrono::nanoseconds >(end1 - start1);
    cout << "Time taken for insert in separate chaining: " << duration1.count() << " nanoseconds" << endl;
    //scTable.display();
    return 0;
}