// Official approach : Sort the array and make each height of the tower maximum by decreasing the height of all the towers towards right
// by k and increasing all the height of the towers towards left by k. 
// Check whether it has the maximum height or not by comparing it with the last element towards the right side 
// If the tower's height is greater then it's the tallest tower available. Similar for finding the shortest tower.  
// ***********We need not consider where a[i]<k because the height of the tower can't be negative so we have to neglect that case.

#include<algorithm>

int getMinDiff(int arr[], int n, int k) {
    sort(arr, arr + n);
    int lowest;
    int highest;
    int result = arr[n - 1] - arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] >= k and arr[n - 1] >= k) {
            lowest = min(arr[0] + k, arr[i] - k);
            highest = max(arr[i - 1] + k, arr[n - 1] - k);
            result = min(result, highest - lowest);
        }
    }
    return result;
}