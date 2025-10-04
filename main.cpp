#include "header/SimHash.h"
#include "header/MurmurHash3.h"
#include <cmath>
#include "header/ISearch.h"
#include "header/MinHash.h"
#include "header/DSU.h"

void DSU_test()
{
    DSU dsu(5);
    dsu.unionSet(0, 1);
    dsu.unionSet(1, 2);
    dsu.unionSet(0, 2);

    vector<vector<int>> groups = dsu.getGroups();
    for (const auto &group : groups)
    {
        for (int member : group)
        {
            cout << member << " ";
        }
        cout << endl;
    }
}

void test_ClassifyByBand()
{
    vector<VectorRecord> vecRecords = {
        VectorRecord(1, {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8}),
        VectorRecord(2, {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.81}),
        VectorRecord(3, {0.9, 0.8, 0.7, 0.6, 0.5, 0.4, 0.3, 0.2}),
        VectorRecord(4, {0.91, 0.8, 0.7, 0.6, 0.5, 0.4, 0.3, 0.2}),
        VectorRecord(5, {0.92, 0.8, 0.7, 0.6, 0.5, 0.4, 0.3, 0.2}),
    };

    Search search;
    vector<vector<VectorRecord>> result = search.classifyByBand(vecRecords);

    cout << search.hammingDistance(vecRecords[0], vecRecords[1]) << endl;

    for (const auto &group : result)
    {
        for (const auto &vec : group)
        {
            cout << vec.id << " ";
        }
        cout << endl;
    }
}

int main()
{
    test_ClassifyByBand();
    return 0;
}

// g++ -std=c++17 -O2 -Iheader -o my_program main.cpp source/MurmurHash3.cpp source/SimHash.cpp