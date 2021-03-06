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

struct node* sort(struct node* head, struct node* tail) {
    
}

void quickSort(struct node **headRef) {
    if(*headRef -> next == NULL) {
        return ;
    }
    struct node* tail = *headRef;
    struct node* head = *headRef;
    while(tail -> next != NULL) {
        tail = tail -> next;
    }
    *headRef = sort(head, tail);
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

    quickSort(&head);
    display(head);
    return 0;
}