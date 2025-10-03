#pragma once
#include "STL.h"
#include "VectorRecord.h"
using namespace std;

class Search
{
private:
    double jarcardSimilarity(VectorRecord, VectorRecord); // MinHash
public:
    double hammingDistance(VectorRecord, VectorRecord);  // SimHash

    vector<vector<VectorRecord>> classify(vector<vector<double>>);
};