// Approach : Add the data in nodes with carry and link it to a new node when one of the list ends add remaining nodes of the list 
//          which still has data to the new list along with carry

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

struct node* reverse(struct node* head) {
    struct node* prev = NULL;
    struct node* curr = head;
    struct node* agla = NULL;
    while(curr != NULL) {
        agla = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = agla;
    }
    head = prev;
    return head;
}

struct node* addTwoLists(struct node* first, struct node* second) {
    first = reverse(first);
    second = reverse(second);
    int carry = 0;

    int temp = first -> data + second -> data;
    if(temp > 9) {
        temp = temp % 10;
        carry = 1;
    }
    struct node* ptr = new node(temp);
    struct node* head = ptr;
    first = first -> next;
    second = second -> next;
    
    while(first != NULL and second != NULL) {
        int data = first -> data + second -> data + carry;
        if(data > 9) {
            data = data % 10;
            carry = 1;
        }
        else {
            carry = 0;
        }
        ptr -> next = new node(data);
        ptr = ptr -> next;
        first = first -> next;
        second = second -> next;
    }

    while(second != NULL) {
        int data = second -> data + carry;
        if(data > 9) {
            data = data % 10;
            carry = 1;
        }
        else {
            carry = 0;
        }
        ptr -> next = new node(data);
        ptr = ptr -> next;
        second = second -> next; 
    }


    while(first != NULL) {
        int data = first -> data + carry;
        if(data > 9) {
            data = data % 10;
            carry = 1;
        }
        else {
            carry = 0;
        }
        ptr -> next = new node(data);
        ptr = ptr -> next;
        first = first -> next;
    }

    if(carry == 1) {
        ptr -> next = new node(carry);
    }

    head = reverse(head);
    return head;

}

int main() {
    int n;
    int m;
    struct node* head = NULL;
    struct node* firstHead = NULL;
    struct node* firstPtr = NULL;
    struct node* secondHead = NULL;
    struct node* secondPtr = NULL;
    cout << "Enter the size of First Linked List: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        int value;
        cout << "Enter Value: ";
        cin >> value;
        if(i == 0) {
            firstHead = new node(value);
            firstPtr = firstHead;
        }
        else {
            firstPtr -> next = new node(value);
            firstPtr = firstPtr -> next;
        }
    }

    cout << "Enter the size of Second Linked List: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        int value;
        cout << "Enter Value: ";
        cin >> value;
        if(i == 0) {
            secondHead = new node(value);
            secondPtr = secondHead;
        }
        else {
            secondPtr -> next = new node(value);
            secondPtr = secondPtr -> next;
        }
    }

    head = addTwoLists(firstHead, secondHead);
    display(head);
    return 0;
}