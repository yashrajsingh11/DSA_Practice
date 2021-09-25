// Approach : Taking one bar at a time we try to create a stack of bars in increasing order. This is achieved by removing the bars in 
// 			stack which are larger than current bar. Removal is done by first checking the rectangle formed by bars between that bar 
// 			and current bar(since in increasing order all these bars are part of rectangle) and comparing with largest rectangle found. 
// 			Apply the same logic for the remaining bar in the stack after creating an increadsing order stack.

#include <iostream>
#include <stack>

using namespace std;

long long getMaxArea(long long arr[], int n) {
	stack<int> s;
	int i = 0, result = 0;
	while(i < n) {
		if(s.empty() or arr[i] >= arr[s.top()]) {
			s.push(i);
			i++;
		}
		else {
			int temp = s.top();
			int currentMaximum;
			s.pop();
			if(s.empty()) {
				currentMaximum = arr[temp] * i;
			}
			else {
				currentMaximum = arr[temp] * (i - s.top() - 1);
			}
			result = max(result, currentMaximum);
		}
	}
	while(!s.empty()) {
		int temp = s.top();
		int currentMaximum;
		s.pop();
		if(s.empty()) {
			currentMaximum = arr[temp] * i;
		}
		else {
			currentMaximum = arr[temp] * (i - s.top() - 1);
		}
		result = max(result, currentMaximum);
	}
	return result;
}

int main() {
	long long arr[] = {5, 5, 6, 2, 3, 2, 4, 1, 17};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << getMaxArea(arr, n);
}