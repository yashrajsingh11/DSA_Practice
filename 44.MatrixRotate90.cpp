// Approach 1 : Rotate the matrix along the diagonal and then along the middle column O(n^2)
// Approach 2 : Simply print the matrix based on the pattern of indices it will form after rotation O(n^2)
// Approach 3 : Consider every concentric square individually and swap the elements accordingly O(n^2)

// ---------------->>> Approach 2 <<<----------------

// 00 01 02 03        30 20 10 00
// 10 11 12 13  <==>  31 21 11 01
// 20 21 22 23        32 22 12 02
// 30 31 32 33        33 23 13 03

#include <bits/stdc++.h>
#define N 4

using namespace std;

void rotate90Clockwise(int a[N][N]) {
	for(int i = 0; i < N; i++) {
		for(int j = N - 1; j >= 0; j--) {
			cout << a[j][i] << " ";
		}
		cout << "\n";
	}
}

int main() {
	int matrix[N][N] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};

	rotate90Clockwise(matrix);
	return 0;
}

// ---------------->>> Approach 3 <<<----------------

// #include <bits/stdc++.h>
// #define N 4

// using namespace std;

// void swap(int &a, int &b) {
// 	int temp = a;
// 	a = b;
// 	b = temp;
// }

// void rotate90Clockwise(int a[N][N]) {
	
// 	for(int i = 0; i < N; i++) {
// 		for(int j = 0; j < i; j++) {
// 			swap(a[i][j], a[j][i]);
// 		}
// 	}

// 	for(int i = 0; i < N; i++) {
// 		for(int j = 0; j < N/2; j++) {
// 			swap(a[i][j], a[i][N - j - 1]);
// 		}
// 	}

// 	for(int i = 0; i < N; i++) {
// 		for(int j = 0; j < N; j++) {
// 			cout << a[i][j] << " ";
// 		}
// 		cout << "\n";
// 	}
// }

// int main() {
// 	int matrix[N][N] = {
// 		{1, 2, 3, 4},
// 		{5, 6, 7, 8},
// 		{9, 10, 11, 12},
// 		{13, 14, 15, 16}
// 	};

// 	rotate90Clockwise(matrix);
// 	return 0;
// }
