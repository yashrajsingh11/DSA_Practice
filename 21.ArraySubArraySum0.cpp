// Approach : Tterate through the array and for every element arr[i], calculate the sum of elements from 0 to i (prefix-sum). 
// 			  If the current sum has been seen before, then there is a zero-sum array.
// intSet.find(arr[i]) == intSet.end() ka mtlb element set me nhi tha != ka mtlb element set me tha

#include <iostream>
#include <unordered_set>
using namespace std;

bool subArrayExists(int arr[], int n) {
	unordered_set<int> presum;
	int temp = 0;
	for(int i = 0; i < n; i++) {
		temp = temp + arr[i];
		if(temp == 0 || presum.find(temp) != presum.end()) {
			return true;
		}
		presum.insert(temp);
	}
	return false;
}	

int main() {

	int a[] = {4, 2, 0, 1, 6};
	int n = sizeof(a)/sizeof(a[0]);
	cout << subArrayExists(a, n);
	return 0;
}