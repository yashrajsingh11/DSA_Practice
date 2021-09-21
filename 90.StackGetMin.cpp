// Approach 1: getMin by comparing all elements of stack
// Approach 2: Store a value in stack such that the previous minimum element can be obtained using it and the current minimum value.
// 			it can be achieved by storing in the stack 2 * value - minimum which is always less than value and updating minimum
// 			equal to value if value is less than minimum else we store normally. When poping if value greater than minimum pop normally
// 			else popped element = min element and minimum equal to 2 * minimum - value which is previous minimum 
// -------------->>> Approach 1 <<<--------------

// #include <iostream>
// #include <stack>

// using namespace std;

// void push(stack<int>&s, int a) {
// 	s.push(a);
// }

// int pop(stack<int>&s) {
// 	int val = s.top();
// 	s.pop();
// 	return val;
// }

// bool isEmpty(stack<int>&s) {
// 	return s.empty();
// }

// bool isFull(stack<int>&s, int n) {
// 	return s.size() == n;
// }

// int getMin(stack<int>&s) {
// 	int minimum = s.top();
// 	while(!s.empty()) {
// 		minimum = min(minimum, s.top());
// 		s.pop();
// 	}
// 	return minimum;
// }

// int main() {
// 	cout << "Enter size of stack: ";
// 	int n; 
// 	cin >> n;
// 	stack<int>s;
// 	while(1) {
// 		cout << "Enter 1 to push to stack" << endl;
// 		cout << "Enter 2 to pop from stack" << endl;
// 		cout << "Enter 3 to check if empty" << endl;
// 		cout << "Enter 4 to check if full" << endl;
// 		cout << "Enter 5 to get minimum element" << endl;
// 		cout << "Enter 6 to quit" << endl;
// 		int check;
// 		cin >> check;
// 		switch(check) {
// 			case 1 : if(isFull(s, n)) {
// 						cout << "Stack is Full" << endl;
// 						break;
// 					} 
// 					cout << "Enter Value: ";
// 					int a;
// 					cin >> a; 
// 					push(s, a);
// 					break;
// 			case 2 : if(isEmpty(s)) {
// 						cout << "Stack is Empty" << endl;
// 						break;
// 					} 
// 					cout << "Popped: " << pop(s) << endl;
// 					break;
// 			case 3 : cout << "IsEmpty: " << isEmpty(s) << endl;;
// 					break;
// 			case 4 : cout << "IsFull: " << isFull(s, n) << endl;
// 					break;
// 			case 5 : if(isEmpty(s)) {
// 						cout << "Stack is Empty" << endl;
// 						break;
// 					} 
// 					cout << "Minimum: " << getMin(s) << endl;
// 					exit(0);
// 					break;
// 			case 6 : exit(0);
// 					break;
// 			default : cout << "Enter Valid Number" << endl;
// 		}
// 	}
// 	return 0;
// }

// ----------->>> Approach 2 <<<-------------

#include <iostream>
#include <stack>

using namespace std;

class Stack {
public:
	stack<int> s;
	int minimum;

	void push() {
		int val;
		cout << "Enter Value: ";
		cin >> val;
		if(s.empty()) {
			minimum = val;
			s.push(val);
		}
		else {
			if(val < minimum) {
				s.push((val * 2) - minimum);
				minimum = val;
			}
			else {
				s.push(val);
			}
		}
	}

	int pop() {
		int val = s.top();
		s.pop();
		if(s.empty()) {
			minimum = 1000;
			return val;
		}
		if(minimum < val) {
			return val;
		}
		else {
			int temp = minimum;
			minimum = (minimum * 2) - val;
			return temp;
		}
	}

	bool isEmpty() {
		return s.empty();
	}

	int getMin() {
		return minimum;
	}
};

int main() {
	int n, check;
	Stack stack;
	while(1) {
		cout << "Enter 1 to push" << endl;
		cout << "Enter 2 to pop" << endl;
		cout << "Enter 3 to get minimum" << endl;
		cout << "Enter 4 to quit" << endl;
		cin >> check;
		switch(check) {
			case 1 : stack.push();
					break;
			case 2 : if(stack.isEmpty()) {
						cout << "Stack is Empty" << endl;
					} 
					else {
						cout << stack.pop() << " is deleted" << endl;
					}
					break;
			case 3 : if(stack.isEmpty()) {
						cout << "Stack is Empty" << endl;
					}
					else {
						cout << stack.getMin() << " is minimum" << endl;
					}
					break;
			case 4 : exit(0);
					break;
			default : cout << "Enter Valid Number" << endl;
		}
	}
	return 0;
}