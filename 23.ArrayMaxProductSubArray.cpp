#include <iostream>

using namespace std;

long long maxProduct(int *arr, int n) {
	long long globalMax = 
	long long minimum = 1;
	long long localmax = 1;
	for(int i = 0; i < n; i++) {
		if(arr[i] > 0) {
			localmin = 
			localmax = localmax * arr[i];
		}
		if(arr[i] < 0) {
			localmin = localmin * arr[i];
			localmax = 
		}
		if(arr[i] == 0) {
			localmax = 1;
			localmin = 1;
		}
		localmax = max(1, localmax * arr[i]) 
		localmin = min(1, localmin * arr[i])
	}
}

int main() {
	int arr[] = {6, -3, -10, 0, 2};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << maxProduct(arr, n);
	return 0;
}