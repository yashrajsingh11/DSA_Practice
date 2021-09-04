// Approach : Move till the end and change links accordingly to make the last element as first element

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

struct node* lastElementToFront(struct node* head) {
    if (head == NULL || head -> next == NULL) { 
        return head; 
    }
    struct node* ptr1 = head;
    struct node* ptr2 = ptr1 -> next;

    while(ptr2 -> next != NULL) {
        ptr1 = ptr1 -> next;
        ptr2 = ptr2 -> next;
    }
    ptr1 -> next = NULL;
    ptr2 -> next = head;
    head = ptr2;
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
            ptr = ptr -> next;
        }
    }

    head = lastElementToFront(head);
    display(head);

    return 0;
}