#pragma once
#include "STL.h"

struct VectorRecord
{
    int id;
    vector<double> vec;
    VectorRecord(int id_, vector<double> vec_):id(id_), vec(vec_) {}
    bool operator==(const VectorRecord &other)
    {
        return this->vec == other.vec && this->id == other.id;
    }

    bool operator!=(const VectorRecord &other)
    {
        return !(this->operator==(other));
    }

    /// deep copy
    VectorRecord &operator=(const VectorRecord &other)
    {
        this->vec = other.vec;
        this->id = other.id;
        return *this;
    }
};