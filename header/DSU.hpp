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
    DSU(int n)
    {
        this->n = n;
        this->parent = new int[n];
        this->sizeOfParent = new int[n];

        for (int i = 0; i < n; i++)
        {
            this->parent[i] = i;
            this->sizeOfParent[i] = 1;
        }
    }
    ~DSU()
    {
        delete[] this->parent;
        delete[] this->sizeOfParent;
    }

    int find(int u)
    {
        if (u == parent[u])
            return u;
        return parent[u] = find(parent[u]);
    }

    bool unionSet(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
            return false;

        if (sizeOfParent[u] < sizeOfParent[v])
            swap(u, v);
        parent[v] = u;
        sizeOfParent[u] += sizeOfParent[v];
        return true;
    }

    // hàm trả về nhóm các ID chung group
    vector<vector<int>> getGroups()
    {
        unordered_map<int, vector<int>> mp;
        for (int u = 0; u < this->n; u++)
        {
            mp[this->find(u)].push_back(u);
        }

        vector<vector<int>> groups;
        for (auto &[key, vecOfID] : mp)
        {
            groups.push_back(move(vecOfID));
        }
        return groups;
    }
};