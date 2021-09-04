// Approach : Find the length of both linked list. Find absolute difference of lengths = d. Traverse d distance in larger linked list
// 			Now both have same size and since we have to find the elements which are same from the end. Traverse each element and check
// 			if their "address are equal" then common element found. (Dont check the equality of value, check the equality of address)

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

int intersectPoint(struct node* head1, struct node* head2) {
	struct node* ptr1 = head1, *ptr2 = head2;
	int count1 = 0, count2 = 0;
	
	while(ptr1 != NULL) {
		count1++;
		ptr1 = ptr1 -> next;
	}

	while(ptr2 != NULL) {
		count2++;
		ptr2 = ptr2 -> next;
	}
	
	int d = abs(count1 - count2);
	for(int i = 0; i < d; i++) {
		if(count1 > count2) {
			head1 = head1 -> next;
		}
		else {
			head2 = head2 -> next;
		}
	}
	int check = 0;
	while(head1 != NULL and head2 != NULL) {
		if(head1 -> data == head2 -> data) {
			if(check == 0) {
				check = head1 -> data;
			}
			head1 = head1 -> next;
			head2 = head2 -> next;
		}
		else {
			head1 = head1 -> next;
			head2 = head2 -> next;
			check = 0;
		}
	}
	if(check == 0) {
		return -1;
	}
	else {
		return check;
	}
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

    cout << intersectPoint(firstHead, secondHead);
    return 0;
}