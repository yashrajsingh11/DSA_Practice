// Approach 1: Store the inorder traversal of the BST in a set and all the leaf nodes in a set. Now for every leaf node which is not 1
// check if +1 and -1 values exist in BST, if true then its a dead end, if leaf node is one check if +1 exist if true then its a dead end.

// Approach 2 : Give the recursion the max-min values that can be part of the subtree, when we reach the leaf node, if their difference
// is 1 that means it is a deadend.

// ------->>> Appraoch 1 <<<----------

// #include <iostream>
// #include <set>

// using namespace std;

// struct node{
// 	int data;
// 	struct node* left;
// 	struct node* right;

// 	node(int x) {
// 		data = x;
// 		left = NULL;
// 		right = NULL;
// 	}
// };

// void inorder(node* root, set<int> &values, set<int> &leaves) {
//     if(root == NULL) {
//         return;
//     }
//     if(root -> left == NULL and root -> right == NULL) {
//         leaves.insert(root -> data);
//     }
//     inorder(root -> left, values, leaves);
//     values.insert(root -> data);
//     inorder(root -> right, values, leaves);
// }

// bool isDeadEnd(node *root) {
//     set<int> values;
//     set<int> leaves;
//     inorder(root, values, leaves);
//     for(auto it = leaves.begin(); it != leaves.end(); it++) {
//         if(*it == 1 and values.find(*it + 1) != values.end()) {
//             return true;
//         }
//         if(values.find(*it + 1) != values.end() and values.find(*it - 1) != values.end()) {
//             return true;
//         }
//     }
//     return false;
// }

// int main() {
// 	struct node* root = new node(8);
// 	root -> left = new node(5);
// 	root -> left -> left = new node(2);//4
// 	root -> left -> left -> left = new node(1);//2
// 	root -> left -> right = new node(7);
// 	root -> right = new node(9);
// 	cout << isDeadEnd(root);
// }

// ------->>> Appraoch 2 <<<----------

#include <iostream>
#include <climits>

using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;

    node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

bool isDeadEnd(node* root, int min, int max) {
    if(root == NULL) {
        return false;
    }
    if(root -> left != NULL or root -> right != NULL) {
        bool l = isDeadEnd(root -> left, min, root -> data - 1);
        bool r = isDeadEnd(root -> right, root -> data + 1, max);
        return l || r;
    }
    if(max - min > 0) {
        return false;
    }
    return true;
}

int main() {
    struct node* root = new node(8);
    root -> left = new node(5);
    root -> left -> left = new node(2);//4
    root -> left -> left -> left = new node(1);//2
    root -> left -> right = new node(7);
    root -> right = new node(9);
    cout << isDeadEnd(root, 1, INT_MAX);
}