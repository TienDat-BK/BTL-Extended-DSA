#pragma once
#include "iHash.h"
#include "MurmurHash3.h"


class SimHash : public IHash
{
private:
public:
    /// Hàm băm ( ko thay đổi )

    vector<double> hash_1(const vector<double>&); //hash a vector
    vector<vector<double>> hash(const vector<vector<double>>&); // hash a set of vector
};