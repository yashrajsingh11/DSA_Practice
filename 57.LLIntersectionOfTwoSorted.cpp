// Approach : Update either of the linked list if one number is smaller than another, when equal number found update both.

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
	while(ptr != NULL) {
		cout << ptr -> data << " ";
		ptr = ptr -> next;
	}
}

struct node* findIntersection(struct node* head1, struct node* head2) {
    struct node* head = NULL;
    struct node* ptr = NULL;
	while(head1 != NULL and head2 != NULL) {
		if(head1 -> data < head2 -> data) {
			head1 = head1 -> next;
		}
		else if(head2 -> data < head1 -> data) {
			head2 = head2 -> next;
		}
		else if(head1 -> data == head2 -> data){
		    if(head == NULL) {
	    		ptr = new node(head1 -> data);
		    	head = ptr;
		    }
		    else {
		    	ptr -> next = new node(head1 -> data);
		    	ptr = ptr -> next;
		    }
			head1 = head1 -> next;
			head2 = head2 -> next;
		}
	}
	return head;
}

int main() {
    int n;
    int m;
    struct node* head = NULL;
    struct node* firstHead = NULL;
    struct node* firstPtr = NULL;
    struct node* secondHead = NULL;
    struct node* secondPtr = NULL;
    cout << "Enter the size of First Linked List: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        int value;
        cout << "Enter Value: ";
        cin >> value;
        if(i == 0) {
            firstHead = new node(value);
            firstPtr = firstHead;
        }
        else {
            firstPtr -> next = new node(value);
            firstPtr = firstPtr -> next;
        }
    }

    cout << "Enter the size of Second Linked List: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        int value;
        cout << "Enter Value: ";
        cin >> value;
        if(i == 0) {
            secondHead = new node(value);
            secondPtr = secondHead;
        }
        else {
            secondPtr -> next = new node(value);
            secondPtr = secondPtr -> next;
        }
    }

    head = findIntersection(firstHead, secondHead);
    display(head);
    return 0;
}