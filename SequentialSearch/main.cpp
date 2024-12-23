#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace chrono;

// Function to generate NIMs
vector<long long> generateNIMs(int count, long long start) {
    vector<long long> nims;
    for (int i = 0; i < count; i++) {
        nims.push_back(start + i);
    }
    return nims;
}

// Sequential search (iterative)
int sequentialSearchIterative(const vector<long long> &nims, long long target) {
    for (int i = 0; i < nims.size(); i++) {
        if (nims[i] == target) {
            return i;
        }
    }
    return -1;
}

// Sequential search (recursive)
int sequentialSearchRecursive(const vector<long long> &nims, long long target, int index) {
    if (index >= nims.size()) {
        return -1;
    }
    if (nims[index] == target) {
        return index;
    }
    return sequentialSearchRecursive(nims, target, index + 1);
}





int main() {
    const int dataSize = 100000;
    const long long startNIM = 103022300000;
    long long target = 103022311234; // Example target

    // Generate NIMs
    vector<long long> nims = generateNIMs(dataSize, startNIM);

    // Sequential search (iterative)
    auto start = high_resolution_clock::now();
    int seqIterResult = sequentialSearchIterative(nims, target);
    auto end = high_resolution_clock::now();
    auto seqIterTime = duration_cast<duration<float, microseconds::period>>(end - start).count();

    // Sequential search (recursive)
    start = high_resolution_clock::now();
    int seqRecResult = sequentialSearchRecursive(nims, target, 0);
    end = high_resolution_clock::now();
    auto seqRecTime = duration_cast<duration<float, microseconds::period>>(end - start).count();


    // Output results
    cout << "Sequential Search (Iterative): Index = " << seqIterResult << ", Time = " << seqIterTime << " microseconds" << endl;
    cout << "Sequential Search (Recursive): Index = " << seqRecResult << ", Time = " << seqRecTime << " microseconds" << endl;

    return 0;
}
