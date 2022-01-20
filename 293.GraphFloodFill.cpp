// Approach : Use BFS to get all the valid neighbours of a pixel and change their value.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int m = image.size();
    int n = image[0].size();
    int target = image[sr][sc];
    queue<int> q;
    q.push(sr);
    q.push(sc);
    while(!q.empty()) {
        int i = q.front();
        q.pop();
        int j = q.front();
        q.pop();
        image[i][j] = -1;
        if(i + 1 < m) {
            if(image[i + 1][j] == target) {
                q.push(i + 1);
                q.push(j);
            }
        }
        if(i - 1 >= 0) {
            if(image[i - 1][j] == target) {
                q.push(i - 1);
                q.push(j);
            }
        }
        if(j + 1 < n) {
            if(image[i][j + 1] == target) {
                q.push(i);
                q.push(j + 1);
            }
        }
        if(j - 1 >= 0) {
            if(image[i][j - 1] == target) {
                q.push(i);
                q.push(j - 1);
            }
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(image[i][j] == -1){
                image[i][j] = newColor;
            }
        }
    }
    return image;
}

int main() {
	vector<vector<int>> image = {
		{0, 0, 0},
		{0, 1, 1}
	};
	int sr = 1;
	int sc = 1;
	int newColor = 2;

	image = floodFill(image, sr, sc, newColor);

	int m = image.size();
	int n = image[0].size();
	for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}