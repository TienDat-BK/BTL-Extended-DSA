#pragma once
#include "iHash.h"
#include "VectorRecord.h"

class MinHash : public IHash
{
private:
public:

    /// Hàm băm ( ko thay đổi )
    vector<VectorRecord> hash(const vector<VectorRecord> &input);
};