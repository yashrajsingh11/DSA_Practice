// Approach : Same as page allocation problem. Check notes. (1ll is used to convert int to long long)

#include <iostream>
#include <climits>

using namespace std;

bool isValid(int* arr, int n, int k, int mid) {
    int sum = 0;
    int painters = 1;
    for(int i = 0; i < n; i++) {
        sum = sum + arr[i];
        if(sum > mid) {
            painters++;
            sum = arr[i];
        }
    }
    if(painters > k) {
        return false;
    }
    return true;
}

long long minTime(int arr[], int n, int k) {
    long long int low = INT_MIN;
    long long int high = 0;
    for(int i = 0; i < n; i++) {
        low = max(low, 1ll*arr[i]);
        high = high + arr[i];
    }
    long long int result = -1;
    while(low <= high) {
        int mid = low + (high - low ) / 2;
        if(isValid(arr, n, k, mid) == true) {
            result = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return result;
}

int main() {
	int arr[] = {10, 20, 30, 40};
	int n = 4;
	int k = 2;
	cout << minTime(arr, n, k);
	return 0;
}