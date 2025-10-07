#pragma once
#include "iHash.h"
#include "MurmurHash3.h"
#include "VectorRecord.h"

class BandBloomFilter : public IHash {
private:
    int bands;  // số band
    int m;      // số hash position mỗi band
    int k;      // số hash function mỗi band
    vector<vector<int>> bitArray; // bitArray[globalIndex] = list vectorID
    int totalSize;

public:
    BandBloomFilter(int i, int o, int bands, int k, int m)
        : IHash(i,o), bands(bands), k(k), m(m)
    {
        totalSize = bands * m;
        bitArray.resize(totalSize);
    }

    // Hash 1 band (subvec đã chia) -> k vị trí
    vector<size_t> getHashIndices(const vector<double>& subvec, int band) const;

    // Thêm vector vào filter
    void addVector(int vectorID, const vector<double>& vec);

    const vector<vector<int>>& getBitArray() const { return bitArray; }

    void print() const;
    vector<VectorRecord> hash(const vector<VectorRecord>& input) override;
    int getBands() const { return bands; }
    int getM() const { return m; }
};