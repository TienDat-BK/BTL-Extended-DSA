#pragma once
#include "STL.h"
#include "VectorRecordList.h"

using namespace std;

class IHash
{
private:
    int inputDim;
    int outputDim;

public:
    virtual VectorRecordList hash(const VectorRecordList &input) = 0;
};