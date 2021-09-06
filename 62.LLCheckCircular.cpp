// Approach : if last node has next as head then circular

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

bool isCircular(struct node* head) {
    if(head == NULL) {
        return true;
    }
    struct node* ptr = head;
    while(ptr != NULL) {
        ptr = ptr -> next;
        if(ptr == head) {
            return true;
        }
    }
    return false;
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
    // making it circular
    // ptr -> next = head;

    cout << isCircular(head);

    return 0;
}