// Approach : Take two lists at a time and apply merge sort logic. Now apply divide and conquer logic to get k/2 lists suc lists. Now
// apply the merge sort logic on them continuing until only a single list is left.

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

struct node* merge(struct node* head1, struct node* head2) {
	struct node* result;
	if(head1 == NULL) {
		return head2;
	}
	if(head2 == NULL) {
		return head1;
	}
	if(head1 -> data <= head2 -> data) {
		result = head1;
		result -> next = merge(head1 -> next, head2);
	}
	else {
		result = head2;
		result -> next = merge(head1, head2 -> next);
	}
	return result;
}

struct node* mergeKLists(struct node* arr[], int k) {
	int first = 0, last = k - 1;
	while(first < last) {
		arr[first] = merge(arr[first], arr[last]);
		first++;
		last--;
		if(first >= last) {
			first = 0;
		}
	}
	return arr[0];
	// for(int i = 1; i < k; i++) {
	// 	arr[0] = merge(arr[0], arr[i]);
	// }
	// return arr[0];
}

int main() {
    int n, k;
    cout << "Enter the number of Linked Lists: ";
    cin >> k;
    struct node* arr[k];

    for(int i = 0; i < k; i++) {
	    struct node* head = NULL;
    	struct node* ptr = NULL;
	    cout << "Enter the size of Linked List: ";
    	cin >> n;

	    for(int j = 0; j < n; j++) {
    	    int value;
        	cout << "Enter Value: ";
	        cin >> value;
    	    if(j == 0) {
        	    head = new node(value);
            	ptr = head;
        	}
	        else {
    	        ptr -> next = new node(value);
        	    ptr = ptr -> next;
        	}
    	}
    	arr[i] = head;
    } 

    struct node* head = mergeKLists(arr, k);
    display(head);
    return 0;
}