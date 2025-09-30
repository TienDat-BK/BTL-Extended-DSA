#pragma once
#include "STL.h"
#include "VectorRecord.h"

/*
    Class sẽ lưu danh sách của các VectorRecord
    vector<VectorRecord> listVec;
    int dim; // dimension của vector
*/

class VectorRecordList
{
private:
    vector<VectorRecord> listVec;
    int dim;

public:
    /// Constructor Nhận List VectorRecord và dimension của vector
    VectorRecordList(const vector<VectorRecord> &listVec, int dim) : listVec(listVec), dim(dim) {}

    /// default constructor
    VectorRecordList() : dim(0) {}

    /// Lấy kích thước của list
    int size() const
    {
        return listVec.size();
    }
    /// Lấy dimension của vector
    int getDim() const
    {
        return dim;
    }

    /// Lấy vector tại index
    VectorRecord &get(int index)
    {
        return listVec[index];
    }

    VectorRecord &operator[](int index)
    {
        return listVec[index];
    }
};
