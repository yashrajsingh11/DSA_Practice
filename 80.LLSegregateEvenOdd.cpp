// Approach: Make 4 pointers for head and tail elements of even and odd lists. Create the even and odd lists and combine them.

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

struct node* divide(int N, struct node *head){
    struct node* even = NULL;
    struct node* odd = NULL;
    struct node* evenHead = NULL;
    struct node* oddHead = NULL;
        
    while(head != NULL) {
        if(head -> data % 2 == 0) {
            if(even == NULL) {
                even = head;
                evenHead = even;
            }
            else {
                even -> next = head;
                even = even -> next;
            }
        }
        else {
            if(odd == NULL) {
                odd = head;
                oddHead = odd;
            }
            else {
                odd -> next = head;
                odd = odd -> next;
            }
        }
        head = head -> next;
    }
    
    if(even != NULL) {
        head = evenHead;
        if(odd != NULL) {
            even -> next = oddHead;
            odd -> next = NULL; 
        }
        else {
            even -> next = NULL;
        }
    }
    else {
        if(odd != NULL) {
            head = oddHead;
            odd -> next = NULL;
        }
        else {
            head = NULL;
        }
    }
    return head;
}

int main() {
    struct node* head = NULL;
    struct node* ptr = NULL;
    int size, val;
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
    head = divide(size, head);
    display(head);
    return 0;
}