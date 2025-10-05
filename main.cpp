#include "header/SimHash.h"
#include "header/MurmurHash3.h"
#include <cmath>
#include "header/ISearch.h"
#include "header/MinHash.h"
int main()
{
    // Example usage of SimHash
    SimHash simHash(3, 128);

    

    // vector<double> vec1 = {1.0, 2.0, 3.0};
    // vector<double> vec2 = {1.0, 10.0, 10.345};


    vector<double> vec1 = {1,1,0,0,0,1,1,1,0,1};
    vector<double> vec2 = {1,1,0,1,0,1,0,1,0,1};
    // Create a vector recordcls

    
    VectorRecord record1(1, vec1);
    VectorRecord record2(2, vec2);


    MinHash min(10, 128);
    // Hash a single vector record
    VectorRecord hashedRecord = min.hash_1(record1);
    VectorRecord hashedRecord2 = min.hash_1(record2);

    // Print the hashed vector record
    cout << "Hashed Record 1: " << hashedRecord.to_string() << endl;
    cout << "Hashed Record 2: " << hashedRecord2.to_string() << endl;

    // cout << (hashedRecord2 == hashedRecord) << endl;
    
    //test hammingDistance
    Search se;

    cout<<endl<<"Distance :"<<se.jarcardSimilarity(hashedRecord2, hashedRecord)<<endl;
    
    return 0;
}

// g++ -std=c++17 -O2 -Iheader -o my_program main.cpp source/MurmurHash3.cpp source/SimHash.cpp