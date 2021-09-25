// Approach : Recursively reach the bottom and push the value.

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

void popbottom(stack<int> &s) {
	int temp = s.top();
	s.pop();
	if(s.empty()) {
		cout << temp << " is deleted" << endl;
		return;
	}
	else {
		popbottom(s);
		s.push(temp);
	}
}

int main() {
	int check, val;
	stack<int> s;
	while(1) {
		cout << "Enter 1 to push to top of stack" << endl;
		cout << "Enter 2 top pop from top of stack" << endl;
		cout << "Enter 3 to push to bottom of stack" << endl;
		cout << "Enter 4 to pop from bottom of stack" << endl;
		cout << "Enter 5 to quit" << endl;
		cin >> check;
		switch(check) {
			case 1 : cout << "Enter Value: ";
					cin >> val;
					s.push(val);
					break;
			case 2 : if(s.empty()) {
						cout << "Stack is Empty" << endl;
						break;
					} 
					cout << s.top() << " is deleted" << endl;
					s.pop();
					break;
			case 3 : cout << "Enter Value: ";
					cin >> val; 
					pushbottom(s, val);
					break;
			case 4 : if(s.empty()) {
						cout << "Stack is Empty" << endl;
						break;
					}
					popbottom(s);
					break;
			case 5 : exit(0);
					break;
			default: cout << "Enter Valid Number" << endl;
		}
	}
	return 0;
}