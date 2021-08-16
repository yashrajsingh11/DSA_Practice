// Approach : Using a pointer first separate the positive and negative values of array. Then apply logic to swap alternate values

#include <iostream>

using namespace std;

void alternateNegPos(int a[], int n) {

	int low = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] < 0) {
			swap(a[i], a[low]);
			low++;
		}
	}
	int neg = low - 2;
	int pos = low + 1;
	while(neg > 0 and pos < n) {
		swap(a[neg], a[pos]);
		neg = neg - 2;
		pos = pos + 1;
	}

	for(int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}

int main() {
	int a[] = {2, 3, -4, -1, 6, -9};
	int n = sizeof(a)/sizeof(a[0]);
	alternateNegPos(a, n);
	return 0;
}