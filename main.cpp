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
#include "../header/BandBloomFilter.h"
using namespace std;

int main() {
    // Cấu hình bộ lọc
    BandBloomFilter bf(6, 6, 2, 2, 10);

    // Tạo vài vector mẫu
    vector<VectorRecord> input = {
        {0, {0.1, 0.2, 0.3, 0.4, 0.5, 0.6}},
        {1, {0.9, 0.8, 0.7, 0.6, 0.5, 0.4}},
        {2, {0.1, 0.2, 0.35, 0.4, 0.5, 0.6}}
    };

    // Gọi hàm hash
    vector<VectorRecord> bitArray = bf.hash(input);

    // In ra kết quả (band nào chứa vector nào)
    int bandSize = bf.getM();
    for (int b = 0; b < bf.getBands(); b++) {
        cout << "=== Band " << b << " ===" << endl;
        for (int h = 0; h < bandSize; h++) {
            int idx = b * bf.getM() + h;
            cout << "Slot " << h << ": ";
            for (double v : bitArray[idx].vec) {
                cout << (int)v << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}

// g++ -std=c++17 -O2 -Iheader -o my_program main.cpp source/MurmurHash3.cpp source/SimHash.cpp