// Approach : Keep two pointers start and end. If the key is smaller than sum of data of start and end then end = end -> prev, if key is
// 			larger than the sum of data of start and end then start = start -> prev			

#include <bits/stdc++.h>

using namespace std;

struct node {
	int data;
	struct node* prev;
	struct node* next;

	node(int x) {
		data = x;
		prev = NULL;
		next = NULL;
	}
};

void pairSum(struct node *head, int x) {
	if(head == NULL or head -> next == NULL) {
		cout << "Not enough data" << endl;
		return ;
	}
	struct node* start = head;
	struct node* end = head;
	while(end -> next != NULL) {
		end = end -> next;
	}

	cout << "These are the pair sum present in the given Linked List: ";
	while(start != end and end -> next != start) {
		if(start -> data + end -> data == x) {
			cout << "(" << start -> data << ", " << end -> data << "), ";
			start = start -> next;
			end = end -> prev;
		}
		else if(start -> data + end -> data < x) {
			start = start -> next;
		}
		else {
			end = end -> prev;
		}
	}
}

int main() {
    int n, m;
    struct node* head = NULL;
    struct node* ptr = NULL;
    cout << "Enter the pair sum of elements to find: ";
    cin >> m;
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
            ptr -> next -> prev = ptr;
            ptr = ptr -> next;
        }
    }

    pairSum(head, m);
    return 0;
}