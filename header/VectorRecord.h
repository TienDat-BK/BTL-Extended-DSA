#pragma once
#include "STL.h"

struct VectorRecord
{
    int id;
    vector<double> vec;
    VectorRecord(int id_, vector<double> vec_):id(id_), vec(vec_) {}
};