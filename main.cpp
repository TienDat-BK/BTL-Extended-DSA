#include "header/SimHash.h"
#include "header/MurmurHash3.h"
#include <cmath>
#include "header/ISearch.h"
#include "header/MinHash.h"
#include "header/DSU.h"
#include <chrono>

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
    search.disFunc = &Search::hammingDistance;
    search.num_bands = 4;
    search.threshold = 0.4;

    vector<vector<VectorRecord>> result = search.classifyByBand(vecRecords);

    cout << "Hamming Distance: " << search.hammingDistance(vecRecords[0], vecRecords[1]) << endl;

    int cnt = 0;
    for (const auto &group : result)
    {
        cout << "Group " << ++cnt << ": ";
        for (const auto &vec : group)
        {
            cout << vec.id << " ";
        }
        cout << endl;
    }
}

void stress_search_test(int nVec, int dim, int nBands, double threshold)
{
    vector<VectorRecord> vecRecords;
    for (int i = 0; i < nVec; ++i)
    {
        vector<double> vec(dim);
        for (int j = 0; j < dim; ++j)
        {
            vec[j] = static_cast<double>(rand()) / RAND_MAX;
        }
        vecRecords.emplace_back(i, vec);
    }

    Search search;
    search.disFunc = &Search::hammingDistance;
    search.num_bands = nBands;
    search.threshold = threshold;

    auto start = chrono::high_resolution_clock::now();
    vector<vector<VectorRecord>> result = search.classifyByBand(vecRecords);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    cout << "Classified " << nVec << " vectors of dimension " << dim << " into " << result.size() << " groups using " << nBands << " bands in " << duration.count() << " seconds." << endl;
}

int main()
{
    stress_search_test(5000, 128, 16, 0.5);
    return 0;
}

// g++ -g source/ISearch.cpp source/MurmurHash3.cpp source/SimHash.cpp main.cpp -Iheader -o app.exe -std=c++17