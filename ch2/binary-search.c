#include <stdio.h>
#include <assert.h>

#define N 100

static int BinarySearch(const int elements[], int target) {
    int lo = 0, hi = N - 1;
    int mid = 0;
    // [lo, hi]
    while (lo <= hi) {
        int mid = ((hi - lo) >> 1) + lo;
        if (elements[mid] == target) {
            return mid;
        } else if (elements[mid] < target) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return -1;
}

int main() {
    int elements[N];
    for (int i = 0; i < N; i++) {
        elements[i] = i;        
    }
    assert(BinarySearch(elements, 100) == -1);
    assert(BinarySearch(elements, 10) == 10);
    assert(BinarySearch(elements, 50) == 50);
    return 0;
}