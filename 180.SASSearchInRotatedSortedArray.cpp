// Approach : We find the index of the minimum element in the array, now the two subarrays from 0 to minIndex - 1 and minIndex to n - 1
// are sorted so we apply BS. We can check which subarray can have the element and apply BS on that. 
// How to get minimum element: We start with a low and a high and calculate mid, now for both the subarray with mid inclusive the subarray
// which is not sorted has the smallest element and the neighbouring elements of the smallest element are always larger than it.
// Note-To-Self: See notes for detailed examples.

#include <iostream>
#include <vector>

using namespace std;

int getMinIndex(vector<int> &nums, int n) {
    int low = 0, high = n - 1;
    while(low <= high) {
        if(nums[low] <= nums[high]) {
        return low;
        }
        int mid = low + (high - low) / 2;
        int prev = (mid + n - 1) % n;
        int next = (mid + 1) % n;
        if(nums[mid] < nums[prev] and nums[mid] < nums[next]) {
            return mid;
        }
        if(nums[low] > nums[mid]) {
            high = mid - 1;
        }
        else if(nums[high] < nums[mid]) {
            low = mid + 1;
        }
    }
    return -1;
}

int bSearch(vector<int> &nums, int target, int low, int high) {
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(nums[mid] == target) {
            return mid;
        }
        if(nums[mid] < target) {
            low = mid + 1;
        }
        else if(nums[mid] > target) {
            high = mid - 1;
        }
    }
    return -1;
}

int search(vector<int> &nums, int target) {
    int n = nums.size();
    int low = 0, high = n - 1;
    int minIndex = getMinIndex(nums, n);
    if(minIndex == 0) {
        return bSearch(nums, target, low, high);
    }
    if(target >= nums[low]) {
        return bSearch(nums, target, low, minIndex - 1);
    }
    if(target <= nums[high]) {
        return bSearch(nums, target, minIndex, high);
    }
    return -1;
}

int main() {
	vector<int> nums = {3, 4, 5, 6, 7, 8, 9, 0, 1, 2};
	int target = 0;
	cout << search(nums, target);
	return 0;
}