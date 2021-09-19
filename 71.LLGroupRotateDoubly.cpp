// Approach : Reverse n nodes of doubly linked list iteratively inside a recursion which links the last element of the linked list reversed in the previous
// 			recursion to the first element of linked list reversed in the current recursion.

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

void display(struct node* head) {
	struct node* ptr = head;
	cout << "The required Linked List is: ";
	while(ptr != NULL) {
		cout << ptr -> data << " ";
		ptr = ptr -> next;
	}
}

struct node* groupRotateDLL(struct node* head, int m) {
	struct node* ptr1 = head;
	struct node* ptr2 = head -> next;
	int i = 0;
	while(ptr2 != NULL and i < m - 1) {
		i++;
		ptr1 -> next = ptr1 -> prev;
		ptr1 -> prev = ptr2;
		ptr1 = ptr2;
		ptr2 = ptr2 -> next;
	}
	ptr1 -> next = ptr1 -> prev;
	ptr1 -> prev = NULL;
	if(ptr2 != NULL) {
		head -> next = groupRotateDLL(ptr2, m);
		head -> next -> prev = head;
	}
	else {
		head -> next = NULL;
	}
	return ptr1;
}

int main() {
    int n, m;
    struct node* head = NULL;
    struct node* ptr = NULL;
    cout << "Enter the group size: ";
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

    head = groupRotateDLL(head, m);
    display(head);
    return 0;
}