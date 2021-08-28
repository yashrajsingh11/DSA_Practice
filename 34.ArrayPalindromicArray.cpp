// Question Link is different from the actual question(solving both).
// Approach for 1 : Take every element and check if its palindrome or not
// Approach for 2 : Take two pointers low and high and merge the smaller one with the next element and compare

// ---------------->>> Question - 1 <<<-------------------

// #include <bits/stdc++.h>

// using namespace std;

// bool isPalindrome(int x) {
// 	int temp = x, sum = 0;
// 	while(temp > 0) { 
// 		int r = temp % 10;
// 		sum = (sum * 10) + r;
// 		temp = temp/10;
// 	}
// 	if(sum == x) {
// 		return false;
// 	}
// 	else {
// 		return true;
// 	}
// }

// int PalinArray(int a[], int n) {
// 	for(int i = 0; i < n; i++) {
// 		if(isPalindrome(a[i])) {
// 			return 0;
// 		}
// 	}
// 	return 1;
// }

// int main() {
// 	int a[] = {111, 222, 333};
// 	int n = sizeof(a)/sizeof(a[0]);
// 	cout << PalinArray(a, n);
// 	return 0;
// }

// ---------------->>> Question - 2 <<<-------------------

#include <bits/stdc++.h>

using namespace std;

int findMinOps(int a[], int n) {
	int result = 0;
	int i = 0, j = n - 1;
	while(i < j) {
		if(a[i] < a[j]) {
			a[i + 1] = a[i + 1] + a[i];
			i++;
			result++;
		}
		else if(a[i] > a[j]) {
			a[j - 1] = a[j - 1] + a[j];
			j--;
			result++;
		}
		else {
			i++;
			j--;
		}
	}
	return result;
}

int main() {
	int a[] = {5, 4, 9, 8, 3, 6, 5, 4};
	int n = sizeof(a)/sizeof(a[0]);
	cout << findMinOps(a, n);
	return 0;
}