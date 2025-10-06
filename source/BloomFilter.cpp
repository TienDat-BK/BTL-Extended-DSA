#include "../header/BloomFilter.h"

BloomFilter::BloomFilter(int i, int o, int m, int k) : IHash(i, o), m(m), k(k), bitArray(m, false) {};

vector<size_t> BloomFilter::getHashIndices(const VectorRecord &rec) const {
    uint64_t out[2];
    MurmurHash3_x64_128(
        rec.vec.data(),
        (int)(rec.vec.size() * sizeof(double)),
        0,
        &out
    );

    uint64_t h1 = out[0];
    uint64_t h2 = out[1];
    if (h2 % m == 0) h2++; // tránh trùng vòng lặp

    vector<size_t> indices(k);
    for (int i = 0; i < k; i++) {
        indices[i] = (h1 + i * h2) % m;
    }
    return indices;
}

bool BloomFilter::possiblyContains(const VectorRecord &vec, vector<size_t>& indices) const {
    for (size_t idx : indices) {
        if (!bitArray[idx]) return false;
    }
    return true;
}

vector<VectorRecord> BloomFilter::hash(const vector<VectorRecord>& input) {
    vector<VectorRecord> unique; 
    unique.reserve(input.size());
    candidates.clear();

    for (const auto& vec : input) {
        vector<size_t> indices = getHashIndices(vec);
        if (!possiblyContains(vec, indices)) {
            for (size_t idx : indices) {
                bitArray[idx] = true;
            }
            unique.push_back(vec); // Lưu vào danh sách unique
        }
        else {
            candidates.push_back(vec); // Lưu vào danh sách false positives
        }
    }
    return unique;
}
