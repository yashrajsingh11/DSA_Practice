// Approach : Sort the intervals according to starting element. Now enter the start and end element of first element in stack.
// 			If start of next element is smaller than top then pop and push larger of end of next element and poped element, else pop 
// 			two times and return them as the desired intervals and add the start and end of the next element in stack.
// 			Already done in array without using extra space;

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> intervals) {
	sort(intervals.begin(), intervals.end());
	stack<int> s;
	vector<vector<int>> result;
	s.push(intervals[0][0]);
	s.push(intervals[0][1]);
	for(int i = 1; i < intervals.size(); i++) {
		if(intervals[i][0] <= s.top()) {
			int largest = s.top();
			s.pop();
			s.push(max(intervals[i][1], largest));
		}
		else {
			vector<int> temp;
			int b = s.top();
			s.pop();
			int a = s.top();
			s.pop();
			temp.push_back(a);
			temp.push_back(b);
			result.push_back(temp);
			s.push(intervals[i][0]);
			s.push(intervals[i][1]);
		}
	}
	vector<int> temp;
	int b = s.top();
	s.pop();
	int a = s.top();
	s.pop();
	temp.push_back(a);
	temp.push_back(b);
	result.push_back(temp);
	return result;
}

int main() {
	vector<vector<int>> intervals = {{1,4},{4,6},{5,10},{15,18}};
	vector<vector<int>> result = mergeIntervals(intervals);
	for(int i = 0; i < result.size(); i++) {
		cout << result[i][0] << " " << result[i][1] << endl;
	}
}