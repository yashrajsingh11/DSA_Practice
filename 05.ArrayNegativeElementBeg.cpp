#include <iostream>

using namespace std;

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void negativeElementBeginning(int a[], int n) {
	int low = 0; 
	int high = n - 1;
	while(low <= high) {
		if(a[low] < 0) {
			low++;
		}
		else {
			swap(a[low], a[high]);
			high--;
		}
	}
	for(int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}

int main() {
	int a[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9 };
	int n = sizeof(a)/sizeof(a[0]);
	negativeElementBeginning(a, n);
	return 0;
}