#pragma once
#include "iHash.h"
#include "VectorRecord.h"

class MinHash : public IHash
{
private:
public:

    /// Hàm băm ( ko thay đổi )
    VectorRecord hash_1(const VectorRecord&);
    vector<VectorRecord> hash(const vector<VectorRecord> &input);
};