// Approach : Find the tail of the doubly linked list. Modify it to a circular doubly linked list. Reach the mth node where we want to rotate.
// 			make mth node's -> prev -> next = NULL and mth node's -> prev = NULL (break the loop before mth node) and return address of mth node.

#include <bits/stdc++.h>

using namespace std;

struct node {
	int data;
	struct node* next;
	struct node* prev;

	node(int x) {
		next = NULL;
		prev = NULL;
		data = x;
	}
};

void display(struct node* head) {
	struct node* ptr = head;
	cout << "The required Linked List is: ";
	while(ptr != NULL) {
		cout << ptr -> data << " ";
		ptr = ptr -> next;
	}
}

struct node* rotateNNodesDLL(struct node* head, int m) {
	if(head == NULL or head -> next == NULL) {
		return head;
	}

	struct node* tail = head;

	while(tail -> next != NULL) {
		tail = tail -> next;
	}

	head -> prev = tail;
	tail -> next = head;

	for(int i = 0; i < m; i++) {
		head = head -> next;
	}

	head -> prev -> next = NULL;
	head -> prev = NULL;
	return head;
}

int main() {
	int n, m;
    struct node* head = NULL;
    struct node* ptr = NULL;
    cout << "Enter the number of nodes to rotate: ";
    cin >> m;
    cout << "Enter the size of Linked List: ";
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
            ptr -> next -> prev = ptr;
            ptr = ptr -> next;
        }
    }

    head = rotateNNodesDLL(head, m);
    display(head);
	return 0;
}