// Approach : Maintain a stack. For each character of string, if it is operand push to stack. If operator then pop top two elements
// 			perform the operation then push the result.

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int evaluatePostfix(string S) {
	stack<int> s;
	for(int i = 0; i < S.size(); i++) {
		char temp = S[i];
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
		}
	}
	return s.top();
}

int main() {
	string A;
	cout << "Enter Valid Expression: " << endl;
	cin >> A;
	cout << evaluatePostfix(A);
	return 0;
}