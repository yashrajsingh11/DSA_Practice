// Approach 1 : We have a recursive function which takes the node of root tree and mirror as input and traverses mirror tree to left when 
// root tree goes to right and vice-versa;
// Approach 2 : Simply swap the left and right of a node if it has any one of those.


// ----->>> Approach 1 <<<------

#include <iostream>

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

void inorder(struct node* root) {
	if(root == NULL) {
		return;
	}
	inorder(root -> left);
	cout << root -> data << " ";
	inorder(root -> right);
}

void mirrorify(struct node* root, struct node** mirror) {
	if(root == NULL) {
		return;
	}
	*mirror = new node(root -> data);
	mirrorify(root -> left, &((*mirror) -> right));
	mirrorify(root -> right, &((*mirror) -> left));
}

int main() {
	struct node* root = new node(5);
	root -> left = new node(6);
	root -> right = new node(3);
	root -> right -> left = new node(4);
	root -> right -> right = new node(2);
	struct node* mirror = NULL;
	mirrorify(root, &mirror);
	inorder(root);
	cout << endl;
	inorder(mirror);
	return 0;
}

// ----->>> Approach 2 <<<------

// #include <iostream>

// using namespace std;

// struct node {
// 	int data;
// 	struct node* left;
// 	struct node* right;

// 	node(int x) {
// 		data = x;
// 		left = NULL;
// 		right = NULL;
// 	}
// };

// void inorder(struct node* root) {
// 	if(root == NULL) {
// 		return;
// 	}
// 	inorder(root -> left);
// 	cout << root -> data << " ";
// 	inorder(root -> right);
// }

// void mirrorify(struct node* root) {
// 	if(root == NULL) {
// 		return;
// 	}
// 	struct node* temp = root -> left;
// 	root -> left = root -> right;
// 	root -> right = temp;
// 	mirrorify(root -> left);
// 	mirrorify(root -> right);
// }

// int main() {
// 	struct node* root = new node(1);
// 	root -> left = new node(2);
// 	root -> right = new node(3);
// 	root -> left -> right = new node(4);
// 	root -> right -> right = new node(5);
// 	struct node* mirror = NULL;
// 	inorder(root);
// 	cout << endl;
// 	mirrorify(root);
// 	inorder(root);
// 	return 0;
// }