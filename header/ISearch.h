#pragma once
#include "STL.h"

using namespace std;

class Search
{
private:
    double hammingDistance(vector<double>, vector<double>);  // SimHash
    double jarcardSimilarity(vector<double>, vector<double>); // MinHash

public:
    vector<vector<double>> classify(vector<vector<double>>);
};