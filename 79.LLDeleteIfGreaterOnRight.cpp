// Approach 1: Apply recursion from the last element using logic if a number is smaller than its next then remove it from the list by
// 			returning the next element to the recursion else add that element to the list and return.

// Approach 2: Reverse the linked list if element on right is greater than max element keep it and update max else remove that element 
// 			form list. Reverse the obtained list again.

#include <bits/stdc++.h>

using namespace std;

struct node{
	int data;
	struct node* next;

	node(int x) {
		data = x;
		next = NULL;
	}
};

void display(struct node* head) {
	struct node* ptr = head;
	cout << "The Linked List is: ";
	while(ptr != NULL) {
		cout << ptr -> data << " ";
		ptr = ptr -> next;
	}
}

struct node* reverse(struct node* head) {
	struct node* prev = NULL;
	struct node* curr = head;
	struct node* nnext = NULL;
	while(curr != NULL) {
		prev = curr -> next;
		curr -> next = nnext;
		nnext = curr;
		curr = prev;
	}
	return nnext;
}

// ----------------->>> Approach 2 <<<-----------------------

struct node* compute(struct node* head) {
	head = reverse(head);
	struct node* current = head;
	struct node* maxNode = head;
	struct node* temp = NULL;
	while(current -> next != NULL) {
		if(current -> next -> data < maxNode -> data) {
			temp = current -> next;
			current -> next = temp -> next;
			temp = NULL;
		}
		else {
			current = current -> next;
			maxNode = current;
		}
	}
	head = reverse(head);
	return head;
}

// ----------------->>> Approach 1 <<<------------------

// struct node* compute(struct node* head) {
// 	if(head -> next == NULL) {
// 		return head;
// 	}
// 	struct node* nextNode = compute(head -> next);
// 	if(nextNode -> data > head -> data) {
// 		return nextNode;
// 	}
// 	head -> next = nextNode;
// 	return head;
// }

int main() {
	struct node* head = NULL;
	struct node* ptr = NULL;
	int size, val;
	cout << "Enter the size of the linked list: ";
	cin >> size;
	while(size > 0) {
		cout << "Enter Value: ";
		cin >> val;
		if(head == NULL) {
			head = new node(val);
			ptr = head;
		}
		else {
			ptr -> next = new node(val);
			ptr = ptr -> next;
		}
		size--;
	}
	head = compute(head);
	display(head);
	return 0;
}