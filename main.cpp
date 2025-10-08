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
    vector<VectorRecord> input = {
        {0, {1, 1, 0, 0, 0, 0}},
        {1, {1, 0.9, 0, 0, 0, 0}},
        {2, {0, 0, 1, 1, 0, 0}},
        {3, {0, 0, 1, 0.9, 0, 0}},
        {4, {1, 0, 0.5, 0.5, 0, 0}},
        {5, {0, 0, 0, 0, 1, 1}}
    };

    BandBloomFilter bf(6, 6, 3, 10, 3);   // bắt buộc thêm
    vector<VectorRecord> bitArray = bf.hash(input);

    Search s;
    s.num_bands = 3;
    s.threshold = 0.85;
    s.disFunc = Search::cosineDistance;

    auto clusters = s.bloomClassify(bitArray, input);

    cout << "\nResult clusters:\n";
    for (int i = 0; i < clusters.size(); i++) {
        cout << "Cluster " << i+1 << ": ";
        for (auto &r : clusters[i])
            cout << r.id << " ";
        cout << endl;
    }
    cout << bf.getM();
}
// g++ -std=c++17 -O2 -Iheader -o my_program main.cpp source/MurmurHash3.cpp source/SimHash.cpp