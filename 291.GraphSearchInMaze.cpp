// Approach : Use recursion and backtracking to check all possible paths. Sort the valid paths to print in lexicographical order. 

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void getPath(vector<vector<int>> &m, int n, int i, int j, string temp, vector<string> &output) {
    if(i == n - 1 and j == n - 1) {
        output.push_back(temp);
        return;
    }
    m[i][j] = 0;
    if(i + 1 < n and m[i + 1][j] != 0) {
        temp.push_back('D');
        getPath(m , n, i + 1, j, temp, output);
        temp.pop_back();
    }
    if(j + 1 < n and m[i][j + 1] != 0) {
        temp.push_back('R');
        getPath(m , n, i, j + 1, temp, output);
        temp.pop_back();
    }
    if(j - 1 >= 0 and m[i][j - 1] != 0) {
        temp.push_back('L');
        getPath(m , n, i, j - 1, temp, output);
        temp.pop_back();
    }
    if(i - 1 >= 0 and m[i - 1][j] != 0) {
        temp.push_back('U');
        getPath(m , n, i - 1, j, temp, output);
        temp.pop_back();
    }
    m[i][j] = 1;
    return;
}

vector<string> findPath(vector<vector<int>> &m, int n) {
    int i = 0, j = 0;
    vector<string> output;
    string temp = "";
    if(m[i][j] == 0) {
        return output;
    }
    getPath(m, n, i, j, temp, output);
    sort(output.begin(), output.end());
    return output;
}

int main() {
	int n = 4;
	vector<vector<int>> m = {
		{1, 1, 1, 1},
		{1, 1, 1, 1},
		{1, 1, 1, 1},
		{1, 1, 1, 1}
	};
	vector<string> result = findPath(m, n);
	for(int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
	return 0;
}