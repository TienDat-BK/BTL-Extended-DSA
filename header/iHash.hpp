#pragma once
#include "STL.hpp"
#include "VectorRecord.hpp"

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