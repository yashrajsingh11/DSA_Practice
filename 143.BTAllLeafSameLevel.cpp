// Approach : 

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

int checkHeight(struct node* root, int height, int &maxheight, bool &check) {
    if(check == false) {
        return 0;
    }
    if(root == NULL) {
        return height;
    }
    int lheight = checkHeight(root -> left, height + 1, maxheight, check);
    int rheight = checkHeight(root -> right, height + 1, maxheight, check);
    if(root -> left == NULL and root -> right == NULL) {
        if(maxheight == 0) {
            maxheight = height;
        }
        else {
            if(maxheight != height) {
                check = false;
            }
        }
    }
    return 1 + max(lheight, rheight);
}

bool check(struct node *root) {
    int maxheight = 0;
    bool check = true;
    checkHeight(root, 0, maxheight, check);
    return check;
}

int main() {
	struct node* root = new node(1);
	root -> left = new node(2);
	root -> right = new node(3);
	root -> left -> left = new node(4);
	root -> right -> right = new node(6);
	root -> left -> left -> left = new node(7);
	root -> right -> right -> right = new node(8);
	cout << check(root);
	return 0;
}