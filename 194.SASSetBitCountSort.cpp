// Approach : Using the bultin_popcount function to calculate the number of bits in a number. Now we perform a stable sort because we
// want to maintain the order if the number of bits is same. In the comparator function(which is static and is checked to see if sorting
// should be done between two elements) which should return false if we want sorting logic to be applied to the two elements and should
// return true otherwise, we compare the bits and then accordingly pass them to be sorted or not.

#include <iostream>
#include <algorithm>

using namespace std;

static int comparator(int a, int b) {
    int ca = __builtin_popcount(a);
    int cb = __builtin_popcount(b);
    if(ca <= cb) {
        return false;
    }
    return true;
}

void sortBySetBitCount(int arr[], int n) {
    stable_sort(arr, arr + n, comparator);
}

int main() {
	int arr[] = {1, 2, 3, 4, 5, 6};
	int n = sizeof(arr)/sizeof(arr[0]);
	sortBySetBitCount(arr, n);
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}