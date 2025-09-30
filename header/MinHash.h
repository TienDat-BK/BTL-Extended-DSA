#pragma once
#include "iHash.h"
#include "VectorRecordList.h"

class MinHash : public IHash
{
private:
public:
    /// Hàm băm ( ko thay đổi )
    VectorRecordList hash(const VectorRecordList &input);
};