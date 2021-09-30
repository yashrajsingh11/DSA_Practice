// Approach : We maintain two deques- large which stores the elements in decreasing order whose first element is the largest and small
// which stores the elements in increasing order whose first element is the smallest. For every element while it is smaller than the 
// rear of the small deque we pop_back and push_back at the end. For every element while it is larger than the rear of large deque
// we pop_back and push_back at the end. (***Note: The elements popped were of no use since we had a smaller or larger element at the
// higher index which will remain for a longer time in the window). Therefore this way only the useful elements are present in both deque.
// We check above for first k elements, then for each element we check if the front are out of the window or not, then we perform above 
// for that element. Keep adding the front of both queues as the result.

#include <iostream>
#include <deque>

using namespace std;

int SumOfKsubArray(int arr[] , int n , int k) {
	int result = 0;
	deque<int> small;
	deque<int> large;
	small.push_back(0);
	large.push_back(0);
	int i = 0;
	for(; i < k; i++) {
		while(!small.empty() and arr[small.back()] >= arr[i]) {
			small.pop_back();
		}
		while(!large.empty() and arr[large.back()] <= arr[i]) {
			large.pop_back();
		}
		small.push_back(i);
		large.push_back(i);
	}
	result = arr[small.front()] + arr[large.front()];
	for(;i < n; i++) {
		if(small.front() < i - k + 1) {
			small.pop_front();
		}
		if(large.front() < i - k + 1) {
			large.pop_front();
		}
		while(!small.empty() and arr[small.back()] >= arr[i]) {
			small.pop_back();
		}
		while(!large.empty() and arr[large.back()] <= arr[i]) {
			large.pop_back();
		}
		small.push_back(i);
		large.push_back(i);
		result = result + arr[small.front()] + arr[large.front()];
	}
	return result;
}

int main() {
	int arr[] = {1, 5, 3, 2, 2};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 1;
	cout << SumOfKsubArray(arr, n, k);
	return 0;
}