#include "../header/ISearch.h"


double Search::hammingDistance(VectorRecord vec1, VectorRecord vec2)
{

    vector<double> a = vec1.vec;
    vector<double> b = vec2.vec;
    double dis = 0;
    for(int i = 0; i < 64; ++i)
    {
        if(a[i] != b[i]) dis = dis + 1;
    }
    return dis;
}


