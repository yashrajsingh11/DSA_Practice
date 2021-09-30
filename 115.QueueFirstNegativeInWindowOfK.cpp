// Approach : Keep a queue which has the index of all the negative elements in the array. Now for each window check if the front of 
// queue has an element inside the window if true then return that element else return 0. Now for the updated window check if the front
// of queue has index lower than lower bound of window if true then remove that index from queue. At each iteration we need to remove 
// only one such element since we are incrementing by one only.

#include <iostream>
#include <queue>

using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
	vector<long long> result;
	queue<long long> q;
	for(int i = 0; i < N; i++) {
		if(A[i] < 0) {
			q.push(i);
		}
	}
	int j = 0;
	for(int i = K - 1; i < N;) {
		if(!q.empty() and q.front() <= i){
			result.push_back(A[q.front()]);
		}
		else {
			result.push_back(0);
		}
		i++;
		j++;
		if(!q.empty() and q.front() < j) {
			q.pop();
		}
	}
	return result;
}

int main() {
	long long int A[] = {-458, -598, -79, 544, 4, 954, 954, 4};
	long long int k = 3;
	long long int n = sizeof(A)/sizeof(A[0]);
	vector<long long> result(n);
	result = printFirstNegativeInteger(A, n, k);
	for(int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	return 0;
}