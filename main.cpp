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

// Hàm tạo 1 vector ngẫu nhiên 128 chiều
VectorRecord randomVector(int dim, std::mt19937 &gen, std::uniform_real_distribution<double> &dist) {
    VectorRecord rec;
    rec.vec.resize(dim);
    for (int i = 0; i < dim; i++)
        rec.vec[i] = dist(gen);
    return rec;
}

int main() {
    cout << "===== BLOOM FILTER TEST =====" << endl;

    int numVectors = 5000;
    int dim = 128;
    int m = 20000; // kích thước bit array
    int k = 6;     // số hàm hash

    BloomFilter bf(dim, 0, m, k);
    Search se;

    // random generator
    std::mt19937 gen(42);
    std::uniform_real_distribution<double> dist(0.0, 1.0);

    // Round 1: tạo 5000 vector random
    vector<VectorRecord> input;
    input.reserve(numVectors);
    for (int i = 0; i < numVectors; i++)
        input.push_back(randomVector(dim, gen, dist));

    // ----------- Round 1 -----------
    auto start = chrono::high_resolution_clock::now();
    auto unique1 = bf.hash(input);
    auto end = chrono::high_resolution_clock::now();
    auto t1 = chrono::duration_cast<chrono::microseconds>(end - start).count();

    cout << "Round 1 - Added unique: " << unique1.size() << endl;
    cout << "Round 1 - Candidates: " << bf.getCandidates().size() << endl;
    cout << "Hash time for Round 1: " << t1 << " microseconds" << endl;

    // Kiểm tra xem 275 candidates là false positive thật hay trùng
    int realDuplicates1 = 0, falsePositives1 = 0;
    for (const auto &cand : bf.getCandidates()) {
        bool isDuplicate = false;
        for (const auto &u : unique1) {
            if (fabs(se.cosineSimilarity(cand, u) - 1.0) < 1e-9) {
                isDuplicate = true;
                break;
            }
        }
        if (isDuplicate) realDuplicates1++;
        else falsePositives1++;
    }
    cout << "Round 1 - Real duplicates by cosine: " << realDuplicates1 << endl;
    cout << "Round 1 - False positives detected: " << falsePositives1 << endl;

    // ✅ Thêm false positive vào unique và Bloom filter
    int falsePositivesFixed = 0;
    for (const auto &cand : bf.getCandidates()) {
        bool isDuplicate = false;
        for (const auto &u : unique1) {
            if (fabs(se.cosineSimilarity(cand, u) - 1.0) < 1e-9) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            falsePositivesFixed++;
            unique1.push_back(cand);
        }
    }
    cout << "Round 1 - False positives corrected and added: " 
         << falsePositivesFixed << endl;
    cout << "Total unique after correction: " << unique1.size() << endl;

    // ----------- Round 2 -----------
    start = chrono::high_resolution_clock::now();
    auto unique2 = bf.hash(input);
    end = chrono::high_resolution_clock::now();
    auto t2 = chrono::duration_cast<chrono::microseconds>(end - start).count();

    cout << "Round 2 - Added unique: " << unique2.size() << endl;
    cout << "Round 2 - Candidates: " << bf.getCandidates().size() << endl;

    // Kiểm tra chính xác số trùng thật sự bằng cosine
    int exactDuplicates2 = 0;
    for (const auto &cand : bf.getCandidates()) {
        for (const auto &u : unique1) {
            if (fabs(se.cosineSimilarity(cand, u) - 1.0) < 1e-9) {
                exactDuplicates2++;
                break;
            }
        }
    }
    cout << "Round 2 - Exact duplicates by cosine: " << exactDuplicates2 << endl;
    cout << "Hash time for Round 2: " << t2 << " microseconds" << endl;

    return 0;
}


// g++ -std=c++17 -O2 -Iheader -o my_program main.cpp source/MurmurHash3.cpp source/SimHash.cpp