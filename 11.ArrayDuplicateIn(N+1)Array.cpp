// Constraints : Cannot modify array and require constant extra space
// Approach 1 : Find a number such that the count of numbers less than or equal to it is greater than the number itself
// Approach 2 : Floyd's Tortoise and Hare Algorithm "faster"  

// ---------------->> Approach 1 <<-------------------- 

#include <iostream>

using namespace std;

int findDuplicate(vector<int>& nums) {

}

int main() {
	int nums = {1, 3, 4, 2, 2};
	int n = sizeof(nums)/sizeof(nums[0]);
	cout << findDuplicate(nums, n);
	return 0;
}

// ---------------->> Approach 2 <<--------------------