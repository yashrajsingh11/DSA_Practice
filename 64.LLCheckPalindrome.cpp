// Approach : Find the middle node reverse the remaining linked list from the mid to end compare one by one head and mid elements.

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

struct node* getMid(struct node* head) {
    struct node* slow = head;
    struct node* fast = head;
    while(fast -> next != NULL and fast -> next -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;

}

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
    struct node* forward = NULL;
    while(curr != NULL) {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

bool isPalindrome(struct node *head) {
    if(head -> next == NULL) {
        return true;
    }
    struct node* mid = NULL;
    mid = getMid(head);
    mid -> next = reverse(mid -> next);
    mid = mid -> next;
    while(mid != NULL) {
        if(head -> data != mid -> data) {
            return false;
        }
        head = head -> next;
        mid = mid -> next;
    }
    return true;
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

    cout << isPalindrome(head);
    return 0;
}