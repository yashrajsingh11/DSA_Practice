// Approach 1 : Find a number such that the count of numbers less than or equal to it is greater than the number itself
// Approach 2 : Floyd's Tortoise and Hare Algorithm "faster"  

// ---------------->> Approach 2 <<-------------------- 

#include <bits/stdc++.h>

using namespace std;

int findDuplicate(vector<int>& nums) {
	int slow = nums[0];
	int fast = nums[0];
	
	do {
		slow = nums[slow];
		fast = nums[nums[fast]];
	} while (slow != fast);

	slow = nums[0];
	while(slow != fast) {
		slow = nums[slow];
		fast = nums[fast];
	}
	return slow;

}

int main() {
	vector<int>nums = {1, 3, 4, 3, 2};
	cout << findDuplicate(nums);
	return 0;
}