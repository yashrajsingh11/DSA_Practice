// Q) Find the pivot element(largest element) in a rotated sorted array. Also find the number of times it is rotated.

// Approach : Look for question in notes "How many times a sorted array is rotated". 
// We can find it by finding the smallest element
// array_size - index_of_smallest_element = number of times it is rotated
// 1 - index_of_smallest_element = index of largest element.
// Properties of minimum element: 
// 1) It is smaller than both its neighbours(use modulo for edge cases).
// 2)When we divide in binary search it is always present in the unsorted part.

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

int main() {
	vector<int> arr = {6, 1, 2, 3, 4, 5};
	int n = arr.size();
	int minIndex = getMinIndex(arr, n);
	cout << "Pivot : " << (minIndex + n - 1) % n << endl;
	cout << "Number of times rotated : " << (n - minIndex) % n;
}