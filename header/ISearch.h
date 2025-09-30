#pragma once
#include "STL.h"
#include "VectorRecordList.h"
using namespace std;

class Search
{
private:
    double cosine(VectorRecord, VectorRecord);  // tra ve do giong nhau cua 2 doi tuong bam
    double jarcard(VectorRecord, VectorRecord); // tra ve do giong nhau cua 2 doi tuong bam

public:
    vector<VectorRecordList> classify(VectorRecordList);
};