// Approach : We recursively calculate the distance of each node from the root and the sum of path to reach that node, if the distance is 
// maximum we have ever seen then we check if the sum is maximum or not and update accordingly.

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

int calculate(struct node* root, int height, int &maxheight, int sum, int &maxsum) {
    if(root == NULL) {
        return height;
    }
    int lheight = calculate(root -> left, height + 1, maxheight, sum + root -> data, maxsum);
    int rheight = calculate(root -> right, height + 1, maxheight, sum + root -> data, maxsum);
    if(max(lheight, rheight) >= maxheight) {
        maxheight = max(lheight, rheight);
        if(sum + root -> data >= maxsum) {
            maxsum = sum + root -> data;
        }
    }
    return max(lheight, rheight);
}
int sumOfLongRootToLeafPath(struct node *root) {
    int maxheight = 0;
    int maxsum = 0;
    calculate(root, 0, maxheight, 0, maxsum);
    return maxsum;
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
	cout << sumOfLongRootToLeafPath(root);
	return 0;
}