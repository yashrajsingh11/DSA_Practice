// Approach : Reverse each group of k nodes individually and link the head -> next to the starting element of next group. 

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
    cout << "The Reversed Linked List is: ";
    while(ptr != NULL) {
        cout << ptr -> data << " ";
        ptr = ptr -> next;
    }
}

struct node* reverse (struct node* head, int k) { 
    struct node* nextNode = NULL;
    struct node* current = head;
    struct node* prevNode = NULL;
    struct node* start = head;
    int i = 0;

    while(current != NULL and i < k) {
        nextNode = current -> next;
        current-> next = prevNode;
        prevNode = current;
        current = nextNode;
        i++;
    }

    if(nextNode != NULL) {
        head -> next = reverse(nextNode, k);
    }
    return prevNode;
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

    int k = 3;
    head = reverse(head, k);
    display(head);

    return 0;
}