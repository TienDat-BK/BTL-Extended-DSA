#pragma once
#include "STL.h"
#include "VectorRecord.h"
using namespace std;

class Search
{
private:


public:
    double hammingDistance(VectorRecord, VectorRecord);  // SimHash
    double jarcardSimilarity(VectorRecord, VectorRecord); // MinHash
    vector<vector<VectorRecord>> classify(vector<vector<double>>);
};