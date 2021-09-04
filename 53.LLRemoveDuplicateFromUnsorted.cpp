// Approach : Using hashmap to keep track of data and changing links if duplicate data is found

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

struct node* removeDuplicates(struct node *head) {
    struct node* ptr = head;
    set<int> hashmap;
    hashmap.insert(ptr -> data);
    while(ptr -> next != NULL) {
        if(hashmap.find(ptr -> next -> data) == hashmap.end()) {
            ptr = ptr -> next;
            hashmap.insert(ptr -> data);
        }
        else {
            ptr -> next = ptr -> next -> next;
        }
    }
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

    head = removeDuplicates(head);
    display(head);

    return 0;
}