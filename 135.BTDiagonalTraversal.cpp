// Approach : Using a tree map(which stores the values in sorted order in logn time) of integer diagonal height and vector of all elements
// at that height. We first traverse the tree to left while keep adding 1 to each recursion, then we traverse right without adding, 
// since all elements on right are on the same diagonal height. We also keep adding the nodes data to the vector at the current dheight.

#include <iostream>
#include <vector>
#include <map>

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

void traverse(struct node* root, map<int, vector<int>> &m, int dheight) {
	if(root == NULL) {
		return;
	}
	m[dheight].push_back(root -> data);
	traverse(root -> left, m, dheight + 1);
	traverse(root -> right, m, dheight);
}

vector<int> diagonalTraversal(struct node* root) {
	vector<int> result;
	if(root == NULL) {
		return result;
	}
	map<int, vector<int>> m;
	traverse(root, m, 0);
	
	for(auto it = m.begin(); it != m.end(); it++) {
		vector<int> temp = it -> second;
		for(int i = 0; i < temp.size(); i++) {
			result.push_back(temp[i]);
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
	vector<int> result = diagonalTraversal(root);
	for(int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	return 0;
}