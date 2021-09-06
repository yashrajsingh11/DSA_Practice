// Approach : Use two pointers update one by 1 step and the other by 2 steps when the faster -> next or faster -> next -> next is head
// 			we the slow has reached the middle node.

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

void splitList(struct node *head, struct node **head1_ref, struct node **head2_ref) {
    struct node* slow = head;
    struct node* fast = head;

    while(fast -> next != head and fast -> next -> next != head) {
    	slow = slow -> next;
    	fast = fast -> next -> next;
    }
    
    *head1_ref = head;
    *head2_ref = slow -> next;
    slow -> next = NULL;
    
    if(fast -> next == head) {
    	fast -> next = NULL;
    } 
    else if(fast -> next -> next == head) {
    	fast -> next -> next = NULL;
    }
}

int main() {
    int n;
    int m;
    struct node* head = NULL;
    struct node* ptr = NULL;
    struct node* list1 = NULL;
    struct node* list2 = NULL;
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

    splitList(head, &list1, &list2);
    display(list1);
    display(list2);
    return 0;
}