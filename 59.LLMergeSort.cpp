// Approach : Split the List recursively and merge them recursively while applying sorting logic

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

struct node* sortedMerge(struct node* front, struct node* back) {
    struct node* result = NULL;
    if(front  == NULL) {
        return back;
    }
    if(back == NULL) {
        return front;
    }
    if(front -> data <= back -> data) {
        result = front;
        result -> next = sortedMerge(front -> next, back);
    }
    else {
        result = back;
        result -> next = sortedMerge(front, back -> next);
    }
    return result;
}

struct node* split(struct node* head) {
    struct node* fast = head;
    struct node* slow = head;
    while(fast -> next != NULL and fast -> next -> next != NULL) {
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    struct node* back = slow -> next;
    slow -> next = NULL;
    return back;
}

struct node* mergeSort(struct node* head) {
    if(head == NULL or head -> next == NULL) {
        return head;
    }
    struct node* front = head;
    struct node* back = NULL;
    back = split(head);
    front = mergeSort(front);
    back = mergeSort(back);
    head = sortedMerge(front, back);
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

    head = mergeSort(head);
    display(head);
    return 0;
}