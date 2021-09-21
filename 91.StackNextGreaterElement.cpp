// Approach : Start from the end of array for each element of array while top of stack is less than array element pop else top is the
// 			desired output push current element. if stack becomes empty return -1(check for emptiness first)

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<long long> nextLargerElement(vector<long long> arr, int n) {
	stack<long long int> s;
	vector<long long int> result;
	result.push_back(-1);
	s.push(arr[n - 1]);
	for(int i = n - 2; i >= 0; i--) {
		while(s.top() <= arr[i] and !s.empty()) {
			s.pop();
		}
		if(s.empty()) {
			result.push_back(-1);
		}
		else {
			result.push_back(s.top());
		}
		s.push(arr[i]);
	}
	reverse(result.begin(), result.end());
	return result;
}

int main() {
	vector<long long> arr = {1, 2};
	int n = arr.size();
	vector<long long> result = nextLargerElement(arr, n);
	for(int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
}