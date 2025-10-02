#pragma once
#include "iHash.h"
#include "MurmurHash3.h"
#include "VectorRecord.h"

class BloomFilter : public IHash {
private:
    vector<bool> bitArray;
    size_t m; // size of bitarray
    int k; // number of hash function

public:
    BloomFilter(int m, int k);
    size_t BloomFilter::hashWithSeed(const VectorRecord &rec, int seed) const;
    void add(const VectorRecord &vec); // hash vector and add into bitarray
    bool BloomFilter::possiblyContains(const VectorRecord &vec) const; //check possible of duplicate
    vector<VectorRecord> hash(const vector<VectorRecord>&); // hash a set of vector
};