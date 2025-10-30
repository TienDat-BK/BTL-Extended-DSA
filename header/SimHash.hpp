#pragma once
#include "iHash.hpp"
#include "MurmurHash3.hpp"
#include "VectorRecord.hpp"

class SimHash : public IHash
{
private:
public:
    /// Hàm băm ( ko thay đổi )
    SimHash() : IHash() {}
    SimHash(int i, int o) : IHash(i, o) {}
    VectorRecord hash_1(const VectorRecord &);               // hash a vector
    vector<VectorRecord> hash(const vector<VectorRecord> &); // hash a set of vector
};