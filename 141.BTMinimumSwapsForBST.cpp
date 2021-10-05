// Approach : Since the inorder traversal of a binary search tree is in sorted order. Hence we find the inorder traversal of the complete
// binary tree given in an array and find the minimum swaps required to sort the inorder traversal. To find the minimum swaps we create 
// a vector pair which has the previous indices of the sorted nodes. If the previous index is same as current index then the node was at
// correct position, if it is not then we swap the node and the node at its previous index, now if it is at its correct position that 
// it was swapped once, else we again swap it with the previous index node, while updating the count.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minimumSwaps(vector<int> in) {
	int result = 0;
	vector<pair<int, int>> sorted(in.size());
	for(int i = 0; i < in.size(); i++) {
		sorted[i].first = in[i];
		sorted[i].second = i;
	}
	sort(sorted.begin(), sorted.end());
	for(int i = 0; i < in.size(); i++) {
		if(sorted[i].second == i) {
			continue;
		}
		else {
			swap(sorted[i].first, sorted[sorted[i].second].first);
			swap(sorted[i].second, sorted[sorted[i].second].second);
		}
		if(sorted[i].second != i) {
			i--;
		}
		result++;
	}
	return result;
}

void traverse(int *arr, int index, vector<int> & result, int n) {
	if(index >= n) {
		return;
	}
	traverse(arr, 2 * index + 1, result, n);
	result.push_back(arr[index]);
	traverse(arr, 2 * index + 2, result, n);
}

vector<int> inorder(int arr[], int n) {
	vector<int> result;
	if(n == 0) {
		return result;
	}
	traverse(arr, 0, result, n);
	return result;
}

int main() {
	int arr[] = {5, 6, 7, 8, 9, 10, 11};
	int n = sizeof(arr)/sizeof(arr[0]);
	vector<int> in = inorder(arr, n);
	cout << minimumSwaps(in);
	return 0;
}