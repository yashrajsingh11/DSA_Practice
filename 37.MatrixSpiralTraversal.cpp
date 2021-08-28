// Approach : Consider the matrix as a set of elements stored in concentric squares. Recursively append the elements of each square in 
// 			a vector in cloclwise fashion starting from the outer square moving towards the inner square

#include <bits/stdc++.h>

using namespace std;

vector<int> traversal(vector<int> result, vector<vector<int>> matrix, int rowMin, int rowMax, int columnMin, int columnMax) {
	
	if(rowMax - rowMin == 0) {
		for(int i = columnMin; i <= columnMax; i++) {
			result.push_back(matrix[rowMin][i]);
		}
		return result;
	}
	if(columnMax - columnMin == 0) {
		for(int i = rowMin; i <= rowMax; i++) {
			result.push_back(matrix[i][columnMin]);
		}
		return result;
	}

	for(int j = columnMin; j < columnMax; j++) {
		result.push_back(matrix[rowMin][j]);
	}
	
	for(int j = rowMin; j < rowMax; j++) {
		result.push_back(matrix[j][columnMax]);
	}
	
	for(int j = columnMax; j > columnMin; j--) {
		result.push_back(matrix[rowMax][j]);
	}
	
	for(int j = rowMax; j > rowMin; j--) {
		result.push_back(matrix[j][columnMin]);
	}

	rowMin++;
	rowMax--;
	columnMin++;
	columnMax--;
	
	if(rowMin > rowMax or columnMin > columnMax) {
		return result;
	}
	return traversal(result, matrix, rowMin, rowMax, columnMin, columnMax);
}

vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) {
	vector<int> result;
	int rowMin = 0;
	int columnMin = 0;
	int rowMax = r - 1;
	int columnMax = c - 1;

	result = traversal(result, matrix, rowMin, rowMax, columnMin, columnMax);
	return result;
}

int main() {
	vector<vector<int>> matrix = {
		{1, 2, 3, 4, 5},
        {5, 6, 7, 8, 9}
	};
	int r = 2;
	int c = 5;
	
	vector<int> output = spirallyTraverse(matrix, r, c);

	for(int i = 0; i < output.size(); i++) {
		cout << output[i] << " ";
	}

	return 0;
}