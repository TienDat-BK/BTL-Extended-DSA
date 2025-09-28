#pragma once

#include <vector>

using namespace std;

class IHash
{
private:
    int inputDim;
    int outputDim;

public:
    virtual vector<pair<int, vector<float>>> hash(vector<pair<int, vector<int>>>) = 0;
};