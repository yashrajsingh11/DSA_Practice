// Approach : Traversing the linked list and changing the next of the node to the next of the next node if the data of the node is 
// 			equal to the data of the next node

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

void removeDuplicates(struct node* head) {
	struct node* ptr = head;
	while(ptr != NULL and ptr -> next != NULL) {
		if(ptr -> data == ptr -> next -> data) {
			ptr -> next = ptr -> next -> next;
		}
		else {
			ptr = ptr -> next;
		}
	}
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
            ptr = ptr -> next;
        }
    }

    removeDuplicates(head);
    display(head);
	return 0;
}