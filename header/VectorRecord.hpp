#pragma once
#include "STL.hpp"

struct VectorRecord
{
    int id;
    vector<double> vec;
    VectorRecord(int id_, vector<double> vec_) : id(id_), vec(vec_) {}
    bool operator==(const VectorRecord &other)
    {
        return this->vec == other.vec && this->id == other.id;
    }

    VectorRecord() : id(0), vec(vector<double>()) {}

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

    string to_string() const
    {
        stringstream ss;
        ss << "ID: " << id << ", Vector: [";
        for (size_t i = 0; i < vec.size(); ++i)
        {
            ss << vec[i];
            if (i < vec.size() - 1)
                ss << ", ";
        }
        ss << "]";
        return ss.str();
    }
};