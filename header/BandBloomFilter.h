#pragma once
#include "iHash.h"
#include "MurmurHash3.h"
#include "VectorRecord.h"

class BandBloomFilter : public IHash {
private:
    int num_bands;  // số band
    int m;      // số hash position mỗi band
    int k;      // số hash function mỗi band

public:
    BandBloomFilter(int i, int o, int num_bands, int k, int m)
        : IHash(i,o), num_bands(num_bands), k(k), m(m)
    {}

    // Hash 1 band (subvec đã chia) -> k vị trí
    vector<size_t> getHashIndices(const vector<double>& subvec, int band) const;

    // Thêm vector vào filter
    void addVector(int vectorID, const vector<double>& vec, vector<VectorRecord>& bitArray);
    void print() const;
    vector<VectorRecord> hash(const vector<VectorRecord>& input) override;
    int getBands() const { return num_bands; }
    int getM() const { return m; }
};