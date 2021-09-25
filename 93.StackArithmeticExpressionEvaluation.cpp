// Approach : Convert infix to postfix expression using stack and then evaluate using stack.

#include <iostream>
#include <string>
#include <stack>
#include <math.h>

using namespace std;

int precedence(char x) {
	if(x == '^') {
		return 3;
	}
	else if(x == '*' or x == '/') {
		return 2;
	}
	else if(x == '+' or x == '-') {
		return 1;
	}
	else {
		return -1;
	}
}

string convertToPostFix(string A, int n) {
	stack<char> s;
	string B;
	for(int i = 0; i < n; i++) {
		char temp = A[i];
		if(temp == '(') {
			s.push(temp);
		}
		else if(temp == ')') {
			while(s.top() != '(') {
				B.push_back(s.top());
				s.pop();
			}
			s.pop();
		}
		else if(temp >= '0' and temp <= '9') {
			B.push_back(temp);
		}
		else {
			while(!s.empty() and s.top() != '(' and precedence(temp) <= precedence(s.top())) {
				B.push_back(s.top());
				s.pop();
			}
			s.push(temp);
		}
	}
	while(!s.empty()){
		B.push_back(s.top());
		s.pop();
	}
	return B;
}

int evaluate(string B, int n) {
	stack<int> s;
	for(int i = 0; i < n; i++) {
		char temp = B[i];
		if(temp >= '0' and temp <= '9') {
			int val = temp - '0';
			s.push(val);
		}
		else {
			int b = s.top();
			s.pop();
			int a = s.top();
			s.pop();
			if(temp == '+') {
				s.push(a + b);
			} 
			else if(temp == '-') {
				s.push(a - b);
			} 
			else if(temp == '*') {
				s.push(a * b);
			} 
			else if(temp == '/') {
				s.push(a / b);
			}
			else if(temp == '^') {
				s.push(pow(a, b));
			}
		}
	}
	return s.top();
}

int main() {
	string A;
	cout << "Enter Valid Expression: " << endl;
	cin >> A;
	string B = convertToPostFix(A, A.size());
	cout << B << endl;
	cout << evaluate(B, B.size());
	return 0;
}