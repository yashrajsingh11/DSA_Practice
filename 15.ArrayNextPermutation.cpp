// Approach : Find the rightmost element which needs to be swapped to get the next lexicographically bigger number
// Find the next largest number to the right of this number and swap that number now that number is at its correct index
// Reverse the rest of the numbers in the right.

#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void reverse(vector<int> &nums, int start, int end) {
	while(start < end) {
		int temp = nums[start];
		nums[start] = nums[end];
		nums[end] = temp;
		start++;
		end--;
	}
}

void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while(i >= 0 and nums[i + 1] <= nums[i]) {
        	i--;
        }
        if(i >= 0) {
        	int j = nums.size() - 1;
        	while(nums[j] <= nums[i]) {
        		j--;
        	}
        	swap(nums[i], nums[j]);
        }
        reverse(nums, i + 1, nums.size() - 1);
}

int main() {
	vector<int> nums {
		3, 1, 7, 5
	};
	nextPermutation(nums);
	for(int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
	return  0;
}