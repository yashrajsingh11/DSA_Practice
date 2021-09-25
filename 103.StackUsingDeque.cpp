// Approach 1 : We can use the deque stl library to get push_back, push_front, pop_back, pop_front methods to implement stack and queue.

// Approach 2 : We can create our own deque using doubly linked list and create these methods. 

// -------->>> Approach 1 <<<--------

// #include<iostream>
// #include<deque>

// using namespace std;

// int main() {
// 	deque<int> dq;
// 	int check, val;
// 	while(1) {
// 		cout << "Enter 1 to push to deque stack" << endl;
// 		cout << "Enter 2 to pop from deque stack" << endl;
// 		cout << "Enter 3 to exit" << endl;
// 		cin >> check;
// 		switch(check) {
// 			case 1 : cout << "Enter Value: ";
// 					cin >> val; 
// 					dq.push_back(val);
// 					break;
// 			case 2 : if(dq.empty()) {
// 						cout << "Deque stack is empty" << endl;
// 						break;
// 					}
// 					cout << dq.back() << " is deleted" << endl; 
// 					dq.pop_back();
// 					break;
// 			case 3 : exit(0);
// 					break;
// 			default : cout << "Enter Valid Number" << endl;
// 		}
// 	}
// 	return 0;
// }

// -------->>> Approach 2 <<<--------

#include<iostream>

using namespace std;

struct node {
	int data;
	struct node* prev;
	struct node* next;

	node(int x) {
		data = x;
		next = NULL;
		prev = NULL;
	}
};

class MyDeque {
public: 
	struct node* head = NULL;
	struct node* tail = NULL;

	void push_back() {
		int val;
		cout << "Enter Value: ";
		cin >> val;
		if(head == NULL) {
			head = new node(val);
			tail = head;
		}
		else {
			tail -> next = new node(val);
			tail -> next -> prev = tail;
			tail = tail -> next;
		}
	}

	void pop_back() {
		if(tail == NULL) {
			cout << "Deque stack is empty" << endl;
		}
		else if(tail == head) {
			cout << tail -> data << " is deleted" << endl;
			struct node* temp = head;
			tail = NULL;
			head = NULL;
			delete(temp);
		}
		else {
			cout << tail -> data << " is deleted" << endl;
			struct node* temp = tail;
			tail = tail -> prev;
			tail -> next = temp -> next;
			delete(temp);
		}
	}
};

int main() {
	MyDeque dq;
	int check;
	while(1) {
		cout << "Enter 1 to push to deque stack" << endl;
		cout << "Enter 2 to pop from deque stack" << endl;
		cout << "Enter 3 to exit" << endl;
		cin >> check;
		switch(check) {
			case 1 : dq.push_back();
					break;
			case 2 : dq.pop_back();
					break;
			case 3 : exit(0);
					break;
			default : cout << "Enter Valid Number" << endl;
		}
	}
	return 0;
}

