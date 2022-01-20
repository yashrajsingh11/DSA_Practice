// Approach : Convert the characters and their frequencies into nodes and store them in a minheap so that the node with the minimum 
// frequency is always at the top of the heap. While there are two or more elements in the heap get the top two elements from the heap
// and create a new node with frequency as the sum of the frequencies of the two elements and empty character. Make the smaller of the 
// two as the left of this node and the other as the right of this node. Push this node in the minheap. At the end we will have our
// huffman tree and only one element in the minheap which is the root node. Now pre-order traverse the tree while maintaining a string 
// which appends 0 if we go to left and appends 1 if we go to right. Now for any node that does not have an empty character we save
// the string as the huffman code for that node's character.

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct node {
    int frequency;
    char letter;
    struct node* left;
    struct node* right;
    
    node(int x) {
        frequency = x;
        letter = ' ';
        left = NULL;
        right = NULL;
    }
};
	
struct compare_nodes {
    bool operator()(struct node* a, struct node* b) {
        return a -> frequency > b -> frequency;    
    }
};
	
void getResult(struct node* root, string output, vector<string> &result) {
    if(root == NULL) {
        return;
    }
    if(root -> letter != ' ') {
        result.push_back(output);
    }
    getResult(root -> left, output + '0', result);
    getResult(root -> right, output + '1', result);
}
	
vector<string> huffmanCodes(string S,vector<int> f,int N) {
    priority_queue<struct node*, vector<struct node*>, compare_nodes> minHeap;
    for(int i = 0; i < N; i++) {
        struct node* temp = new node(f[i]);
        temp -> letter = S[i];
        minHeap.push(temp);
    }
    
    while(minHeap.size() > 1) {
        struct node* temp1 = minHeap.top();
        minHeap.pop();
        struct node* temp2 = minHeap.top();
        minHeap.pop();
        struct node* newTemp = new node(temp1 -> frequency + temp2 -> frequency);
        newTemp -> left = temp1;
        newTemp -> right = temp2;
        minHeap.push(newTemp);
    }
    
    struct node* root = minHeap.top();
    vector<string> result;
    string output = "";
    getResult(root, output, result);
    return result;
}

int main() {
	vector<int> f = {5, 9, 12, 13, 16, 45};
	string S = "abcdef";
	int N = 6;
	vector<string> answer = huffmanCodes(S, f, N);
	for(int i = 0; i < N; i++) {
		cout << answer[i] << " ";
	}
	return 0;
}