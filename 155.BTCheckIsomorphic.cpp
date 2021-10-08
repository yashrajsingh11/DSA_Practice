// Approach : We will recursively check if the tree formed by each node is isomorphic or not. There can be 3 cases for the root elements
// in the recursion, either they can both be NULL in which case they will be isomorphic, or either one of them can be NULL which will
// make them non-isomorphic, or they can both be not NULL in that case if their data is not same then they are non-isomorphic. Now if the
// data is same then, call the function recursively for all these possibilities and apply boolean logic as written: left of root1 is 
// same as right of root2 and right of root1 is same as left of root2 or left of root1 is same as left of root2 and right of root1 is 
// same as right of root2. 

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

bool isIsomorphic(struct node *root1, struct node *root2) {
    if(root1 == NULL and root2 == NULL) {
        return true;
    }
    if(root1 == NULL or root2 == NULL) {
        return false;
    }
    if(root1 -> data != root2 -> data) {
        return false;
    }
    return (isIsomorphic(root1 -> left, root2 -> left) and isIsomorphic(root1 -> right, root2 -> right)) || 
            (isIsomorphic(root1 -> right, root2 -> left) and isIsomorphic(root1 -> left, root2 -> right));
}

int main() {
    struct node* root1 = new node(1);
    struct node* root2 = new node(1);

    root1 -> left = new node(2);
    root1 -> left -> left = new node(4);
    root1 -> left -> right = new node(5);
    root1 -> left -> right -> left = new node(7);
    root1 -> left -> right -> right = new node(8);
    root1 -> right = new node(3);
    root1 -> right -> left = new node(6);

    root2 -> right = new node(2);
    root2 -> right -> left = new node(4);
    root2 -> right -> right = new node(5);
    root2 -> right -> right -> right = new node(7);
    root2 -> right -> right -> left = new node(8);
    root2 -> left = new node(3);
    root2 -> left -> right = new node(6);
    cout << isIsomorphic(root1, root2);
    return 0;
}