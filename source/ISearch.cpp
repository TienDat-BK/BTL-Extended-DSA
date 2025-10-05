#include "../header/ISearch.h"


double Search::hammingDistance(VectorRecord vec1, VectorRecord vec2)
{

    vector<double> a = vec1.vec;
    vector<double> b = vec2.vec;
    double dis = 0;
    for(int i = 0; i < a.size(); ++i)
    {
        if(a[i] != b[i]) dis = dis + 1;
    }
    return dis;
}


double Search::jarcardSimilarity(VectorRecord vec1, VectorRecord vec2)
{

    set<double> s1(vec1.vec.begin(), vec1.vec.end());
    set<double> s2(vec2.vec.begin(), vec2.vec.end());

    vector<double> inter; 
    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(inter));

    vector<double> uni;
    set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(uni));

    return (double)inter.size() / uni.size();

}

