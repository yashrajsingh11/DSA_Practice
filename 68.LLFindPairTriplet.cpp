// Approach : For each node of linked list take the remaining of the linked list and do the same thing done in finding pair sum.

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

void tripletSum(struct node *head, int x) {
    if(head == NULL or head -> next == NULL or head -> next -> next == NULL) {
        cout << "Not enough data" << endl;
        return ;
    }

    cout << "These are the triplet sum present in the given Linked List: ";
    struct node* ptr = head;
    while(ptr -> next -> next != NULL) {
        struct node* start = ptr -> next;
        struct node* end = ptr -> next; 
        while(end -> next != NULL) {
            end = end -> next;
        }
        while(start != end and end -> next != start) {
            if(start -> data + end -> data + ptr -> data == x) {
                cout << "(" << ptr -> data << ", " << start -> data << ", " << end -> data << "), ";
                start = start -> next;
                end = end -> prev;
            }
            else if(start -> data + end -> data + ptr -> data < x) {
                start = start -> next;
            }
            else {
                end = end -> prev;
            }
        }
    ptr = ptr -> next;
    }
}

int main() {
    int n, m;
    struct node* head = NULL;
    struct node* ptr = NULL;
    cout << "Enter the triplet sum of elements to find: ";
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

    tripletSum(head, m);
    return 0;
}