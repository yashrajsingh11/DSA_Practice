// Approach : Push '(' and arithmetic operators into a stack. When we encounter a ')' if s.top == '(' then it is redundant.

#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool checkRedundancy(string A) {
	stack<char> s;
	for(int i = 0; i < A.size(); i++) {
		if(A[i] == '(' or A[i] == '+' or A[i] == '-' or A[i] == '*' or A[i] == '/') {
			s.push(A[i]);
		}
		else if(A[i] == ')') {
			if(s.top() == '(') {
				return true;
			}
			while(s.top() != '(') {
				s.pop();
			}
			s.pop();
		}
	}
	return false;
}

int main() {
	string A = "(a+b*(c-d))";
	cout << checkRedundancy(A);
	return 0;
}