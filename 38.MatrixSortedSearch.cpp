// Approach : Consider the matrix as an array and apply binary search while considering its 2d shape

#include <bits/stdc++.h> 

using namespace std;

bool bSearch(vector<vector<int>> matrix, int rows, int columns, int low, int high, int target) {
	int mid = (low + high) / 2;
	int i = mid / columns;
	int j = mid % columns;

	if(high >= low) {

		if(matrix[i][j] < target) {
			return bSearch(matrix, rows, columns, mid + 1, high, target);
		} 
		
		else if(matrix[i][j] > target){
			return bSearch(matrix, rows, columns, low, mid - 1, target);
		}
	
		else {
			return true;
		}
	}
	return false;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	
	int rows = matrix.size();
	int columns = matrix[0].size();
	int low = 0;
	int high = (rows * columns) - 1;
	
	return bSearch(matrix, rows, columns, low, high, target);
}

int main() {
	vector<vector<int>> matrix = {
		{1, 3, 5, 7},
		{10, 11, 16, 20},
		{23, 30, 34, 60}
	};
	int target = 30;

	cout << searchMatrix(matrix, target);
	return 0;
}