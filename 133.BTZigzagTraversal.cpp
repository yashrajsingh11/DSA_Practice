// Approach : Use two stack one which stores next nodes in left to right order so that it can be used to traverse right to left, since 
// popping will start from top. Anothers stores the nodes in right to left order, hence it traverses left to right since left will be top.


#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct node {
	int data;
	struct node* left;
	struct node* right;

	node(int x) {
		data = x;
		left = NULL;
		right = NULL;
	}
};

vector<int> zigZagTraversal(struct node* root) {
	stack<struct node*> s1;
	stack<struct node*> s2;
	int check = 0;
	vector<int> result;
	if(root == NULL) {
		return result;
	}
	s1.push(root);
	while(!s1.empty() or !s2.empty()) {
		if(check == 0) {
			while(!s1.empty()) {
				if(s1.top() -> left != NULL) {
					s2.push(s1.top() -> left);
				}
				if(s1.top() -> right != NULL) {
					s2.push(s1.top() -> right);
				}
				result.push_back(s1.top() -> data);
				s1.pop(); 
			}
			check = 1;
		}
		if(check == 1) {
			while(!s2.empty()) {
				if(s2.top() -> right != NULL) {
					s1.push(s2.top() -> right);
				}
				if(s2.top() -> left != NULL) {
					s1.push(s2.top() -> left);
				}
				result.push_back(s2.top() -> data);
				s2.pop();
			}
			check = 0;
		}
	}
	return result;
}

int main() {
	struct node* root = new node(1);
	root -> left = new node(2);
	root -> right = new node(3);
	root -> left -> left = new node(4);
	root -> right -> left = new node(5);
	root -> right -> right = new node(6);
	root -> right -> left -> left = new node(7);
	root -> right -> left -> right = new node(8);
	vector<int> result = zigZagTraversal(root);
	for(int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	return 0;
}