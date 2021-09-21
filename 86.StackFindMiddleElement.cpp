// Approach: Create the stack using doubly linked list to keep track of the middle element

#include <bits/stdc++.h>

using namespace std;

struct node {
	int data;
	struct node* prev;
	struct node* next;

	node(int x) {
		data = x;
		prev = NULL;
		next = NULL;
	}
};

class DLLStack {
public: 
	struct node* head;
	bool even;
	struct node* mid;

	DLLStack() {
		head = NULL;
		even = true;
		mid = NULL;
	}

	void push() {
		cout << "Enter Value: ";
		int val;
		cin >> val;
		if(head == NULL) {
			head = new node(val);
			mid = head;
			even = false;
		}
		else {
			struct node* temp = new node(val);
			temp -> next = head;
			head -> prev = temp;
			head = head -> prev;
			even ? even = false : even = true;
			if(even) {
				mid = mid -> prev;
			}
		}
	}

	void pop() {
		if(head == NULL) {
			cout << "Stack is Empty\n";
			return;
		}
		cout << head -> data << " is deleted\n";
		struct node* temp = head;
		if (head -> next != NULL) {
			if(even) {
				mid = mid -> next;
			}
			head = head -> next;
			head -> prev = NULL;
			even ? even = false : even = true;
		}
		else {
			head = NULL;
			mid = NULL;
			even = true;
		}
		delete(temp);
	}

	int middle() {
		return mid -> data;
	}

	void delMid() {
		if(mid == NULL) {
			cout << "Stack is Empty\n";
			return;
		}
		cout << mid -> data << " is deleted\n";
		struct node* temp = mid;
		if(head -> next == NULL) {
			head = NULL;
			mid = NULL;
			even = true;
			delete(temp);
			return;
		}
		if(temp == head) {
			head = head -> next;
			mid = head;
			head -> prev = NULL;
			delete(temp);
			return;
		}
		if(even) {
			mid = mid -> next;
			even = false;
		}
		else {
			mid = mid -> prev;
			even = true;
		}
		if(temp -> prev != NULL) {
			temp -> prev -> next = temp -> next;
		}
		if(temp -> next != NULL) {
			temp -> next -> prev = temp -> prev;
		}
		delete(temp);
	}

	void display() {
		struct node* ptr = head;
		cout << "Stack: ";
		while(ptr != NULL) {
			cout << ptr -> data << " ";
			ptr = ptr -> next;
		}
		cout << endl;
	}
};

int main() {
	DLLStack stack;
	int check;
	while(1) {
		cout << "Enter 1 to push into stack" << endl;
		cout << "Enter 2 to pop from stack" << endl;
		cout << "Enter 3 to find middle element" << endl;
		cout << "Enter 4 to delete middle element" << endl;
		cout << "Enter 5 to display the stack" << endl;
		cout << "Enter 6 to quit" << endl;
		cin >> check;
		switch(check) {
			case 1 : stack.push();
					break;
			case 2 : stack.pop();
					break;
			case 3 : cout << "Middle Element: " << stack.middle() << endl;
					break;
			case 4 : stack.delMid();
					break;	
			case 5 : stack.display();
					break;
			case 6 : exit(0);
					break;
			default : cout << "Enter Valid Number" << endl;
		}
	}
	return 0;
}