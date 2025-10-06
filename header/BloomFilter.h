#pragma once
#include "iHash.h"
#include "MurmurHash3.h"
#include "VectorRecord.h"

class BloomFilter : public IHash {
private:
    vector<bool> bitArray;
    size_t m; // size of bitarray
    int k; // number of hash function
    vector<VectorRecord> candidates; // contain false positives 

public:
    BloomFilter(int i, int o, int m, int k);
    vector<size_t> getHashIndices(const VectorRecord &rec) const;
    bool possiblyContains(const VectorRecord &vec, vector<size_t>& indices) const; //check possible of duplicate
    vector<VectorRecord> hash(const vector<VectorRecord>&); // hash a set of vector
    const vector<VectorRecord>& getCandidates() const {return candidates;}
    void clearCandidates() {candidates.clear();}
};