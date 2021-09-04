// Approach 1 : Use hashmap (high space complexity)
// Approach 2 : Floyd Cycle Detection Algorithm (same as done in array, constant space complexity)

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

bool detectLoop(struct node* head) {
    struct node* slow = head;
    struct node* fast = head;
    while(slow && fast && fast -> next) {
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast) {
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

    // Defining loop for the problem here
    // ptr -> next = NULL;
	// ptr -> next = head -> next -> next;

    cout << detectLoop(head);

	return 0;
}