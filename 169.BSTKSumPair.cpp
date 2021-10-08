// Approach : Apply inorder traversal on one tree and reverse inorder traversal on other tree simultaneously using iteration, and for each
// pair of element if their sum in equal to K, then increase count and traverse one node in both tree, else if sum is greater then 
// traverse one node in reverse inorder tree, else if sum is smaller then traverse in inorder tree.

#include <iostream>
#include <stack>

using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;

	node(int x) {
		data = x;
		left = NULL;
		right = NULL;
	}
};

int countPairs(struct node* root1, struct node* root2, int x) {
    stack<struct node*> s1, s2;
    struct node* curr1 = root1;
    struct node* curr2 = root2;
    int count = 0;
    while(1) {
        while(curr1 != NULL) {
            s1.push(curr1);
            curr1 = curr1 -> left;
        }
        while(curr2 != NULL) {
            s2.push(curr2);
            curr2 = curr2 -> right;
        }
        if(s1.empty() or s2.empty()) {
            break;
        }
        struct node* temp1 = s1.top();
        struct node* temp2 = s2.top();
        if(temp1 -> data + temp2 -> data == x) {
            s1.pop();
            s2.pop();
            count++;
            curr1 = temp1 -> right;
            curr2 = temp2 -> left;
        }
        else if(temp1 -> data + temp2 -> data < x) {
            s1.pop();
            curr1 = temp1 -> right;
        }
        else {
            s2.pop();
            curr2 = temp2 -> left;
        }
    }
    return count;
}

int main() {
	struct node* root1 = new node(8);
	root1 -> left = new node(4);
	root1 -> left -> left = new node(2);
	root1 -> left -> left -> left = new node(1);
	root1 -> left -> left -> right = new node(3);
	root1 -> left -> right = new node(6);
	root1 -> left -> right -> left = new node(5);
	root1 -> left -> right -> right = new node(7);
	root1 -> right = new node(12);
	root1 -> right -> left = new node(10);
	root1 -> right -> left -> left = new node(9);
	root1 -> right -> left -> right = new node(11);
	root1 -> right -> right = new node(14);
	root1 -> right -> right -> left = new node(13);
	root1 -> right -> right -> right = new node(15);
	struct node* root2 = new node(8);
	root2 -> left = new node(4);
	root2 -> left -> left = new node(2);
	root2 -> left -> left -> left = new node(1);
	root2 -> left -> left -> right = new node(3);
	root2 -> left -> right = new node(6);
	root2 -> left -> right -> left = new node(5);
	root2 -> left -> right -> right = new node(7);
	root2 -> right = new node(12);
	root2 -> right -> left = new node(10);
	root2 -> right -> left -> left = new node(9);
	root2 -> right -> left -> right = new node(11);
	root2 -> right -> right = new node(14);
	root2 -> right -> right -> left = new node(13);
	root2 -> right -> right -> right = new node(15);
	cout << countPairs(root1, root2, 13);
}