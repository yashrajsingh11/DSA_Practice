// Approach : Use a stack to stre the starting brackets. If matching ending brackets are not found then return else pop the starting 
// 			bracket from stack. When all brackets are checked, check if stack is empty then balanced, if not empty then unbalanced.

#include <iostream>
#include <string>

using namespace std;

class Stack {
public:
	char* arr;
	int size;
	int top;

	Stack(int mySize) {
		arr = new char[mySize];
		size = mySize;
		top = -1;
	}

	void push(char x) {
		if(top == size - 1) {
			cout << "Stack is Full";
			exit(0);
		}
		top++;
		arr[top] = x;
	}

	void pop() {
		if(top == -1) {
			cout << "Stack is Empty";
			exit(0);
		}
		top--;
	}

	char peek() {
		return arr[top];
	}

	bool isEmpty() {
		return top == -1;
	}

};

bool ispar(string A) {
	Stack parenthesis(A.size());
	for(int i = 0; i < A.size(); i++) {
		if(A[i] == '(' or A[i] == '{' or A[i] == '[') {
			parenthesis.push(A[i]);
		}
		else {
			if((A[i] == ')' and parenthesis.peek() == '(') or (A[i] == '}' and parenthesis.peek() == '{') or (A[i] == ']' and parenthesis.peek() == '[')) {
				parenthesis.pop();
			}
			else {
				return false;
			}
		}
	}
	if(parenthesis.isEmpty()) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	string A;
	cout << "Enter parenthesis string: ";
	cin >> A;
	isPar(A) ? cout << "balanced" : cout << "unbalanced";
	return 0;
}