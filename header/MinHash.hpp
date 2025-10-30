#pragma once
#include "iHash.hpp"
#include "VectorRecord.hpp"

class MinHash : public IHash
{
private:
public:

    /// Hàm băm ( ko thay đổi )
    MinHash(int i, int o): IHash(i,o){}
    VectorRecord hash_1(const VectorRecord&);
    vector<VectorRecord> hash(const vector<VectorRecord> &input);
};