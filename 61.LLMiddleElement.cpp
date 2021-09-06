// Approach : Take two pointers slow and fast, increment fast by 2 and slow by 1, when fast -> next = null or fast -> next -> next = null
//          slow -> next is the result

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

struct node* middleNode(struct node* head) {
    if(head -> next == NULL) {
        return head;
    }
    struct node* fast = head -> next;
    struct node* slow = head;
    while(fast -> next != NULL and fast -> next -> next != NULL) {
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    return slow -> next;
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

    head = middleNode(head);
    display(head);
    return 0;
}