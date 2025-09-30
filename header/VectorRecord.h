#pragma once
#include "STL.h"

/*
    Class sẽ chứa vector và id của vector
    vector<float> data;
    int id;
*/

class VectorRecord
{
public:
    vector<float> data; /// Data của vector
    int id;             /// Id của vector

public:
    VectorRecord(vector<float> data, int id) : data(data), id(id) {}

    bool operator==(const VectorRecord &other)
    {
        return this->data == other.data && this->id == other.id;
    }

    bool operator!=(const VectorRecord &other)
    {
        return !(this->operator==(other));
    }

    /// deep copy
    VectorRecord &operator=(const VectorRecord &other)
    {
        this->data = other.data;
        this->id = other.id;
        return *this;
    }
};