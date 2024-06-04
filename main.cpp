#include <iostream>
#include "separate_chaining.h"
#include "open_addressing.h"
#include "cuckoo_hashing.h"
#include <chrono>

using namespace std;

int main() {
    int size = 250000;
    scTable scTable(3);   // Hash table for separate chaining
    oaTable oaTable(50);   // Hash table for open addressing
    CuckooHash ckHash(size/2);  // Hash table for cuckoo hashing

    for(int i = 1; i < size; i=i+3) {
        ckHash.insert(i);
    }

//    int x = 1;
//    for(int i = 1; i < 50; i++) {
//        oaTable.insert(x);
//        x=x+3;
//    }
//    oaTable.display();
//    oaTable.deleteKey(49);
//    oaTable.display();
//
    auto start = chrono::high_resolution_clock::now();
    ckHash.remove(250000);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds >(end - start);
    cout  << duration.count() <<  endl;

//    oaTable.display();
//
//    auto start1 = chrono::high_resolution_clock::now();
//    oaTable.insert(1);
//    auto end1 = chrono::high_resolution_clock::now();
//    auto duration1 = chrono::duration_cast<chrono::nanoseconds >(end1 - start1);
//    cout << duration1.count() << endl;
//
//    auto start2 = chrono::high_resolution_clock::now();
//    oaTable.deleteKey(7);
//    auto end2 = chrono::high_resolution_clock::now();
//    auto duration2 = chrono::duration_cast<chrono::nanoseconds >(end2 - start2);
//    cout  << duration2.count() << endl;
//
//    auto start3 = chrono::high_resolution_clock::now();
//    oaTable.deleteKey(10);
//    auto end3 = chrono::high_resolution_clock::now();
//    auto duration3 = chrono::duration_cast<chrono::nanoseconds >(end3 - start3);
//    cout  << duration3.count() <<  endl;
//    auto start4 = chrono::high_resolution_clock::now();
//    oaTable.deleteKey(13);
//    auto end4 = chrono::high_resolution_clock::now();
//    auto duration4 = chrono::duration_cast<chrono::nanoseconds >(end4 - start4);
//    cout  << duration4.count() << endl;


    return 0;
}