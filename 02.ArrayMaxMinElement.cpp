#include <iostream>

using namespace std;

struct Pair {
	int min;
	int max;
};

struct Pair getMinMax(int arr[], int arr_size) {

	struct Pair minmax;

	if(arr_size == 1) {
		minmax.min == arr[0];
		minmax.max = arr[0];
		return minmax;
	}

	if(arr[0] > arr[1]) {
		minmax.min = arr[1];
		minmax.max = arr[0];
	} else {
		minmax.min = arr[0];
		minmax.max = arr[1];
	}

	for(int i = 2; i < arr_size; i++) {
		if(arr[i] > minmax.max) {
			minmax.max = arr[i];
		}
		else if(arr[i] < minmax.min) {
			minmax.min = arr[i];
		}
	}

	return minmax;

}

int main() {

	int arr[] = {2, 8, 4, 6, 5, 1, 9, 3, 0, 7};
	int arr_size = 10;
	struct Pair minmax = getMinMax(arr, arr_size);
	cout << minmax.min << endl;
	cout << minmax.max << endl;
	return 0;

}