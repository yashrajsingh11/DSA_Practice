// Approach : Start from the top right and row++ if 0 is encountered and column-- if 1 is encountered while rows and columns exist
// 			store the value of the row where we did column-- since that is the row with the highest number of 1 up until now
// 			basically checking the left and bottom to see if we the current row has max 1's or any other row below it has max 1's

#include <bits/stdc++.h>

using namespace std;

int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	int result = 0, row = 0, column = m - 1;
	while(row < n and column >= 0) {
		if(arr[row][column] == 0) {
			row++;
		}
		else {
			column--;
			result = row;
		}
	}
	
	if(column == m - 1) {
		return -1;
	}
	else {
		return result;
	}
}

int main() {
	vector<vector<int>> arr = {
		{0, 0, 0, 0},
       	{0, 0, 0, 0},
	    {0, 0, 0, 0},
        {0, 0, 0, 1}
	};
	int n = arr.size();
	int m = arr[0].size();

	cout << rowWithMax1s(arr, n, m);
	return 0;
}