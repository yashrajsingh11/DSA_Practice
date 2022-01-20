// Approach : 
    int postOrder(Node* root) {
        if(root == NULL) {
            return 0;
        }
        int l = postOrder(root -> left);
        int r = postOrder(root -> right);
        if((l == 0 or root -> left -> data < root -> data) and (r == 0 or root -> right -> data > root -> data)) {
            return l + r + 1;
        }
        return max(l, r);
    }
    
    int largestBst(Node *root) {
        return postOrder(root);
    }