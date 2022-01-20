// Approach 1 : This is a DP problem. So we first create the recursive code then convert it to dp.
// Approach 2 : Space optimization can be done refer this link: https://www.cdn.geeksforgeeks.org/find-maximum-possible-stolen-value-houses/

#include <iostream>

using namespace std;

int solve(int* arr, int n, int* t) {
    if(n == 1) {
        return arr[0];
    }
    if(n == 2) {
        return max(arr[0], arr[1]);
    }
    if(t[n] != -1) {
        return t[n];
    }
    t[n] = max(arr[n - 1] + solve(arr, n - 2, t), solve(arr, n - 1, t));
    return t[n];
}

int FindMaxSum(int arr[], int n) {
    int t[n + 1];
    for(int i = 0; i < n + 1; i++) {
        t[i] = -1;
    }
    return solve(arr, n, t);
}

int main() {
	int arr[] = {5, 5, 10, 100, 10, 5};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << FindMaxSum(arr, n);
	return 0;
}