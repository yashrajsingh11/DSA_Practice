// Approach: Maintain two arrays:- inDLL, isPresent, inDLL keeps the addresses of nodes of non repeating characters and isPresent keeps
// 			track if the character is repeating or not. Maintain a doubly linked list which stores the non repeating characters.
// 			At any given point head of dll has the first non repeating character. For every element check if it is present or not.
// 			If not present then add to dll, inDLL, isPresent, if present then if inDLL is not null that means we encountered it second
// 			time update dll and inDLL, if inDLL is null that means we encountered it after 2 times hence we dont do anything.
// 			After every check we return the head of the dll as the desired character.

#include <bits/stdc++.h>

using namespace std;

struct node {
	struct node* prev;
	struct node* next;
	char data;

	node(char x) {
		data = x;
		prev = NULL;
		next = NULL;
	}
};

string FirstNonRepeating(string A) {
	bool isPresent[256];
	struct node* inDLL[256];
	struct node* head = NULL;
	struct node*tail = NULL;

	for(int i = 0 ;i < 256; i++) {
		isPresent[i] = false;
		inDLL[i] = NULL;
	}

	for(int i = 0; i < A.size(); i++) {
		if(isPresent[A[i]] == true) {
			if(inDLL[A[i]] != NULL) {
				struct node* temp = inDLL[A[i]];
				if(temp == head) {
					head = head -> next;
				}
				if (temp == tail){
					tail = tail -> prev;
				}
				if (temp -> next != NULL) {
					temp -> next -> prev = temp -> prev;
				}
				if (temp -> prev != NULL) {
					temp -> prev -> next = temp -> next;
				}
				delete(temp);
				inDLL[A[i]] = NULL;
			}
		}
		else {
			isPresent[A[i]] = true;
			if(head == NULL) {
	            head = new node(A[i]);
            	tail = head;
        	}
	        else {
    	        tail -> next = new node(A[i]);
        	    tail -> next -> prev = tail;
        	    tail = tail -> next;
        	}
        	inDLL[A[i]] = tail;
		}

    	if(head == NULL) {
    		A[i] = '#';
    	}
    	else {
    		A[i] = head -> data;
    	}
	}
	return A;
}

int main() {
	string A;
	cin >> A;
	cout << FirstNonRepeating(A);
	return 0;
}