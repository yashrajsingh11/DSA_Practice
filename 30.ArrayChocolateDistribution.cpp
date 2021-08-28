// Approach: Sort then loop to find the sub array of size m with smallest difference

#include <bits/stdc++.h>

using namespace std;

long long findMinDiff(vector<long long> a, long long n, long long m){
	sort(a.begin(), a.end());
	long long globalMin = INT_MAX;
	long long localMinimum = 0;
	int size = a.size();
	for(int i = 0; i <= size - m; i++) {
		localMinimum = a[i+m-1] - a[i];
		globalMin = min(localMinimum, globalMin);
	}
	return globalMin;
}

int main() {
	vector<long long> a = {3, 4, 1, 9, 56, 7, 9, 12};
	long long n = 8;
	long long m = 5;
	cout << findMinDiff(a, n, m);
	return 0;
}