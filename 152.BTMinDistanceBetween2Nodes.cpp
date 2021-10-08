// Approach : We find the LCA of the two given nodes. Then we find the distance between the LCA and those two nodes and sum it. 

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

struct node* findLCA(struct node* root, int a, int b) {
    if(root == NULL) {
        return NULL;
    }
    if(root -> data == a or root -> data == b) {
        return root;
    }
    struct node* lNode = findLCA(root -> left, a, b);
    struct node* rNode = findLCA(root -> right, a, b);
    if(lNode != NULL and rNode != NULL) {
        return root;
    }
    if(lNode != NULL) {
        return lNode;
    }
    return rNode;
}

int distance(struct node* root, int d, int n) {
    if(root == NULL) {
        return 0;
    }
    if(root -> data == n) {
        return d;
    }
    int ld = distance(root -> left, d + 1, n);
    int rd = distance(root -> right, d + 1, n);
    return max(ld, rd);
}

int findDist(struct node* root, int a, int b) {
    struct node* lca = findLCA(root, a, b);
    int aDistance = distance(lca, 0, a);
    int bDistance = distance(lca, 0, b);
    return aDistance + bDistance;
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
	cout << findDist(root, 4, 8);
	return 0;
}