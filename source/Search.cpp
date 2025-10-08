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
    unordered_set<string> seen; // dùng để tránh trùng cụm
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


void BandBloomFilter::addVector(int vectorID, const vector<double>& vec, vector<VectorRecord>& bitArray) {
    int perBand = inputDim / num_bands;

    for (int b = 0; b < num_bands; b++) {
        int start = b * perBand;
        int end = (b == num_bands - 1) ? inputDim : start + perBand;
        vector<double> subvec(vec.begin() + start, vec.begin() + end);

        vector<size_t> indices = getHashIndices(subvec, b);
        int bandOffset = b * m;

        for (size_t h : indices) {
            bitArray[bandOffset + h].vec.push_back(vectorID);
        }
    }
}