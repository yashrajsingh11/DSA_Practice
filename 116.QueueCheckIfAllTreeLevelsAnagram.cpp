// Approach : Create two binary trees. Use two queues to keep track of elements in each level of tree. Use two lists to store the elements
// of each level of tree. While elements are present in a level if front of queues are equal then add left and rights to queues and datas 
// to list, if unequal return false. Now check size of queues, if unequal return false. If size = 0(traversal complete) return true else
// update number of elements in a level and repeat.

#include <iostream>
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

bool areAnagrams(struct node* root1, struct node* root2) {
	if(root1 == NULL and root2 == NULL) {
		return true;
	}
	if(root1 == NULL or root2 == NULL ) {
		return false;
	}
	queue<struct node*> tree1;
	queue<struct node*> tree2;
	list<int> num1;
	list<int> num2;
	tree1.push(root1);
	tree2.push(root2);
	num1.push_back(tree1.front() -> data);
	num2.push_back(tree2.front() -> data);
	int count = 1;

	while(1) {
		if(count == 0) {
			if(num1.size() != num2.size()) {
				return false;
			}
			if(num1.size() == 0) {
				return true;
			}
			count = tree1.size();
			num1.sort();
			num2.sort();
		}
		if(num1.front() == num2.front()) {
			if(tree1.front() -> left != NULL) {
				tree1.push(tree1.front() -> left);
				num1.push_back(tree1.front() -> left -> data);
			}
			if(tree2.front() -> left != NULL) {
				tree2.push(tree2.front() -> left);
				num2.push_back(tree2.front() -> left -> data);
			}
			if(tree1.front() -> right != NULL) {
				tree1.push(tree1.front() -> right);
				num1.push_back(tree1.front() -> right -> data);
			}
			if(tree2.front() -> right != NULL) {
				tree2.push(tree2.front() -> right);
				num2.push_back(tree2.front() -> right -> data);
			}
			tree1.pop();
			tree2.pop();
			num1.pop_front();
			num2.pop_front();
			count--;
		}
		else {
			return false;
		}
	}
}

int main() {
	struct node* root1 = new node(1);
	root1 -> left = new node(2);
	root1 -> right = new node(3);
	root1 -> left -> right = new node(5);
	root1 -> left -> left = new node(4);
	struct node* root2 = new node(1);
	root2 -> left = new node(3);
	root2 -> right = new node(2);
	root2 -> left -> right = new node(5);
	root2 -> right -> left = new node(4);
	cout << areAnagrams(root1, root2);
	return 0;
}