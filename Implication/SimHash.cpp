#include "..\header\SimHash.h"

// fingerprint 64

vector<double> SimHash::hash_1(const vector<double> &vt)
{
    vector<double> a(64, 0.0);

    for(int i = 0; i < vt.size(); ++i)
    {
        uint64_t out[2];
        MurmurHash3_x64_128(&i, sizeof(i), 10, &out);
        for(int j = 0; j < 64; j++)
        {
           if (out[0] & (1ULL << j))
                a[j] += vt[i];
            else
                a[j] -= vt[i];
        }
    }
    vector<double> rt(64);
    for(int i = 0; i<64; ++i) rt[i] = (a[i]>=0) ? 1 : 0;

    return rt;
}


vector<vector<double>> SimHash::hash(const vector<vector<double>> &set)
{
    int nums = set.size();
    vector<vector<double>> rt(nums);
    for(int i = 0; i< nums; ++i)
    {
        rt[i] = this->hash_1(set[i]);
    }
    return rt;
}