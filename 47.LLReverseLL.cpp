// Approach 1 : (Iterative) We keep track of the next node of the node we are reversing by changing the direction of the link from the next node to 
// 			  the previous node
// Approach 2 : (Recursive) Recursively reach the last node and apply logic to change links in order to reverse the  list 

#include <bits/stdc++.h>

using namespace std;

struct node {
	int data;
	struct node* next;
};

struct node* head = NULL;

void insert(int val) {
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode -> data = val;
	newNode -> next = head;
	head = newNode;
}

void display() {
	struct node* ptr;
	ptr = head;
	while(ptr != NULL) {
		cout << ptr -> data << " ";
		ptr = ptr -> next;
	}
	cout << "\n";
}

void iterReverse() {
	struct node* ekAage = NULL;
	struct node* current = head;
	struct node* ekPeeche = NULL;

	while(current != NULL) {
		ekAage = current -> next;
		current-> next = ekPeeche;
		ekPeeche = current;
		current = ekAage;
	}
	head = ekPeeche;
}

void recurReverse(struct node* ptr) {
	if(ptr -> next == NULL) {
		head = ptr;
		return;
	}
	recurReverse(ptr -> next);
	ptr -> next -> next = ptr;
	ptr -> next = NULL;
}

int main() {
	insert(3);
	insert(1);
	insert(7);
	insert(2);
	insert(9);
	cout << "The linked list is: ";
	display();
	int check;
	cout << "Enter 1 to iteratively reverse the Linked List\n" << "Enter 2 to recursively reverse the Linked List\n";
	cin >> check;
	if(check == 1) {		
		iterReverse();
		cout << "The Iteratively Reversed Linked List is: ";
	}
	else if(check == 2) {
		recurReverse(head);
		cout << "The Recursively Reversed Linked List is: ";
	}
	else {
		cout << "Enter Valid Number";
		exit(0);
	}
	display();
	return 0;
}