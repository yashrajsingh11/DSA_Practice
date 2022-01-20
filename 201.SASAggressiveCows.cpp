// Approach : Similar to book allocation problem. Check notes

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isValid(vector<int> &stalls, int n, int c, int mx) {
	int currentCow = 0;
	int cows = 1;
	for(int i = 1; i < n; i++) {
		if(stalls[i] - stalls[currentCow] >= mx) {
			cows++;
			currentCow = i;
		}
	}
	if(cows < c) {
		return false;
	}
	return true;
}

int main() {
	int t;
	cin >> t;
	while(t > 0) {
		int n, c;
		cin >> n;
		cin >> c;
		vector<int> stalls;
		for(int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			stalls.push_back(temp);
		}
		sort(stalls.begin(), stalls.end());
	
		int low = stalls[0];
		int high = stalls[n - 1];
		int result = -1;
		while(low <= high) {
			int mid = low + (high - low) / 2;
			if(isValid(stalls, n, c, mid) == true) {
				result = mid;
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}
		cout << result << endl;
		t--;
	}
	return 0;
}