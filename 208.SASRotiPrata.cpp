// Approach : Same as book allocating problem, instead of pages we have to minimize the maximum time all chef will take to cook. 
// Think in the way, what is the total pratas we can get if we give all chefs x time and minimuze this x.

#include <iostream>
#include <climits>
#include <vector>

using namespace std;

bool isValid(vector<int> &cooks, int l, int p, int mid) {
	int pratas = 0;
	for(int i = 0; i < l; i++) {
		int sum = 0;
		int count = 1;
		while(sum + (count * cooks[i]) <= mid) {
			sum = sum + (count * cooks[i]);
			pratas++;
			count++;
		}
	}
	if(pratas < p) {
		return false;
	}
	return true;
}

int main() {
	int t;
	cin >> t;
	while(t > 0) {
		int p, l;
		cin >> p;
		cin >> l;
		vector<int> cooks;
		for(int i = 0; i < l; i++) {
			int temp;
			cin >> temp;
			cooks.push_back(temp);
		}

		int low = 0;
		int high;
		int mx = INT_MIN;
		for(int i = 0; i < l; i++) {
			mx = max(mx, cooks[i]);
		}
		high = (p * ((2 * mx) + ((p - 1) * mx))) / 2;
		int result = -1;

		while(low <= high) {
			int mid = low + (high - low) / 2;
			if(isValid(cooks, l, p, mid) == true) {
				result = mid;
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}
		cout << result << endl;
		t--;
	}
	return 0;
}