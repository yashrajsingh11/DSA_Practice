// #include <iostream>

// using namespace std;

// int trappingWater(int arr[], int n){
// 	int left = arr[0];
// 	int right = arr[n-1];
// 	int result = 0;
// 	int tempResult = 0;

// 	for(int i = 1; i < n; i++) {
// 		if(arr[i] >= left) {
// 			result = result + tempResult;
// 			tempResult = 0;
// 			left = arr[i];
// 		}
// 		else if(arr[i] < left) {
// 			tempResult = tempResult + (left - arr[i]);
// 		}
// 		cout << tempResult << " ";
// 	}

// 	tempResult = 0;
// 	for(int i = n - 2; i >= 0; i--) {
// 		if(arr[i] >= right) {
// 			result = result + tempResult;
// 			tempResult = 0;
// 			right = arr[i];
// 		}
// 		else if(arr[i] < right) {
// 			tempResult = tempResult + (right - arr[i]);
// 		}
// 	}

// 	return result;
// }

// int main() {
// 	int a[] = {7, 2, 6, 0, 1, 6};
// 	int n = sizeof(a)/sizeof(a[0]);
// 	cout << trappingWater(a, n);
// 	return 0;
// }