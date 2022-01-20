// Approach : First check for null array. Now if size is even make the first pair as min and max after comparison and then check for the 
// remaining in pair by first comparing each other, then with min or max. If size is odd then make the first element as min and max then
// do the same.

#include <iostream>

using namespace std;

struct Pair {
	int minimum;
	int maximum;
};

struct Pair minMax(int arr[], int n) {
	struct Pair output;
	int i = 0;
	if(n % 2 != 0) {
		output.minimum = arr[0];
		output.maximum = arr[0];
		i++;
	}
	else {
		if(arr[0] > arr[1]) {
			output.minimum = arr[1];
			output.maximum = arr[0];
		}
		else {
			output.minimum = arr[0];
			output.maximum = arr[1];
		}
		i = i + 2;
	}
	while(i < n) {
		if(arr[i] > arr[i + 1]) {
			output.maximum = max(arr[i], output.maximum);
			output.minimum = min(arr[i + 1], output.minimum);
		}
		else {
			output.maximum = max(arr[i + 1], output.maximum);
			output.minimum = min(arr[i], output.minimum);
		}
		i = i + 2;
	}
	return output;
}

int main() {
	int arr[] = {1000, 11, 445, 1, 330, 3000};
	int n = sizeof(arr)/sizeof(arr[0]);
	struct Pair result = minMax(arr, n);
	cout << result.minimum << " " << result.maximum;
	return 0;
}