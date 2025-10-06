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

double Search::cosineSimilarity(VectorRecord vec1, VectorRecord vec2)
{
    vector<double> a = vec1.vec;
    vector<double> b = vec2.vec;
    double dot_product = 0.0;
    double norm_a = 0.0;
    double norm_b = 0.0;
    for (size_t i = 0; i < a.size(); ++i) {
        dot_product += a[i] * b[i];
        norm_a += a[i] * a[i];
        norm_b += b[i] * b[i];
    }
    if (norm_a == 0 || norm_b == 0) return 0.0;
    return dot_product / (sqrt(norm_a) * sqrt(norm_b));
}  


