// Approach : Push the characters one by one into a stack, then store the elements while poping in a string and return.

#include <iostream>
#include <cstring>

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

	char pop() {
		if(top == -1) {
			cout << "Stack is Empty";
			exit(0);
		}
		char val = arr[top];
		top--;
		return val;
	}
};

char* reverse(char *str, int length) {
	Stack stack(length);
    for(int i = 0; i < length; i++) {
    	stack.push(str[i]);
    }
    for(int i = 0; i < length; i++) {
    	str[i] = stack.pop();
    }
    return str;
}

int main() {
	char str[100];
	int length;
	cout << "Enter a String: ";
	cin >> str;
	length = strlen(str);
	char* result = reverse(str, length);
	cout << result;
}