#pragma once
#include "iHash.h"

class SimHash : public IHash
{
private:
public:
    vector<pair<int, vector<float>>> hash(vector<pair<int, vector<int>>>);
};