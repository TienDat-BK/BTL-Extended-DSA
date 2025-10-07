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
#include "../source/Search.cpp"
using namespace std;

int main() {
    // ===== Tham số Band Bloom Filter =====
    int bands = 3;
    int k = 2;
    int m = 10; // số ô hash mỗi band

    BandBloomFilter bloom(12, 12, bands, k, m);

    // ===== Dataset demo =====
    vector<VectorRecord> dataset = {
        {0, {0.1,0.2,0.3,0.4, 0.5,0.6,0.7,0.8, 0.9,1.0,1.1,1.2}},
        {1, {0.1,0.2,0.31,0.41, 0.5,0.6,0.7,0.81, 0.9,1.0,1.1,1.21}},
        {2, {0.9,0.8,0.7,0.6, 0.5,0.4,0.3,0.2, 0.1,0.0,-0.1,-0.2}},
        {3, {0.11,0.19,0.29,0.41, 0.5,0.61,0.7,0.79, 0.91,1.02,1.1,1.22}}
    };

    // ===== Add vectors vào BandBloomFilter =====
    for (int i = 0; i < dataset.size(); i++) {
        bloom.addVector(dataset[i].id, dataset[i].vec);
    }

    // ===== In bitArray =====
    cout << "\n==== BitArray ====\n";
    bloom.print();

    // ===== Gom cụm văn bản trùng =====
    auto clusters = groupSimilar(bloom, dataset);

    // ===== In kết quả gom cụm =====
    cout << "\n==== Kết quả groupSimilar() ====\n";
    printClusters(clusters);

    return 0;
}



// g++ -std=c++17 -O2 -Iheader -o my_program main.cpp source/MurmurHash3.cpp source/SimHash.cpp