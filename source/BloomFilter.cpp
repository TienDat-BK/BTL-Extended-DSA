#include "../header/BloomFilter.h"

BloomFilter::BloomFilter(int m, int k) : m(m), k(k), bitArray(m, false) {}

size_t BloomFilter::hashWithSeed(const VectorRecord &rec, int seed) const {
    uint64_t out[2];
    MurmurHash3_x64_128(
        rec.vec.data(),                      
        (int)(rec.vec.size() * sizeof(double)), 
        seed,
        &out
    );
    return out[0] % m;
}

void BloomFilter::add(const VectorRecord &vec) {
    for (int i = 0; i < k; i++) {
        size_t idx = hashWithSeed(vec, i);
        bitArray[idx] = true;
    }
}

bool BloomFilter::possiblyContains(const VectorRecord &vec) const {
    for (int i = 0; i < k; i++) {
        size_t idx = hashWithSeed(vec, i);
        if (!bitArray[idx]) return false;
    }
    return true;
}