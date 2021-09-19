// Approach : Create and assign 6 pointers pointing to the heads and tails of individual 0, 1, 2 linked list. Now link them accordingly. 

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

struct node* segregate(struct node *head) {
	struct node* zero = NULL;
	struct node* one = NULL;
	struct node* two = NULL;
	struct node* zzero = NULL;
	struct node* oone = NULL;
	struct node* ttwo = NULL;
	struct node* ptr = head;

	while(ptr != NULL) {
		if(ptr -> data == 0) {
			if(zero == NULL) {
				zero = ptr;
				zzero = zero;
			}
			else {
				zero -> next = ptr;
				zero = zero -> next;
			}
		}
		else if(ptr -> data == 1) {
			if(one == NULL) {
				one = ptr;
				oone = one;
			}
			else {
				one -> next = ptr;
				one = one -> next;
			}
		}
		else {
			if(two == NULL) {
				two = ptr;
				ttwo = two;
			}
			else {
				two -> next = ptr;
				two = two -> next;
			}
		}
		ptr = ptr -> next;
	}

	if(zzero == NULL) {
		if(oone == NULL) {
			if(ttwo == NULL) {
				return NULL;
			}
			else {
				head = ttwo;
				two -> next = NULL;
			}
		}
		else {
			head = oone;
			if(ttwo == NULL) {
				one -> next = NULL;
			}
			else {
				one -> next = ttwo;
				two -> next = NULL;
			}
		}
	}
	else {
		head = zzero;
		if(oone == NULL) {
			if(ttwo == NULL) {
				zero -> next = NULL;
			}
			else {
				zero -> next = ttwo;
				two -> next = NULL;
			}
		}
		else {
			zero -> next = oone;
			if(ttwo == NULL) {
				one -> next = NULL;
			}
			else {
				one -> next = ttwo;
				two -> next = NULL;
			}
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

    head = segregate(head);
    display(head);
    return 0;
}