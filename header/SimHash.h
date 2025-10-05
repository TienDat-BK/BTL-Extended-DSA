#pragma once
#include "iHash.h"
#include "MurmurHash3.h"
#include "VectorRecord.h"



class SimHash : public IHash
{
private:
public:
    /// Hàm băm ( ko thay đổi )
    SimHash(int i, int o): IHash(i,o){}
    VectorRecord hash_1(const VectorRecord&); //hash a vector
    vector<VectorRecord> hash(const vector<VectorRecord>&); // hash a set of vector


};