// Approach : We create two arrays which keeps the product of the left part and right part for each element. Basically the arrays store
// the product of all previous elements for ith element in left and product of all next elements for ith element in right. Now product
// of ith element is left[i - 1] * right[i + 1];

#include <iostream>
#include <vector>

using namespace std;

vector<long long int> productExceptSelf(vector<long long int> &nums, int n) {
    long long int left[n];
    long long int leftProduct = 1;
    for(int i = 0; i < n; i++) {
        leftProduct = leftProduct * nums[i];
        left[i] = leftProduct;
    }
    long long int right[n];
    long long int rightProduct = 1;
    for(int i = n - 1; i >= 0; i--) {
        rightProduct = rightProduct * nums[i];
        right[i] = rightProduct;
    }
    if(n == 1) {
        nums[0] = 1;
        return nums;
    }
    if(n == 2) {
        long long int temp = nums[0];
        nums[0] = nums[1];
        nums[1] = temp;
        return nums;
    }
    nums[0] = right[1];
    nums[n - 1] = left[n - 2];
    for(int i = 1; i < n - 1; i++) {
        nums[i] = left[i - 1] * right[i + 1];
    }
    return nums;
}