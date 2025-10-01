#pragma once
#include "STL.h"
#include "VectorRecord.h"

using namespace std;

class IHash
{
private:
    int inputDim;
    int outputDim;

public:
    virtual vector<VectorRecord> hash(const vector<VectorRecord> &input) = 0;
};