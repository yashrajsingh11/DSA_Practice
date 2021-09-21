// Approach: Stack from scratch with push, pop, isEmpty, isFull, peek(top element), size, display methods.

#include <bits/stdc++.h>

using namespace std;

class Stack {
public:
	int* arr;
	int size;
	int top;

	Stack(int mysize) {
		size = mysize;
		top = -1;
		arr = new int[size];
	}

	void push() {
		if(isFull()) {
			cout << "Stack is Full";
			exit(0);
		}
		int val;
		cout << "Enter Value: ";
		cin >> val;
		top++;
		arr[top] = val;
	}

	void pop() {
		if(isEmpty()) {
			cout << "Stack is Empty";
			exit(0);
		}
		cout << peek() << " deleted\n";
		top--;
	}

	bool isEmpty() {
		return top == -1;
	}

	bool isFull() {
		return top == size - 1;
	}

	int length() {
		return top + 1;
	}

	int peek() {
		if(isEmpty()) {
			cout << "Stack is Empty";
			exit(0);
		}
		return arr[top];
	}

	void display() {
		if(isEmpty()) {
			cout << "Stack is Empty";
			exit(0);
		}
		cout << "Stack: ";
		for(int i = 0; i <= top; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
};

int main() {
	int size;
	cout << "Enter the size of Stack: ";
	cin >> size;

	Stack stack(size);
	int i = 1;
	while(i) {
		int check;
		cout << "Enter 1 to push to stack" << endl;
		cout << "Enter 2 to pop from stack" << endl;
		cout << "Enter 3 to check if empty" << endl;	
		cout << "Enter 4 to check if full" << endl;
		cout << "Enter 5 to get the top element" << endl;
		cout << "Enter 6 to get the size of stack" << endl;
		cout << "Enter 7 to display the stack" << endl;
		cin >> check;
		switch(check) {
			case 1 : stack.push();
					break;
			case 2 : stack.pop();
					break;
			case 3 : cout << "IsEmpty = " << stack.isEmpty() << endl;
					break;
			case 4 : cout << "IsFull = " << stack.isFull() << endl;
					break;
			case 5 : cout << "Top = " << stack.peek() << endl;
					break;
			case 6 : cout << "Length = " << stack.length() << endl;
					break;
			case 7 : stack.display();
					break;
			default : cout << "Enter Valid Number" << endl; 
		}
		cout << "Enter 0 to quit or 1 to continue: ";	
		cin >> i;
	}
	return 0;
}