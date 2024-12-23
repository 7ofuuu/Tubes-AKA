#include <iostream>
#include <vector>
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

// Binary search (iterative)
int binarySearchIterative(const vector<long long> &nims, long long target) {
    int left = 0, right = nims.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nims[mid] == target) {
            return mid;
        } else if (nims[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

// Binary search (recursive)
int binarySearchRecursive(const vector<long long> &nims, long long target, int left, int right) {
    if (left > right) {
        return -1;
    }
    int mid = left + (right - left) / 2;
    if (nims[mid] == target) {
        return mid;
    } else if (nims[mid] < target) {
        return binarySearchRecursive(nims, target, mid + 1, right);
    } else {
        return binarySearchRecursive(nims, target, left, mid - 1);
    }
}

int main() {
    const int dataSize = 100000;
    const long long startNIM = 103022300000;
    long long target = 103022301234; // Example target

    // Generate NIMs
    vector<long long> nims = generateNIMs(dataSize, startNIM);

    // Binary search (iterative)
    auto start = high_resolution_clock::now();
    int binIterResult = binarySearchIterative(nims, target);
    auto end = high_resolution_clock::now();
    auto binIterTime = duration_cast<duration<float, microseconds::period>>(end - start).count();

    // Binary search (recursive)
    start = high_resolution_clock::now();
    int binRecResult = binarySearchRecursive(nims, target, 0, nims.size() - 1);
    end = high_resolution_clock::now();
    auto binRecTime = duration_cast<duration<float, microseconds::period>>(end - start).count();

    // Output results
    cout << "Binary Search (Iterative): Index = " << binIterResult << ", Time = " << binIterTime << " microseconds" << endl;
    cout << "Binary Search (Recursive): Index = " << binRecResult << ", Time = " << binRecTime << " microseconds" << endl;

    return 0;
}
