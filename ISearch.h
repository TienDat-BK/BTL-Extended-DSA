#pragma once 
#include<vector>
using namespace std;


class Search
{
    double cosine(vector<float>, vector<float>);
    double jarcard(vector<float>, vector<float>); // tra ve do giong nhau cua 2 doi tuong bam

    vector<vector<int>> classify(vector<pair<int, vector<float>>>);
};