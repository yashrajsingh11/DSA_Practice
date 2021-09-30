// Approach : We use a map which stores the latest values found for a certain key, where key is the distance of the node from the centre.
// We perform level order traversal and update the values in map according to the key of the current node. At the end the map has all
// the nodes which belong to the bottom view. The map keeps the key in sorted order so it is faster to update keys.

#include <iostream>
#include <vector>
#include <queue>
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

vector<int> bottomView(struct node* root) {
	vector<int> result;
	map<int, int> m;
	queue<struct node*> q1;
	queue<int> q2;
	if(root == NULL) {
		return result;
	}
	m[0] = root -> data;
	q1.push(root);
	q2.push(0);

	while(!q1.empty()) {
		int temp = q2.front();
		if(q1.front() -> left != NULL) {
			m[temp - 1] = q1.front() -> left -> data; 
			q1.push(q1.front() -> left);
			q2.push(temp - 1);
		}
		if(q1.front() -> right != NULL) {
			m[temp + 1] = q1.front() -> right -> data; 
			q1.push(q1.front() -> right);
			q2.push(temp + 1);
		}
		q1.pop();
		q2.pop();
	}
	for(auto it = m.begin(); it != m.end(); it++) {
		result.push_back(it -> second);
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
	vector<int> result = bottomView(root);
	for(int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	return 0;
}