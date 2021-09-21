// Approach : Start both stacks from opposite side of array

#include <bits/stdc++.h>

using namespace std;

class TwoStacks {
public:
	int* arr;
	int top1;
	int top2;
	int size;

	TwoStacks(int mySize) {
		arr = new int[mySize];
		top1 = -1;
		top2 = mySize;
		size = mySize;
	}

	void push1() {
		if(top1 == top2 - 1) {
			cout << "Array is Full";
			exit(0);
		}

		int val;
		cout << "Enter Value: ";
		cin >> val;
		top1++;
		arr[top1] = val;
	}

	void push2() {
		if(top2 == top1 + 1) {
			cout << "Array is Full";
			exit(0);
		}

		int val;
		cout << "Enter Value: ";
		cin >> val;
		top2--;
		arr[top2] = val;
	}

	void pop1() {
		if(top1 == -1) {
			cout << "Stack 1 is Empty";
			exit(0);
		}
		cout << arr[top1] << " is deleted" << endl;
		top1--;
	}

	void pop2() {
		if(top2 == size) {
			cout << "Stack 2 is Empty";
			exit(0);
		}
		cout << arr[top2] << " is deleted" << endl;
		top2++;
	}

	void display() {
		if(top1 == -1) {
			cout << "Stack 1 is Empty" << endl;
		}
		else {
			cout << "Stack 1 : ";
			for(int i = 0; i <= top1; i++) {
				cout << arr[i] << " ";
			}
			cout << "\n";
		}
		if(top2 == size) {
			cout << "Stack 2 is Empty" << endl;
		}
		else {
			cout << "Stack 2 : ";
			for(int i = size - 1; i >= top2; i--) {
				cout << arr[i] << " ";
			}
			cout << "\n";
		}
	}
};

int main() {
	int size, i = 1, check;
	cout << "Enter the size of array: ";
	cin >> size;

	TwoStacks twoStacks(size);
	while(i) {
		cout << "Enter 1 to push in stack1" << endl;
		cout << "Enter 2 to push in stack2" << endl;
		cout << "Enter 3 to pop from stack1" << endl;
		cout << "Enter 4 to pop from stack2" << endl;
		cout << "Enter 5 to display both stacks" << endl;
		cin >> check;
		switch(check) {
			case 1 : twoStacks.push1();
					break;
			case 2 : twoStacks.push2();
					break;
			case 3 : twoStacks.pop1();
					break;
			case 4 : twoStacks.pop2();
					break;
			case 5 : twoStacks.display();
					break;
			default : cout << "Enter Valid Number" << endl;
		}
		cout << "Enter 0 to exit or 1 to continue: ";
		cin >> i;
	} 
	return 0;
}