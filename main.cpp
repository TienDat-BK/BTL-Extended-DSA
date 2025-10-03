#include "header/SimHash.h"
#include "header/MurmurHash3.h"
#include <cmath>
#include "header/ISearch.h"
#include "header/MinHash.h"
int main()
{
    // Example usage of SimHash
    SimHash simHash;

    

    vector<double> vec1 = {1.0, 2.0, 3.0};
    vector<double> vec2 = {1.0, 100.0, 10.345};

    // Create a vector recordcls

    
    VectorRecord record1(1, vec1);
    VectorRecord record2(2, vec2);

    //testMInHash
    MinHash minHash; 

    vector<double> min1 = {0, 1 , 1, 0};
    vector<double> min2 = {1, 1, 1, 1};

    VectorRecord r1(1, min1);
    VectorRecord r2(2, min2);


    // Hash a single vector record
    VectorRecord hashedRecord = minHash.hash_1(r1);
    VectorRecord hashedRecord2 = minHash.hash_1(r2);

    // Print the hashed vector record
    cout << "Hashed Record 1: " << hashedRecord.to_string() << endl;
    cout << "Hashed Record 2: " << hashedRecord2.to_string() << endl;

    cout << (hashedRecord2 == hashedRecord) << endl;
    Search sear;

    
    return 0;
}

// g++ -std=c++17 -O2 -Iheader -o my_program main.cpp source/MurmurHash3.cpp source/SimHash.cpp