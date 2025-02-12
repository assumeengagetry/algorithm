#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
    int m = A.size();
    int n = B.size();
    vector<int> merged;
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (A[i] <= B[j]) {
            merged.push_back(A[i++]);
        } else {
            merged.push_back(B[j++]);
        }
    }
    while (i < m) merged.push_back(A[i++]);
    while (j < n) merged.push_back(B[j++]);
    int total = merged.size();
    return merged[total/2];
}

int main() {
    int n;
    cin >> n;  
    vector<int> A(n), B(n);
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> B[i];
    }
    cout << findMedianSortedArrays(A, B) << endl;
    return 0;
}