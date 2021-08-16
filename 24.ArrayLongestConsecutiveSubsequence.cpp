// Approach : Store all elements in hash and now check the longest consecutive sequence in the hashmap

#include <iostream>

using namespace std;

int findLongestConseqSubseq(int arr[], int N) {
	
	int result = 0, count = 0;
	int hashmap[100001] = {0};
	
	for(int i = 0; i < N; i++) {
		hashmap[arr[i]] = 1;
	}

	for(int i = 0; i < 100001; i++) {
		if(hashmap[i] == 1) {
			count = count + 1;
		}
		else if(hashmap[i] == 0) {
			if(count > result) {
				result = count;
			}
			count = 0;
		}
	}

	if(count > result) {
		result = count;
	}

	return result;
}

int main() {
	int a[] = {0, 1, 2, 3, 5, 6, 7, 8, 9};
	int n = sizeof(a)/sizeof(a[0]);
	cout << findLongestConseqSubseq(a, n);
	return 0;
}