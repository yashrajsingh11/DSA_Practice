// Approach: The idea is to find the person which is most likely to be the celebrity and then check if it is actually celebrity.
// 1 : Use two pointers a and b as first and last person. IF a knows b then a cannot be celebrity move to next of a if a doesnt know b 
// 		then b cannot be celebrity.At last Check if person a knows nobody and everybody knows a. Then a is celebrity else no celebrity.
// 2 : Push all people into a stack. Take top two check as above and instead of moving to next pop that person and push the other.
// Approach 1 does not require extra stack space;

// ------>>> Approach 1 <<<------

// #include <iostream>
// #include <vector>

// using namespace std;

// int celebrity(vector<vector<int> >& M, int n) {
// 	int a = 0, b = n - 1;
// 	while(a < b) {
// 		M[a][b] == 1 ? a++ : b--;
// 	}
// 	for(int i = 0; i < n; i++) {
// 		if(M[a][i] == 1) {
// 			return -1;
// 		}
// 	}
// 	int count = 0;
// 	for(int i = 0; i < n; i++) {
// 		if(M[i][a] == 1) {
// 			count++;
// 		}
// 	}
// 	if(count != n - 1) {
// 		return -1;
// 	}
// 	return a;
// }	

// int main() {
// 	vector<vector<int>> matrix = 
// 	{
// 		{0, 1, 0, 0},
// 		{0, 0, 0, 0},
// 		{0, 1, 0, 0},
// 		{0, 1, 0, 0}
// 	};
// 	int n = matrix[0].size();
// 	cout << celebrity(matrix, n);
// 	return 0;
// }

// ----->>> Approach 2 <<<-----

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int celebrity(vector<vector<int> >& M, int n) {
	stack<int> s;
	int result;

	for(int i = 0; i < n; i++) {
		s.push(i);
	}

	while(!s.empty()) {
		int a = s.top();
		s.pop();
		int b = s.top();
		s.pop();
		if(s.empty()) {
			M[a][b] == 1 ? result = b : result = a;
			break;
		}
		M[a][b] == 1 ? s.push(b) : s.push(a);
	}

	for(int i = 0; i < n; i++) {
		if(M[result][i] == 1) {
			return -1;
		}
	}
	int count = 0;
	for(int i = 0; i < n; i++) {
		if(M[i][result] == 1) {
			count++;
		}
	}
	if(count != n - 1) {
		return -1;
	}
	return result;
}

int main() {
	vector<vector<int>> matrix = 
	{
		{0, 0, 0, 0},
		{1, 0, 0, 0},
		{1, 0, 0, 0},
		{1, 0, 0, 0}
	};
	int n = matrix[0].size();
	cout << celebrity(matrix, n);
	return 0;
}
