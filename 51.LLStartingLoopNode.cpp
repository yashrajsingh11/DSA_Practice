// Approach : Use Floyd's Loop Detection Algorithm

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

struct node* findFirstLoopNode(struct node* head) {
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
			return slow;
		}
	}
	return NULL;
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

    struct node* result = findFirstLoopNode(head);
    if(result == NULL) {
    	cout << "No Loop";
    }
    else {
    	cout << "Starting Node: " << result -> data;
    }
	return 0;
}