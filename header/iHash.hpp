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
    IHash(int i, int o) : inputDim(i), outputDim(o) {}
    IHash() {}
    void setInOutput(int in, int out)
    {
        this->inputDim = in;
        this->outputDim = out;
    }

    virtual vector<VectorRecord> hash(const vector<VectorRecord> &input) = 0;
};