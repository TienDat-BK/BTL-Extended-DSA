#include "../header/MinHash.h"

//sig length = 200
VectorRecord MinHash::hash_1(const VectorRecord& vec)
{
    std::hash<string> ha;
    vector<double> sig(200, SIZE_MAX);
    vector<double> p = vec.vec;
    for(int seed = 0; seed < 200; seed++)
    {
        for(int i = 0; i < p.size(); i++)
        {
            if(fabs(p[i]-1) < 1e-9)
            {
                int value = ha(to_string(i) + "@" + to_string(seed));
                if(value < sig[i]) sig[i] = value;
            }
        }
    }
    



    VectorRecord rt(vec.id, sig);
    return rt;
}



vector<VectorRecord> MinHash::hash(const vector<VectorRecord> &input)
{
    int nums = input.size();
    vector<VectorRecord> rt(nums);
    for(int i = 0; i< nums; ++i)
    {
        rt[i] = this->hash_1(input[i]);
    }
    return rt;
}
