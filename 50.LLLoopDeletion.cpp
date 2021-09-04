// Approach : Find the starting point of the loop using the Floyd Loop Detection Algorithm and then use  while loop to find the last 
// 			node in the Linked List. Set next value of the last node as NULL.

#include <bits/stdc++.h>

using namespace std;

struct node {
	int data;
	struct node* next;

	node(int x) {
		data = x;
		next = NULL;
	}
};

void display(struct node* head) {
	struct node* ptr = head;
	cout << "The new Linked List is: ";
	while(ptr !=NULL) {
		cout << ptr -> data << " ";
		ptr = ptr -> next;
	}
}

void removeLoop(struct node* head) {
	struct node* fast = head;
	struct node* slow = head;
	while(fast and slow and fast -> next) {
		fast = fast -> next -> next;
		slow = slow -> next;
		if(fast == slow) {
			slow = head;
			while(fast != slow) {
				slow = slow -> next;
				fast = fast -> next;
			}
			while(fast -> next != slow) {
				fast = fast -> next;
			}
			fast -> next = NULL;
		}
	}
}

int main() {
	struct node* head;
	struct node* ptr;
	int n;
	cout << "Enter the size of the Linked List: ";
	cin >> n;

	for(int i = 0; i < n; i++) {
		int value;
		cout << "Enter Value: ";
		cin >> value;
		if(i == 0) {
			head = new node(value);
			ptr = head;
		}
		else {
			ptr -> next = new node(value);
			ptr =  ptr -> next;
		}
	}

    // Defining loop for the problem here
    // ptr -> next = NULL;
	ptr -> next = head -> next -> next;

	removeLoop(head);
	display(head);

	return 0;
}