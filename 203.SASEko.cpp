// Approach : Same as book allocation problem. Check notes.

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

bool isValid(vector<long long> &heights, long long n, long long m, long long mid) {
	long long sum = 0;
	for(long long i = 0; i < n; i++) {
		if(heights[i] > mid) {
			sum = sum + (heights[i] - mid);
		}
	}
	if(sum < m) {
		return false;
	}
	return true;
}

int main() {
	long long n, m;
	cin >> n;
	cin >> m;
	vector<long long> heights;
	for(long long i = 0; i < n; i++) {
		long long temp;
		cin >> temp;
		heights.push_back(temp);
	}

	long long low = 0;
	long long high = 1000000001;
	for(long long i = 0; i < n; i++) {
		high = max(high, heights[i]);
	}
	long long result = -1;

	while(low <= high) {
		long long mid = low + (high - low) / 2;
		if(isValid(heights, n, m, mid) == true) {
			result = mid;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	cout << result << endl;
	return 0;
}