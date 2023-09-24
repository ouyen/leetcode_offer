#include <bits/stdc++.h>

using namespace std;

void QuickSort(int* A, int start, int end);  // Sort A[start]---A[end]

int Part(int* A, int start, int end);

void test_sort() {
    int A[10] = {-1, 2, 3, 9, -1, 20, 100, -3, 6, 3};
    QuickSort(A, 0, 9);
    int i;
    for (i = 0; i < 10; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    test_sort();
}

void QuickSort(int* A, int start, int end) {
    if (start >= end)
        return;
    int p = Part(A, start, end);
    QuickSort(A, start, p - 1);
    QuickSort(A, p + 1, end);
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