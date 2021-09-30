// Approach : While queue is not empty we take the right and left(in order) of the front element and add them to the queue. Pop the front
// element and add it to a vector. Now the vector has the output in reverse order so we reverse it and return. 

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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

vector<int> reverseLevelOrder(struct node* root) {
	queue<struct node*> nodes;
	vector<int> result;
	if(root == NULL) {
		return result;
	}
	nodes.push(root);
	while(!nodes.empty()) {
		if(nodes.front() -> right != NULL) {
			nodes.push(nodes.front() -> right);
		}
		if(nodes.front() -> left != NULL) {
			nodes.push(nodes.front() -> left);
		}
		result.push_back(nodes.front() -> data);
		nodes.pop();
	}
	reverse(result.begin(), result.end());
	return result;
}

int main() {
	struct node* root = new node(10);
	root -> left = new node(20);
	root -> right = new node(30);
	root -> left -> left = new node(40);
	root -> right -> right = new node(50);
	vector<int> result = reverseLevelOrder(root);
	for(int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
}