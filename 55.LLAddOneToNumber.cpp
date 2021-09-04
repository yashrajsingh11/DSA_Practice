// Approach : Reverse the List. While carry exit add 1 to current element, if it is 10 then carry = 1 and current element = 0 reverse again

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

struct node* addOne(struct node *head) {
	head = reverse(head);
	struct node* ptr = head;
	int carry = 1;
	while(carry == 1) {
		if(ptr -> data == 9) {
			ptr -> data = 0;
			carry = 1;
			if(ptr -> next != NULL) {
				ptr = ptr -> next;
			}
			else {
				struct node* newNode = new node(carry);
				ptr -> next = newNode;
				ptr = ptr -> next;
				carry = 0;
			}
		}
		else {
			ptr -> data = ptr -> data + 1;
			carry = 0;
		}
	}
	head = reverse(head);
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

    head = addOne(head);
    display(head);
	return 0;
}