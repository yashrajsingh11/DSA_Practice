// Approach : Consider each sub linked list as a separate list and merge them together using merge sort logic.

#include <bits/stdc++.h>

using namespace std;

struct node{
	int data;
	struct node * next;
	struct node * bottom;
	
	node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

void display(struct node* head) {
	struct node* ptr = head;
	cout << "The new Linked List is: ";
	while(ptr !=NULL) {
		cout << ptr -> data << " ";
		ptr = ptr -> bottom;
	}
}

struct node* merge(struct node* head1, struct node* head2) {
	struct node* result = NULL;
    if(head1  == NULL) {
        return head2;
    }
    if(head2 == NULL) {
        return head1;
    }
    if(head1 -> data <= head2 -> data) {
        result = head1;
        result -> bottom = merge(head1 -> bottom, head2);
    }
    else {
        result = head2;
        result -> bottom = merge(head1, head2 -> bottom);
    }
    return result;
}

struct node* flatten(struct node* head) {
	if(head == NULL) {
		return head;
	}
	
	struct node* ptr = head -> next;

	while(ptr != NULL) {
		head = merge(head, ptr);
		ptr = ptr -> next;
	}
	return head;
}

int main() {
	int n, m;
	cout << "Enter the size of Linked List: ";
	cin >> n;
	struct node* head = NULL;
	struct node* ptr = NULL;
	struct node* ptr1 = NULL;
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
            ptr = ptr -> next;
        }
        ptr1 = ptr;
		cout << "Enter the size of sub Linked List: ";
		cin >> m;
		for(int j = 0; j < m; j++) {
			int val;
			cout << "Enter Value: ";
			cin >> val;
			ptr1 -> bottom = new node(val);
			ptr1 = ptr1 -> bottom;
		}
	}
	head = flatten(head);
	display(head);
	return 0;
}