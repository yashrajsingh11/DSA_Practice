// Approach 1 : Perform Inorder Traversal until the kth node is found. This is the kth smallest node of the BST. Time : O(n), Space : O(n) 
// Approach 2 : Morris Traversal. Time : O(n), Space : O(1)

// -------->>> Approach 2 <<<---------

#include <iostream>

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

struct node* predecessor(struct node* root) {
    struct node* curr = root -> left;
    while(curr -> right != NULL and curr -> right != root) {
        curr = curr -> right;
    }
    return curr;
}

int KthSmallestElement(struct node *root, int K) {
    struct node* curr = root;
    struct node* result = NULL;
    while(curr != NULL) {
        if(curr -> left == NULL) {
            K--;
            if(K == 0) {
                result = curr;
                K--;
            }
            curr = curr -> right;
        }
        else {
            struct node* pred = predecessor(curr);
            if(pred -> right == NULL) {
                pred -> right = curr;
                curr = curr -> left;
            }
            else {
                pred -> right = NULL;
                K--;
                if(K == 0) {
                    result = curr;
                    K--;
                }
                curr = curr -> right;
            }
        }
    }
    if(result == NULL) {
        return -1;
    }
    return result -> data;
}

int main() {
	struct node* root = new node(8);
	root -> left = new node(4);
	root -> left -> left = new node(2);
	root -> left -> left -> left = new node(1);
	root -> left -> left -> right = new node(3);
	root -> left -> right = new node(6);
	root -> left -> right -> left = new node(5);
	root -> left -> right -> right = new node(7);
	root -> right = new node(12);
	root -> right -> left = new node(10);
	root -> right -> left -> left = new node(9);
	root -> right -> left -> right = new node(11);
	root -> right -> right = new node(14);
	root -> right -> right -> left = new node(13);
	root -> right -> right -> right = new node(15);
	cout << KthSmallestElement(root, 3);
	return 0;
}

// -------->>> Approach 1 <<<---------

// #include <iostream>

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

// void inorder(struct node* root, int &K, struct node* &result) {
//     if(root == NULL) {
//         return;
//     }
//     if(result != NULL) {
//         return;
//     }
//     inorder(root -> left, K, result);
//     K--;
//     if(K == 0) {
//         result = root;
//         K--;
//     }
//     inorder(root -> right, K, result);
// }

// int KthSmallestElement(struct node* root, int K) {
//     struct node* result = NULL;
//     inorder(root, K, result);
//     if(result == NULL) {
//         return -1;
//     }
//     return result -> data;
// }

// int main() {
// 	struct node* root = new node(8);
// 	root -> left = new node(4);
// 	root -> left -> left = new node(2);
// 	root -> left -> left -> left = new node(1);
// 	root -> left -> left -> right = new node(3);
// 	root -> left -> right = new node(6);
// 	root -> left -> right -> left = new node(5);
// 	root -> left -> right -> right = new node(7);
// 	root -> right = new node(12);
// 	root -> right -> left = new node(10);
// 	root -> right -> left -> left = new node(9);
// 	root -> right -> left -> right = new node(11);
// 	root -> right -> right = new node(14);
// 	root -> right -> right -> left = new node(13);
// 	root -> right -> right -> right = new node(15);
// 	cout << KthSmallestElement(root, 9);
// 	return 0;
// }