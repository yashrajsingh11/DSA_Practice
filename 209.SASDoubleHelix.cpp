// Approach : Use two pointer approach to find the sum of the maximum path among two sorted array. Take care of edge cases.

#include <iostream>
#include <vector>

using namespace std;

int main() {
	while(1) {
		vector<int> a;
		vector<int> b;
		int n, m;
		cin >> n;
		if(n == 0) {
			break;
		}
		for(int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			a.push_back(temp);
		}
		cin >> m;
		if(m == 0) {
			break;
		}
		for(int i = 0; i < m; i++) {
			int temp;
			cin >> temp;
			b.push_back(temp);
		}

		int i = 0, j = 0, answer = 0, ts1 = 0, ts2 = 0, index1 = 0, index2 = 0;

		while(i < n and j < m) {
			if(a[i] < b[j]) {
				ts1 = ts1 + a[i];
				i++;
			}
			else if(a[i] > b[j]) {
				ts2 = ts2 + b[j];
				j++;
			}
			else {
				answer = answer + max(ts1, ts2) + a[i];
				ts1 = 0;
				ts2 = 0;
				i++;
				j++;
				index1 = i;
				index2 = j;
			}
		}
		ts1 = 0;
		ts2 = 0;
		i = index1;
		j = index2;
		while(i < n) {
			ts1 = ts1 + a[i];
			i++;
		}
		while(j < m) {
			ts2 = ts2 + b[j];
			j++;
		}
		answer = answer + max(ts1, ts2);
		cout << answer << endl;
	}
	return 0;
}