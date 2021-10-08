// Approach 1 : We can take one element of preorder array at a time and insert in the BST normally. Time : O(n*h) and O(n^2) for skewed. 
// Approach 2 : We can use a stack to enter each element at its correct position. Time : O(n), Space : O(n)

// --------->>> Approach 1 <<<-----------

// #include <iostream>

// using namespace std;

// struct node{
// 	int data;
// 	struct node* left;
// 	struct node* right;

// 	node(int x) {
// 		data = x;
// 		left = NULL;
// 		right = NULL;
// 	}
// };

// struct node* insert(struct node* root, int value) {
// 	if(root == NULL) {
// 		struct node* temp = new node(value);
// 		return temp;
// 	}
// 	if(root -> data > value) {
// 		root -> left = insert(root -> left, value);
// 	}
// 	else {
// 		root -> right = insert(root -> right, value);
// 	}
// 	return root;
// }

// struct node* getBST(int* pre, int n) {
// 	struct node* root = NULL;
// 	for(int i = 0; i < n; i++) {
// 		root = insert(root, pre[i]);
// 	}
// 	return root;
// }

// void inorder(struct node* root) {
// 	if(root == NULL) {
// 		return;
// 	}
// 	inorder(root -> left);
// 	cout << root -> data << " ";
// 	inorder(root -> right);
// }

// int main() {
// 	int pre[] = {8, 4, 2, 1, 3, 6, 5, 7, 12, 10, 9, 11, 14, 13, 15};
// 	int n = sizeof(pre) / sizeof(pre[0]);
// 	struct node* root = getBST(pre, n);
// 	inorder(root);
// 	return 0;
// }

// --------->>> Approach 2 <<<-----------

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

struct node* getBST(int* pre, int n) {
	stack<struct node*> s;
	struct node* root = NULL;
	for(int i = 0; i < n; i++) {
		if(s.empty()) {
			root = new node(pre[i]);
			s.push(root);
		}
		else if(!s.empty() and pre[i] < s.top() -> data) {
			s.top() -> left = new node(pre[i]);
			s.push(s.top() -> left);
		}
		else if(!s.empty() and pre[i] > s.top() -> data){
			struct node* temp = NULL;
			while(!s.empty() and s.top() -> data < pre[i]) {
				temp = s.top();
				s.pop();
			}
			temp -> right = new node(pre[i]);
			s.push(temp -> right);
		}
	}
	return root;
}

void inorder(struct node* root) {
	if(root == NULL) {
		return;
	}
	inorder(root -> left);
	cout << root -> data << " ";
	inorder(root -> right);
}

int main() {
	int pre[] = {8, 4, 2, 1, 3, 6, 5, 7, 12, 10, 9, 11, 14, 13, 15};
	int n = sizeof(pre) / sizeof(pre[0]);
	struct node* root = getBST(pre, n);
	inorder(root);
	return 0;
}