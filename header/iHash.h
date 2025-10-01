#pragma once
#include "STL.h"


using namespace std;

class IHash
{
private:
    int inputDim;
    int outputDim;

public:
    virtual vector<vector<double>> hash(const vector<vector<double>> &input) = 0;
};