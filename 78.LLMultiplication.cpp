// Approach : Generate the two numbers from linked lists in integer form while checking for modulo 10^9+7. Multiply normally then modulo

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

long long multiplyTwoLists(struct node* l1, struct node* l2) {
	long long N = 1000000007;
	long long num1 = 0, num2 = 0;
	while(l1 or l2) {
		if(l1) {
			num1 = ((num1 * 10) + l1 -> data) % N;
			l1 = l1 -> next;
		}
		if(l2) {
			num2 = ((num2 * 10) + l2 -> data) % N;
			l2 = l2 -> next; 
		}
	}
	long long result = (num1 * num2) % N;
	return result;
}

int main() {
	int t, l, val;
	struct node* head1 = NULL;
	struct node* ptr1 = NULL;
	struct node* head2 = NULL;
	struct node* ptr2 = NULL;
	cin >> t;
	while(t > 0) {
		cin >> l;
		while(l > 0) {
			cin >> val;
			if(head1 == NULL) {
				head1 = new node(val);
				ptr1 = head1;
			}
			else {
				ptr1 -> next = new node(val);
				ptr1 = ptr1 -> next;
			}
			l--;
		}
		cin >> l;
		while(l > 0) {
			cin >> val;
			if(head2 == NULL) {
				head2 = new node(val);
				ptr2 = head2;
			}
			else {
				ptr2 -> next = new node(val);
				ptr2 = ptr2 -> next;
			}
			l--;
		}
		t--;
	}

	long long result = multiplyTwoLists(head1, head2);
	cout << result;
	return 0;
}