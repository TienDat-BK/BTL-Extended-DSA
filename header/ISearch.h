#pragma once
#include "STL.h"
#include "DSU.h"
#include "VectorRecord.h"
using namespace std;

class Search
{

public:
    double (*disFunc)(const VectorRecord &, const VectorRecord &) = &Search::hammingDistance; // con trỏ hàm tính khoảng cách ( jarcard, hamming,... sẽ đc dùng ở các class con)
    int num_bands = 4;                                                                        // số bands
    double threshold = 0.4;                                                                   // ngưỡng để quyết định 2 vecRecord có cùng nhóm hay không
private:
    vector<double> getband(VectorRecord, int, int); // lấy band thứ i trong b bands

    struct bandHash
    {
        size_t operator()(const vector<double> &band) const;
    };

    struct pairHash
    {
        size_t operator()(const pair<int, int> &p) const;
    };

public:
    /*
    setOfVecRecord (input)
    └─> Hash band → setOfBucket
          └─> DSU → groups (index)
                 └─> move setOfVecRecord[idx] vào groupVecRecords
                        └─> move groupVecRecords vào result
    */
    vector<vector<VectorRecord>> classifyByBand(vector<VectorRecord>);

public:
    static double jarcardSimilarity(const VectorRecord &, const VectorRecord &); // MinHash
    static double hammingDistance(const VectorRecord &, const VectorRecord &);   // SimHash
    vector<vector<VectorRecord>> classify(vector<vector<double>>);
};
