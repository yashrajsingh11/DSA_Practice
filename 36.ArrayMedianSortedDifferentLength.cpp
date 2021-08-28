// Approach 1 : Efficiently merge the two arrays while keeping track of the middle element (linear time)
// Approach 2 : Get the median of both arrays and divide accordingly but it has many corner cases to take care of(logarithmic time)

#include <bits/stdc++.h>

using namespace std;

int getMedian(int a[], int b[], int n, int m) {
	
}

int main() {
	int a[] = {-5, 3, 6, 12, 15}
    int b[] = {-12, -10, -6, -3, 4, 10}
    int n = sizeof(a)/sizeof(a[0])
    int m = sizeof(b)/sizeof(b[0])

    cout << getMedian(a, b, m, n);
	return 0;
}