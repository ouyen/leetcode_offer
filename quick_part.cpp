#include <bits/stdc++.h>

using namespace std;

int QuickFind(int* A,
              int start,
              int end,
              int target);  // Sort A[start]---A[end]

int Part(int* A, int start, int end);

void test_sort() {
    int A[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int ans = QuickFind(A, 0, 9, 4 - 1);
    cout << ans << endl;
    int i;
    for (i = 0; i < 10; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    test_sort();
}

int QuickFind(int* A, int start, int end, int target) {
    if (start > end) {
        throw "start>end";
    }
    int p = start;
    if (start != end)
        p = Part(A, start, end);
    if (p == target)
        return A[p];
    if (p > target)
        return QuickFind(A, start, p - 1, target);
    else
        return QuickFind(A, p + 1, end, target);
}

int Part(int* A, int start, int end) {
    int key = A[end];
    int i = start;
    int j = 0;
    for (j = start; j <= end - 1; ++j) {
        if (A[j] <= key) {
            swap(A[i], A[j]);
            ++i;
        }
    }
    swap(A[end], A[i]);
    return i;
}