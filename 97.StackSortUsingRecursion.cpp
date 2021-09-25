// Approach : Reach the last element recursively and then push each element at their correct position while remaking the stack.

#include <iostream>
#include <stack>

using namespace std;

void insertAtCorrectPosition(stack<int> &s, int val) {
	if(s.top() > val) {
		int temp = s.top();
		s.pop();
		if(s.empty()) {
			s.push(val);
			s.push(temp);
			return;
		}
		insertAtCorrectPosition(s, val);
		s.push(temp);
	}
	else {
		s.push(val);
	}
}

void stackSort(stack<int> &s) {
	int temp = s.top();
	s.pop();
	if(s.empty()) {
		s.push(temp);
		return;
	}
	stackSort(s);
	insertAtCorrectPosition(s, temp);
}

void print(stack<int> &s) {
	while(!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
}

int main() {
	stack<int> s;
	s.push(41);
	s.push(3);
	s.push(32);
	s.push(2);
	s.push(11);
	stackSort(s);
	print(s);
	return 0;
}