#pragma once
#include "iHash.h"



class SimHash : public IHash
{
private:
public:
    /// Hàm băm ( ko thay đổi )
    vector<vector<double>> hash(const vector<vector<double>> &input);
};