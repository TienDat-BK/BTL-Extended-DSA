#include "header/SimHash.h"
#include "header/MurmurHash3.h"
#include <cmath>
#include "header/ISearch.h"
#include "header/MinHash.h"
#include "header/BloomFilter.h"
#include <iostream>
#include <vector>
#include <random>
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

    return 0;
}
// g++ -std=c++17 -O2 -Iheader -o my_program main.cpp source/MurmurHash3.cpp source/SimHash.cpp