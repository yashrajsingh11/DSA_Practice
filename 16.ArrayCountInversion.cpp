// Approach : Modify the merge sort to count the number of inversions.

#include <iostream>

using namespace std;

long long int merge(long long arr[], long long temp[], long long left, long long mid, long long right) {
	long long i = left;
	long long j = mid + 1;
	long long k = left;
	long long int count = 0;
	while(i <= mid and j <= right) {
		if(arr[i] <= arr[j]) {
			temp[k] = arr[i];
			k++;
			i++;
		}
		else {
			temp[k] =arr[j];
			k++;
			j++;
			count = count + ((mid + 1) - i);
		}
	}
	while(j <= right) {
		temp[k] = arr[j];
		k++;
		j++;
	}
	while(i <= mid) {
		temp[k] = arr[i];
		k++;
		i++;
	}
	for(i = left; i <= right; i++) {
		arr[i] = temp[i];
	}
	return count;
}

long long int mergesort(long long arr[], long long temp[], long long left, long long right) {
	long long int count = 0;
	long long mid = 0;
	if(right > left) {
		mid = (right + left)/2;
		count += mergesort(arr, temp, left, mid);
		count += mergesort(arr, temp, mid + 1, right);
		count += merge(arr, temp, left, mid, right);
	}
	return count;
}

long long int inversionCount(long long arr[], long long N) {
	long long temp[N];
	return mergesort(arr, temp, 0, N - 1);
}

int main() {
	long long arr[] = {2, 4, 1, 3, 5};
	long long N = sizeof(arr)/sizeof(arr[0]);
	cout << inversionCount(arr, N) << endl;
	for(long long i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}