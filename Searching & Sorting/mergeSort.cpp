#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int s, int mid, int e) {
    vector<int> nums;
    int i = s, j = mid + 1;
    
    while (i <= mid && j <= e) {
        if (arr[i] < arr[j]) {
            nums.push_back(arr[i++]);
        } else {
            nums.push_back(arr[j++]);
        }
    }
    while (i <= mid) {
        nums.push_back(arr[i++]);
    }
    while (j <= e) {
        nums.push_back(arr[j++]);
    }

    for (int k = 0; k < nums.size(); k++) {
        arr[s + k] = nums[k];
    }
}

void mergeSort(int arr[], int s, int e) {
    if (s >= e) return;  // Fixed base condition
    
    int mid = s + (e - s) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    
    merge(arr, s, mid, e);
}

int main() {
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
