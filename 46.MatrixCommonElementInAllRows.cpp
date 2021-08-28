// Approach 1 : Sort every row of the matrix individually and then find common elements. O(mnlogn) but no extra space
// Approach 2 : Use maps to check the frequency of elements. O(mn) but with extra n space "faster"

// ------------------->>> Approach 2 <<<--------------------

#include <bits/stdc++.h>
#define M 4
#define N 5

using namespace std;

void commonElements(int matrix[M][N]) {
	int hashmap[100000] = {0};
	
	for(int i = 0; i < N; i++) {
		hashmap[matrix[0][i]] = 1;
	}

	for(int i = 1; i < M; i++) {
		for(int j = 0; j < N; j++) {
			if(hashmap[matrix[i][j]] > 0) {
				hashmap[matrix[i][j]]++;
			}
		}
	}

	for(int i = 0; i < 100000; i++) {
		if(hashmap[i] == M) {
			cout << i << " ";
		}
	}

}

int main() {
    int matrix[M][N] = {
        {1, 2, 1, 4, 8},
        {3, 7, 8, 5, 1},
        {8, 7, 7, 3, 1},
        {8, 1, 2, 7, 9}
    };
    commonElements(matrix);
	return 0;
}