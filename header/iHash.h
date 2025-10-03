#pragma once
#include "STL.h"
#include "VectorRecord.h"

using namespace std;

class IHash
{
protected:
    int inputDim;
    int outputDim;

public:
    IHash(int i, int o): inputDim(i), outputDim(o){}
    virtual vector<VectorRecord> hash(const vector<VectorRecord> &input) = 0;
};