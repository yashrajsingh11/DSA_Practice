// Approach : Use Breadth-First-Search Algorithm. Maintain a queue. First add all rotten oranges. Now for each rotten orange if its 
// adjacent has fresh orange then rot them and dequeue the old rotten orange and enqueue the new rotten oranges. When all previous
// rotten oranges are removed from the queue increment number of days. Keep doing it while queue is not empty. finally check if any 
// fresh orange is left which is unreachable if true return -1 else return number of days.

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
	queue<int> rottenOranges;
	for(int i = 0; i < grid.size(); i++) {
		for(int j = 0; j < grid[0].size(); j++) {
			if(grid[i][j] == 2) {
				rottenOranges.push(i);
				rottenOranges.push(j);
			}
		}
	}
	int days = 0;
	int count = rottenOranges.size();
	while(!rottenOranges.empty()) {
		if(count == 0) {
			days++;
			count = rottenOranges.size();
		}
		int i = rottenOranges.front();
		rottenOranges.pop();
		int j = rottenOranges.front();
		rottenOranges.pop();
		if(i != 0) {
			if(grid[i - 1][j] == 1) {
				grid[i - 1][j] = 2;
				rottenOranges.push(i - 1);
				rottenOranges.push(j);
			}
		}
		if(i != grid.size() - 1) {
			if(grid[i + 1][j] == 1) {
				grid[i + 1][j] = 2;
				rottenOranges.push(i + 1);
				rottenOranges.push(j);
			}
		}
		if(j != 0) {
			if(grid[i][j - 1] == 1) {
				grid[i][j - 1] = 2;
				rottenOranges.push(i);
				rottenOranges.push(j - 1);
			}
		}
		if(j != grid[0].size() - 1) {
			if(grid[i][j + 1] == 1) {
				grid[i][j + 1] = 2;
				rottenOranges.push(i);
				rottenOranges.push(j + 1);
			}
		}
		count = count - 2;
	}

	for(int i = 0; i < grid.size(); i++) {
		for(int j = 0; j < grid[0].size(); j++) {
			if(grid[i][j] == 1) {
				return -1;
			}
		}
	}
	return days;
}

int main() {
	vector<vector<int>> grid = {
		{1, 0, 0, 0},
		{1, 1, 0, 0},
		{2, 1, 1, 0},
		{0, 1, 1, 2},
	};
	cout << orangesRotting(grid);
	return 0;
}