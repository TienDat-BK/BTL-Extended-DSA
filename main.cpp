#include "header/SimHash.hpp"
#include "header/MurmurHash3.hpp"
#include <cmath>
<<<<<<< HEAD
#include "header/ISearch.h"
#include "header/MinHash.h"
#include "header/BloomFilter.h"
#include <iostream>
#include <vector>
#include <random>
=======
#include "header/ISearch.hpp"
#include "header/MinHash.hpp"
#include "header/DSU.hpp"
>>>>>>> origin/binding
#include <chrono>
#include "../header/BloomFilter.h"
using namespace std;


int main() {
    // Tham số Bloom filter
    size_t expectedItems = 100000;
    double falsePositiveRate = 0.001;

    BloomFilter bf(0, 0, expectedItems, falsePositiveRate);

    // Tạo dữ liệu ngẫu nhiên
    vector<VectorRecord> input;
    mt19937 rng(12345);
    uniform_real_distribution<float> dist(-1.0, 1.0);

    // Sinh 100k vector ngẫu nhiên (mỗi vector 8 chiều)
    for (int i = 0; i < 10000; i++) {
        VectorRecord rec;
        rec.id = i;
        rec.vec.resize(384);
        for (double &x : rec.vec) x = dist(rng);
        input.push_back(rec);
    }

    // Thêm bản sao trùng (15% bị trùng)
    for (int i = 0; i < 1500; i++) {
        input.push_back(input[i]); // copy 1500 bản đầu
    }

    cout << "Tổng số vector đầu vào: " << input.size() << endl;

    auto start = chrono::high_resolution_clock::now();
    vector<VectorRecord> unique = bf.hash(input);
    auto end = chrono::high_resolution_clock::now();

    cout << "Số vector unique sau lọc Bloom: " << unique.size() << endl;
    cout << "Thời gian xử lý: " 
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms" << endl;

<<<<<<< HEAD
=======
int main()
{

    // // Example usage of SimHash
    // SimHash simHash(3, 128);

    

    // // vector<double> vec1 = {1.0, 2.0, 3.0};
    // // vector<double> vec2 = {1.0, 10.0, 10.345};


    // vector<double> vec1 = {1,1,0,0,0,1,1,1,0,1};
    // vector<double> vec2 = {1,1,0,1,0,1,0,1,0,1};
    // // Create a vector recordcls

    
    // VectorRecord record1(1, vec1);
    // VectorRecord record2(2, vec2);


    // MinHash min(10, 128);
    // // Hash a single vector record
    // VectorRecord hashedRecord = min.hash_1(record1);
    // VectorRecord hashedRecord2 = min.hash_1(record2);

    // // Print the hashed vector record
    // cout << "Hashed Record 1: " << hashedRecord.to_string() << endl;
    // cout << "Hashed Record 2: " << hashedRecord2.to_string() << endl;

    // // cout << (hashedRecord2 == hashedRecord) << endl;
    
    // //test hammingDistance
    // Search se;

    // cout<<endl<<"Distance :"<<se.jarcardSimilarity(hashedRecord2, hashedRecord)<<endl;
    

    stress_search_test(5000, 128, 16, 0.5);
>>>>>>> origin/binding
    return 0;
}
// g++ -std=c++17 -O2 -Iheader -o my_program main.cpp source/MurmurHash3.cpp source/SimHash.cpp