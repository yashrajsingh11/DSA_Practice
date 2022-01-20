// Approach : Number range from -2^18 to 2^18 so use required datatype. Given in question that the ranges are distinct and in increasing 
// order(not sure if its the case so perform sorting and create the distinct ranges), not for every k check if it lies in the ith range
// if it doesnt update its value to k - range(i) and check in i+1th range. If no ranges left to check then return -1 else return the
// starting value of range + k - 1 value.
// Didnt complete the question because problem statement and cases not clear will come back later maybe, approach is correct though.

#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t > 0) {
		int n, q;
		cin >> n;
		cin >> q;
		int A[n];
		int B[n];
		int k[q];
		for(int i = 0; i < n; i++) {
			cin >> A[i];
			cin >> B[i];
		}
		for(int i = 0; i < q; i++) {
			cin >> k[i];
		}
		for(int i = 0; i < q; i++) {
			int cond = k[i];
			int j = 0;
			while(j < n and B[j] - A[j] < cond) {
				cond = cond - (B[j] - A[j]);
				j++;
			}
			if(j == n) {
				cout << -1 << endl;
			}
			else {
				cout << A[j] + (cond - 1) << endl;
			}
		}
		t--;
	}
}