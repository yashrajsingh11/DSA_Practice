// Approach: Make two pointers. Move the first pointer by N nodes and then traverse both pointers until first pointer reaches NULL
//          Now, the second pointer is at the desired node.

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

int getNthFromLast(struct node *head, int n) {
    struct node* ptr1 = head;
    struct node* ptr2 = head;

    for(int i = 0; i < n; i++) {
        if(ptr1 == NULL) {
            return -1;
        }
        ptr1 = ptr1 -> next;
    }

    while(ptr1 != NULL) {
        ptr1 = ptr1 -> next;
        ptr2 = ptr2 -> next;
    }
    return ptr2 -> data;
}

int main() {
    struct node* head = NULL;
    struct node* ptr = NULL;
    int size, val, n;
    cout << "Enter the size of the linked list: ";
    cin >> size;
    while(size > 0) {
        cout << "Enter Value: ";
        cin >> val;
        if(head == NULL) {
            head = new node(val);
            ptr = head;
        }
        else {
            ptr -> next = new node(val);
            ptr = ptr -> next;
        }
        size--;
    }
    cout << "Enter the node form the end: ";
    cin >> n;
    cout << getNthFromLast(head, n);
    return 0;
}