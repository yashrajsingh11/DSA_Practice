// Approach : We maintain two queues one keeps track of the nodes in level order traversal other keeps track of their distance from the
// centre in level order traversal. For each node if its left has distance from centre greatest negative till now we push_front it to 
// a list. If its right has distance from centre greatest till now we push_back it to a list. We also push the left and right to the 
// node queue and their distance from centre in distance queue. 

#include <iostream>
#include <vector>
#include <list>
#include <queue>

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

vector<int> topView(struct node* root) {
	vector<int> result;
	list<int> output;
	queue<struct node*> q1;
	queue<int> q2;
	if(root == NULL) {
		return result;
	}
	output.push_back(root -> data);
	q1.push(root);
	q2.push(0);
	int left = 0;
	int right = 0;
	while(!q1.empty()) {
		int temp = q2.front();
		if(q1.front() -> left != NULL) {
			if(temp - 1 < left) {
				output.push_front(q1.front() -> left -> data);
				left = temp - 1;
			} 
			q1.push(q1.front() -> left);
			q2.push(temp - 1);
		}
		if(q1.front() -> right != NULL) {
			if(temp + 1 > right) {
				output.push_back(q1.front() -> right -> data);
				right = temp + 1;
			} 
			q1.push(q1.front() -> right);
			q2.push(temp + 1);
		}
		q1.pop();
		q2.pop();
	}
	for(auto it = output.begin(); it != output.end(); it++) {
		result.push_back(*it);
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
	root -> right -> left -> right -> right = new node(9);
	root -> right -> left -> right -> right -> right = new node(10);
	vector<int> result = topView(root);
	for(int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	return 0;
}