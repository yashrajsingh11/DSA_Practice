// Approach : We recursively traverse the tree until one of the nodes is found. Then we stop the recursion from going further in the 
// subtree where the node is found and we traverse the remaining tree. When the other node is found we return its root upward in the 
// recursion until we reach the node where we found the first node. Here the if condition checking whether the left or the right node
// is null or not is veru crucial. When a node is found in any left node then we check the right node of the parent of left node, if
// the other node is not in the right subtree, then information is passed one step upwards in the tree. This is important while finding 
// the second node, while finding the common node of the second and first node after both are found and in the case where one of the nodes
// itself is the LCA since it will be returned at the end in this case as both have to be present.

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

struct node* lca(struct node* root ,int n1 ,int n2 ) {
    if(root == NULL) {
        return NULL;
    }
    if(root -> data == n1 or root ->data == n2) {
        return root;
    }
    struct node* left = lca(root -> left, n1, n2);
    struct node* right = lca(root -> right, n1, n2);
    if(left != NULL and right != NULL) {
        return root;
    }
    if(left != NULL) {
        return left;
    }
    return right;
}

int main() {
	struct node* root = new node(1);
	root -> left = new node(2);
	root -> right = new node(3);
	root -> left -> left = new node(4);
	root -> left -> right = new node(5);
	root -> right -> left = new node(6);
	root -> right -> right = new node(7);
	cout << lca(root, 1, 2) -> data;
	return 0;
}
      