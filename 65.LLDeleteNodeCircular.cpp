// Approach : keep two pointer curr and prev special case is head otherwise delete normally

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
	cout << "The required Linked List is: ";
	while(ptr -> next != head) {
		cout << ptr -> data << " ";
		ptr = ptr -> next;
	}
	cout << ptr -> data << " ";
}

struct node* deleteNode(struct node* head, int key) {
	if(head == NULL) {
		return head;
	}
	else if(head -> next == head) {
		if(head -> data == key) {
			head = NULL;
			return head;
		}
		else {
			return head;
		}
	}

	struct node* prev = head;
	struct node* curr = head -> next;

	while(curr != head) {
		if(curr -> data == key) {
			prev -> next = curr -> next;
			curr -> next = NULL;
			return head;
		}
		else {
			prev = curr;
			curr = curr -> next;
		}
	}
	if(curr -> data == key) {
		prev -> next = curr -> next;
		head = curr -> next;
		curr -> next = NULL;
	}
	return head;
}

int main() {
    int n, m;
    struct node* head = NULL;
    struct node* ptr = NULL;
    cout << "Enter the element to delete: ";
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
            ptr = ptr -> next;
        }
    }
    ptr -> next = head;
    head = deleteNode(head, m);
    display(head);
    return 0;
}