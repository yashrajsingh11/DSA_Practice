// Approach : We create a new array of pairs and sort it. The pair after sorting will hold the value and the actual position of the
// value in the unsorted array. Now for each index in the array we check if the value and its unsorted index is the same, if it is then we
// require 0 swap since it is at its correct position, if it isnt then we have to swap the value with the value which is at the unsorted 
// index (thus bringing the value at its correct unsorted index) and check if the new value at the index is at its correct position by 
// applying the above logic again.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int minSwaps(vector<int> &nums) {
    int count = 0;
    pair<int, int> arr[nums.size()];
    for(int i = 0; i < nums.size(); i++) {
        arr[i].first = nums[i];
        arr[i].second = i;
    }
    sort(arr, arr + nums.size());
    int i = 0; 
    while(i < nums.size()) {
        if(nums[i] == arr[i].first) {
            i++;
            continue;
        }
        pair<int, int> temp = arr[arr[i].second];
        arr[arr[i].second] = arr[i];
        arr[i] = temp;
        count++;
    }
    return count;
}

int main() {
	vector<int> nums = {9, 3, 2, 6, 1, 7, 4, 5, 0, 8};
	cout << minSwaps(nums);
	return 0;
}