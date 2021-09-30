// Approach : Maintain a queue which keeps track of the elements in each level of tree. Push the root node and while the queue is not
// empty push the left and right of the front of the queue into the queue and add front into level order traversal then pop queue.

#include <iostream>
#include <vector>
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

vector<int> levelOrder(struct node* root) {
	queue<struct node*> nodes;
	vector<int> result;
	if(root == NULL) {
		return result;
	}
	nodes.push(root);
	while(!nodes.empty()) {
		if(nodes.front() -> left != NULL) {
			nodes.push(nodes.front() -> left);
		}
		if(nodes.front() -> right != NULL) {
			nodes.push(nodes.front() -> right);
		}
		result.push_back(nodes.front() -> data);
		nodes.pop();
	}
	return result;
}

int main() {
	struct node* root = new node(10);
	root -> left = new node(20);
	root -> right = new node(30);
	root -> left -> left = new node(40);
	root -> right -> right = new node(50);
	vector<int> result = levelOrder(root);
	for(int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	return 0;
}