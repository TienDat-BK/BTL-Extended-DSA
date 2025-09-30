#pragma once
#include "iHash.h"
#include "VectorRecordList.h"

class BloomFilter : public IHash
{
private:
public:
    VectorRecordList hash(const VectorRecordList &input);
};