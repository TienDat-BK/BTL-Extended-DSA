#pragma once
#include "iHash.h"
#include "VectorRecordList.h"

class SimHash : public IHash
{
private:
public:
    /// Hàm băm ( ko thay đổi )
    VectorRecordList hash(const VectorRecordList &input);
};