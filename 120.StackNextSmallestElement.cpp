// Approach : For every elements we check if it is smaller than the top of stack if true then it is the next smallest element for the 
// element at the top of stack. Now, pop the stack and check again until it becomes larger than top of stack, then we push that element. 
// At the end the remaining element in stack do not have next smallest element hence we print -1.

#include <iostream>
#include <stack>

using namespace std;

void printNSE(int arr[], int n) {
	stack<int> s;
	s.push(arr[0]);
	for(int i = 1; i < n; i++) {
		while(!s.empty() and arr[i] < s.top()) {
			cout << s.top() << "<>" << arr[i] << endl;
			s.pop();
		}
		s.push(arr[i]);
	}
	while(!s.empty()) {
		cout << s.top() << "<>" << "-1" << endl;
		s.pop();
	}
}

int main() {
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 ,13, 14, 15, 16, 17, 18, 19, 20};
	int n = sizeof(arr)/sizeof(arr[0]);
	printNSE(arr, n);
	return 0;
}