// Approach : We recursively calculate sum of left and right subtree(return 0 if null). Then if current node is not leaf node we check
// if sum equal to current node if true then return the sum tree value(total sum + current node value) to the upper node. If not true
// then maintain a boolean and turn it false, and if it is false we do not perform anything inside the recursion.

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

int isSum(node* root, bool &check) {
    if(check == false) {
        return 0;
    }
    if(root == NULL) {
        return 0;
    }
    int lsum = isSum(root -> left, check);
    int rsum = isSum(root -> right, check);
    if(root -> left != NULL or root -> right != NULL){
        if(root -> data != lsum + rsum) {
            check = false;
        }
    }
    return lsum + rsum + root -> data;
}

bool isSumTree(node* root) {
    bool check = true;
    isSum(root, check);
    return check;
}

int main() {
	struct node* root = new node(70);
	root -> left = new node(20);
	root -> right = new node(30);
	root -> left -> left = new node(10);
	root -> left -> right = new node(10);
	cout << isSumTree(root);
	return 0;
}