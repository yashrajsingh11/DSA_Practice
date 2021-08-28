// Question Link is different from the actual question(solving both).
// Approach for 1 : Find median of array normally
// Approach for 2 : Find the median of both arrays and recursively take the half which can contain the combined median

// ---------------->>> Question - 1 <<<-------------------

// #include <bits/stdc++.h>

// using namespace std;

// int find_median(vector<int> v) {
// 	int median;
// 	sort(v.begin(), v.end());

// 	if(v.size() % 2 == 0) {
// 		median = (v[v.size() / 2] + v[(v.size() / 2) - 1]) / 2;
// 	}
// 	else {
// 		median = v[v.size() / 2];
// 	}

// 	return median;
// }

// int main() {
// 	vector<int> v = {56, 67, 30, 79};
// 	cout << find_median(v);
// 	return 0;
// }

// ---------------->>> Question - 2 <<<-------------------

#include <bits/stdc++.h>

using namespace std;

int median(int arr[], int n) {
	if(n % 2 == 0) {
		return (arr[n / 2] + arr[(n / 2) - 1]) / 2;
	} else {
		return arr[n / 2];
	}
}

int getMedian(int a[], int b[], int n) {
	
	if(n == 1) {
		return (a[0] + b[0]) / 2;
	}
	
	else if(n == 2) {
		return (max(a[0], b[0]) + min(a[1], b[1])) / 2;
	}

	int medianA = median(a, n);
	int medianB = median(b, n);

	if(medianA == medianB) {
		return medianA;
	}
	else if(medianA > medianB) {
		if(n % 2 == 0) {
			return getMedian(a, b + n/2 - 1, n - n/2 + 1);
		}
		else {
			return getMedian(a, b + n/2, n - n/2);
		}
	}
	else {
		if(n % 2 == 0) {
			return getMedian(a + n/2 - 1, b, n - n/2 + 1);
		}
		else {
			return getMedian(a + n/2, b, n - n/2);
		}
	}

}

int main() {
	int a[] = { 1, 12, 15, 26, 38 };
    int b[] = { 2, 13, 17, 30, 45 };
    int n = sizeof(a) / sizeof(a[0]);

    cout << getMedian(a, b, n);
	return 0;
}