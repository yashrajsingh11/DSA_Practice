// Approach : For each node reverse the next and prev link of the node and point head to last element

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

struct node* reverseDLL(struct node * head) {
	if(head == NULL or head -> next == NULL) {
		return head;
	}

	struct node* ptr1 = head;
	struct node* ptr2 = head -> next;
	while(ptr2 != NULL) {
		ptr1 -> next = ptr1 -> prev;
		ptr1 -> prev = ptr2;
		ptr1 = ptr2;
		ptr2 = ptr2 -> next;
	}
	ptr1 -> next = ptr1 -> prev;
	ptr1 -> prev = NULL;
	head = ptr1;
	return head;
}

int main() {
    int n;
    struct node* head = NULL;
    struct node* ptr = NULL;
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

    head = reverseDLL(head);
    display(head);
    return 0;
}