// Approach 1: Kadane's Algorithm "faster"
// Approach 2: Comparing all sum of sub arrays

// ---------------->> Approach 1 <<--------------------

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
