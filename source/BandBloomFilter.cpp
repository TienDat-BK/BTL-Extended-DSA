#include "../header/BandBloomFilter.h"

vector<size_t> BandBloomFilter::getHashIndices(const vector<double> &subvec, int band) const {
    uint64_t out[2];
    MurmurHash3_x64_128(
        subvec.data(),
        (int)(subvec.size() * sizeof(double)),
        band, // seed khác nhau cho từng band
        &out
    );

    uint64_t h1 = out[0];
    uint64_t h2 = out[1];
    if (h2 % m == 0) h2++; // tránh lặp trùng

    vector<size_t> indices(k);
    for (int i = 0; i < k; i++) {
        indices[i] = (h1 + i * h2) % m;
    }
    return indices;
}

void BandBloomFilter::addVector(int vectorID, const vector<double>& vec) {
    int dim = vec.size();
    int perBand = dim / bands;

    for (int b = 0; b < bands; b++) {
        int start = b * perBand;
        int end = (b == bands - 1) ? dim : start + perBand;
        vector<double> subvec(vec.begin() + start, vec.begin() + end);

        vector<size_t> indices = getHashIndices(subvec, b);
        int bandOffset = b * m; // dịch index cho band

        for (size_t h : indices) {
            bitArray[bandOffset + h].push_back(vectorID); // push vectorID vào vị trí hash
        }
    }
}

void BandBloomFilter::print() const {
    int bandWidth = m;

    for (int b = 0; b < bands; b++) {
        cout << "=== Band " << b << " ===" << endl;
        for (int h = 0; h < bandWidth; h++) {
            int globalIndex = b * m + h;
            cout << h << ": ";
            if (!bitArray[globalIndex].empty()) {
                for (int id : bitArray[globalIndex]) cout << id << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

vector<VectorRecord> BandBloomFilter::hash(const vector<VectorRecord>& input) {
    // Chức năng này không dùng trong BandBloomFilter
    return {};
}
