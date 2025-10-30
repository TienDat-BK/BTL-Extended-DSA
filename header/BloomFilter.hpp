#pragma once
#include "iHash.hpp"
#include "MurmurHash3.hpp"
#include "VectorRecord.hpp"

class BloomFilter : public IHash {
private:
    vector<bool> bitArray;
    size_t m; // size of bitarray
    int k; // number of hash function

public:
    BloomFilter(int i, int o, size_t expectedItems, double falsePositiveRate);
    vector<size_t> getHashIndices(const VectorRecord &rec, uint64_t &fingerprint) const;
    bool possiblyContains(vector<size_t>& indices) const; //check possible of duplicate
    vector<VectorRecord> hash(const vector<VectorRecord>&); // hash a set of vector
};