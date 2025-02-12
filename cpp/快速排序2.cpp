#include<iostream>
using namespace std;

int N, a[1000];

void quicksort(int left, int right) {
    if (left >= right) return;
    int i = left, j = right;
    int temp = a[left];
    while (i < j) {
        while (i < j && a[j] >= temp) j--;
        while (i < j && a[i] <= temp) i++;
        if (i < j) {
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    a[left] = a[i];
    a[i] = temp;
    quicksort(left, i - 1);
    quicksort(i + 1, right);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    quicksort(0, N - 1);
    for (int j = 0; j < N; j++) {
        cout << a[j] << " ";
    }
    return 0;
}
