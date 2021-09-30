// Approach : We maintain a variable maxHeight thorughout the recursion and update level in recursion, whenever level is larger than 
// maxHeight it means we have encountered our first node in the deepest level till now so we add it to the array representing left view.
// We first traverse the left subtree then the right subtree.

#include <iostream>
#include <vector>

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

void calcLeftView(struct node* root, vector<int> &result, int &maxLevel, int level) {
	if(root == NULL) {
		return;
	}
	level++;
	if(maxLevel < level) {
		result.push_back(root -> data);
		maxLevel = level;
	}
	calcLeftView(root -> left, result, maxLevel, level);
	calcLeftView(root -> right, result, maxLevel, level);
}

vector<int> leftView(struct node *root) {
    vector<int> result;
    if(root == NULL) {
    	return result;
    }
    int maxLevel = 0;
    calcLeftView(root, result, maxLevel, 0);
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
	vector<int> result = leftView(root);
	for(int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	return 0;
}