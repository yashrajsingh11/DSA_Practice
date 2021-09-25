// Approach : stack can be reversed in O(n) if we represent the stack using Linked List. Recursion takes O(n^2) time.
// 1 : Create a stack using linked list and reverse the linked list to reverse the stack.			
// 2 : Recursively reach the last element and push the element to the bottom of the stack one by one.

#include <iostream>
#include <stack>

using namespace std;

void pushbottom(stack<int> &s, int val) {
	if(s.empty()) {
		s.push(val);
	}
	else {
		int temp = s.top();
		s.pop();
		pushbottom(s, val);
		s.push(temp);
	}
}

void reverseStack(stack<int> &s) {
	int val = s.top();
	s.pop();
	if(s.empty()) {
		s.push(val);
		return;
	}
	reverseStack(s);
	pushbottom(s, val);
}

int main() {
	stack<int> s;
	for(int i = 0; i < 10; i++) {
		s.push(i);
	}

	reverseStack(s);
	
	for(int i = 0; i < 10; i++) {
		cout << s.top() << " ";
		s.pop();
	}
	return 0;
}