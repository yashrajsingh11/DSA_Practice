// Approach : Find all the 1 in the grid. Now apply Breadth-First-Search Algorithm to update the values of adjacent cells in the grid.
// 			Keep track of the iterations in order to fill the cells.

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> nearest(vector<vector<int>> grid) {
	queue<int> visited;
	for(int i = 0; i < grid.size(); i++) {
		for(int j = 0; j < grid[0].size(); j++) {
			if(grid[i][j] == 1) {
				visited.push(i);
				visited.push(j);
				grid[i][j] = 300000;
			}
		}
	}

	int count = visited.size();
	int space = 1;
	while(!visited.empty()) {
		if(count == 0) {
			count = visited.size();
			space++;
		}
		int i = visited.front();
		visited.pop();
		int j = visited.front();
		visited.pop();
		if(i != 0) {
			if(grid[i - 1][j] == 0) {
				grid[i - 1][j] = space;
				visited.push(i - 1);
				visited.push(j);
			}
		}
		if(i != grid.size() - 1) {
			if(grid[i + 1][j] == 0) {
				grid[i + 1][j] = space;
				visited.push(i + 1);
				visited.push(j);
			}
		}
		if(j != 0) {
			if(grid[i][j - 1] == 0) {
				grid[i][j - 1] = space;
				visited.push(i);
				visited.push(j - 1);
			}
		}
		if(j != grid[0].size() - 1) {
			if(grid[i][j + 1] == 0) {
				grid[i][j + 1] = space;
				visited.push(i);
				visited.push(j + 1);
			}
		}
		count = count - 2;
	}

	for(int i = 0; i < grid.size(); i++) {
		for(int j = 0; j < grid[0].size(); j++) {
			if(grid[i][j] == 300000) {
				grid[i][j] = 0;
			}
		}
	}

	return grid;
}

int main() {
	vector<vector<int>> grid = {
		{0, 0, 0, 0},
		{0, 1, 0, 0},
		{0, 0, 0, 1}
	};
	vector<vector<int>> result = nearest(grid);
	for(int i = 0; i < result.size(); i++) {
		for(int j = 0; j < result[0].size(); j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}