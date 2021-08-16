#include <iostream>
#include <algorithm>

using namespace std;

bool find3Numbers(int A[], int n, int X) {
	
	if(n < 3) {
		return false;
	}
	sort(A, A + n);

	for(int i = 0; i < n - 2; i++) {

		int firstNum = A[i];
		int low = i + 1;
		int high = n - 1;
		int secondNum = A[low];
		int thirdNum = A[high];
		int temp = X - firstNum;
		while(low < high) {
			if(secondNum + thirdNum > temp) {
				high--;
				thirdNum = A[high];
			}
			else if(secondNum + thirdNum < temp) {
				low++;
				secondNum = A[low];
			}
			else {
				return true;
			}
		}
	}
	return false;
}

int main() {
	int a[] = {1, 2, 4, 3, 6};
	int n = sizeof(a)/sizeof(a[0]);
	int X = 10;
	cout << find3Numbers(a, n, X);
	return 0;
}