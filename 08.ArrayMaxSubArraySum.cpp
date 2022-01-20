// Approach 1: Kadane's Algorithm "faster"
// Approach 2: Comparing all sum of sub arrays

// ---------------->> Approach 1 <<--------------------

#include <iostream>
#include <climits>

using namespace std;

int maxSubarraySum(int arr[], int n){
    int localMax = 0;
    int globalMax = INT_MIN;
    for(int i = 0; i < n; i++) {
        localMax = max(arr[i], localMax + arr[i]);
        if(localMax > globalMax) {
            globalMax = localMax;
        }
    }
    return globalMax;
}

int main() {
    int arr[] = {20, 4, -10, 55, -80, 33, 12, -32};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << maxSubarraySum(arr, n);
    return 0;
}

// ---------------->> Approach 2 <<--------------------

// int maxSubarraySum(int a[], int n) {
//     int largest = -10000;
//     for(int i = 0; i < n; i++) {
//         int sum = 0;
//         int localMax = a[i];
//         for(int j = i; j < n; j++) {
//             sum = sum + a[j];
//             if(sum > localMax) {
//                 localMax = sum;
//             }
//         }
//         if(localMax > largest) {
//             largest = localMax;
//         }
//     }
//     return largest;
// }
