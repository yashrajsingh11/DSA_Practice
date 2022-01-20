// Approach : Sort the array and then use two pointer approach to find if such a pair exist or not.

#include <iostream>
#include <algorithm>

using namespace std;

bool findPair(int arr[], int size, int n){
    if(size == 1) {
        return false;
    }
    sort(arr, arr + size);
    int low = 0;
    int high = 1;
    while(high < size and low < size) {
        if(abs(arr[low] - arr[high]) == n) {
            return true;
        }
        else if(abs(arr[low] - arr[high]) < n) {
            high++;
        }
        else {
            low++;
            if(low == high) {
                high++;
            }
        }
    }
    return false;
}

int main() {
	int arr[] = {2, 4, 3, 80, 20};
	int size = sizeof(arr)/sizeof(arr[0]);
	int n = 18;
	cout << findPair(arr, size, n);
	return 0;
}