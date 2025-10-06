#include "../header/MinHash.hpp"

//sig length = 200

size_t mini_hash(const string& in)
{
    std::hash<string> ha;
    return ha(in) % 1000000;

}

VectorRecord MinHash::hash_1(const VectorRecord& vec)
{

    if((vec.vec.size() != this->inputDim))
    throw invalid_argument("input vector is invalid!");

    std::hash<string> ha;
    vector<size_t> sig(this->outputDim, SIZE_MAX);
    vector<double> p = vec.vec;
 
    for(int seed = 0; seed < this->outputDim; ++seed)
    {
        for(int i = 0; i < p.size(); i++)
        {        
            if(fabs(p[i] - 1) < 1e-9)
            {
                size_t value = mini_hash(to_string(i) + "@" + to_string(seed));    // hash index;
                sig[seed] = min(value, sig[seed]);
            }
        }
    }
    vector<double> rt(sig.begin(), sig.end());
    return VectorRecord(vec.id, rt);
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
