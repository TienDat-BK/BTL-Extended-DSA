#include "../header/BandBloomFilter.h"

vector<size_t> BandBloomFilter::getHashIndices(const vector<double> &subvec, int band) const {
    uint64_t out[2];
    MurmurHash3_x64_128(
        subvec.data(),
        (int)(subvec.size() * sizeof(double)),
        band,
        &out
    );

    uint64_t h1 = out[0];
    uint64_t h2 = out[1];
    if (h2 % m == 0) h2++;

    vector<size_t> indices(k);
    for (int i = 0; i < k; i++) {
        indices[i] = (h1 + i * h2) % m;
    }
    return indices;
}

void BandBloomFilter::addVector(int vectorID, const vector<double>& vec, vector<VectorRecord>& bitArray) {
    int perBand = inputDim / num_bands;

    for (int b = 0; b < num_bands; b++) {
        int start = b * perBand;
        int end = (b == num_bands - 1) ? inputDim : start + perBand;
        vector<double> subvec(vec.begin() + start, vec.begin() + end);

        vector<size_t> indices = getHashIndices(subvec, b);
        int bandOffset = b * m;

        cout << "Vector " << vectorID << " - Band " << b << ": ";
        for (size_t h : indices) {
            cout << h << " ";
            bitArray[bandOffset + h].vec.push_back(vectorID);
        }
        cout << endl;
    }
}



vector<VectorRecord> BandBloomFilter::hash(const vector<VectorRecord>& input) {
    // 1️⃣ Tạo bit array cục bộ
    vector<VectorRecord> bitArray(num_bands * m);

    // 2️⃣ Thêm toàn bộ vector vào Bloom Filter
    for (int i = 0; i < (int)input.size(); i++) {
        addVector(i, input[i].vec, bitArray);
    }

    return bitArray;
}
