#pragma once
#include "STL.h"
#include "VectorRecord.h"
using namespace std;

class Search
{
private:
    double hammingDistance(VectorRecord, VectorRecord);  // SimHash
    double jarcardSimilarity(VectorRecord, VectorRecord); // MinHash

public:
    vector<vector<VectorRecord>> classify(vector<vector<double>>);
};