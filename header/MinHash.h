#pragma once
#include "iHash.h"


class MinHash : public IHash
{
private:
public:

    //t làm cai nay
    /// Hàm băm ( ko thay đổi )
    vector<vector<double>> hash(const vector<vector<double>> &input);
};