#include "../header/BandBloomFilter.h"
#include <set>
#include <unordered_set>
#include <iostream>
using namespace std;

// ------------------------------------------------------------
// Gom cụm các vector có khả năng trùng nhau (theo hash bucket)
// ------------------------------------------------------------
vector<vector<VectorRecord>> groupSimilar(const BandBloomFilter& filter,
                                          const vector<VectorRecord>& dataset)
{
    vector<vector<VectorRecord>> clusters;
    const auto& bitArray = filter.getBitArray();
    unordered_set<string> seen; // dùng để tránh trùng cụm

    int totalSize = bitArray.size();
    int bands = filter.getBands();
    int m = filter.getM();

    for (int globalIdx = 0; globalIdx < totalSize; globalIdx++) {
        const vector<int>& bucket = bitArray[globalIdx];
        if (bucket.size() <= 1) continue; // chỉ 1 vector thì bỏ qua

        // Sắp xếp ID để tạo khóa duy nhất cho cụm
        vector<int> sortedIDs = bucket;
        sort(sortedIDs.begin(), sortedIDs.end());

        string key;
        for (int id : sortedIDs) key += to_string(id) + "-";
        if (seen.count(key)) continue;
        seen.insert(key);

        // Gom các vectorRecord tương ứng
        vector<VectorRecord> cluster;
        for (int id : sortedIDs) {
            if (id >= 0 && id < (int)dataset.size())
                cluster.push_back(dataset[id]);
        }

        if (!cluster.empty())
            clusters.push_back(cluster);
    }

    return clusters;
}

// ------------------------------------------------------------
// In thông tin các cụm (dùng để debug / kiểm tra)
// ------------------------------------------------------------
void printClusters(const vector<vector<VectorRecord>>& clusters) {
    cout << "Total clusters: " << clusters.size() << endl;
    for (int i = 0; i < clusters.size(); i++) {
        cout << "Cluster " << i + 1 << " (size = " << clusters[i].size() << "): ";
        for (const auto& rec : clusters[i]) {
            cout << rec.id << " "; // giả sử VectorRecord có field id
        }
        cout << endl;
    }
}
