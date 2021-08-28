// Approach : Get the Matrix into an array. Sort the array. Return the array to the Matrix

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
	vector<int> array;
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			array.push_back(Mat[i][j]);
		}
	}
	
	sort(array.begin(), array.end());
	int j = 0, k = 0;

	for(int i = 0; i < array.size(); i++) {
		if(k == N) {
			k = 0;
			j++;
		}
		Mat[j][k] = array[i];
		k++;
	}
	return Mat;
}

int main() {
	vector<vector<int>> matrix = {
		{10, 20, 30, 40},
		{15, 25, 35, 45}, 
		{27, 29, 37, 48}, 
		{32, 33, 39, 50}
	};
	int n = matrix.size();
	
	vector<vector<int>> result = sortedMatrix(n, matrix);
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}