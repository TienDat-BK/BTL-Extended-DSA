#pragma once
#include "STL.hpp"
#include "VectorRecord.hpp"
using namespace std;

/*
    Disjoint Set Union (DSU)
    Cấu trúc dữ liệu hỗ trợ hai thao tác:
    1. Find: Tìm đại diện của một tập hợp.
    2. Union: Hợp nhất hai tập hợp.
    3. getGroups: Lấy tất cả các nhóm (tập hợp con) hiện có.
*/

class DSU
{
private:
    int n;
    int *parent;
    int *sizeOfParent;

public:
    DSU(int n) {}
    ~DSU() {}

    int find(int u) {}

    bool unionSet(int u, int v) {}

    // hàm trả về nhóm các ID chung group
    vector<vector<int>> getGroups() {}
};