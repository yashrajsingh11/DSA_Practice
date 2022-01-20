// Approach 1 : Use a pointer in each of the array to track the current index. Update the pointers to get elements from both array in 
// ascending order, return the kth among them. Time : O(n)
// Approach 2 : Using binary search(will look into it later).

#include <iostream>

using namespace std;

int kthElement(int arr1[], int arr2[], int n, int m, int k) {
    int i = 0, j = 0, index = 0;
    while(i < n and j < m) {
        if(arr1[i] < arr2[j]) {
            index++;
            if(k == index) {
                return arr1[i];
            }
            i++;
        }
        else {
            index++;
            if(k == index) {
                return arr2[j];
            }
            j++;
        }
    }
    while(i < n) {
        index++;
        if(k == index) {
            return arr1[i];
        }
        i++;
    }
    while(j < m) {
        index++;
        if(k == index) {
            return arr2[j];
        }
        j++;
    }
    return -1;
}

int main() {
	int arr1[] = {1, 2, 2, 3, 4, 4, 5, 6, 6};
	int arr2[] = {1, 1, 2, 3, 3, 4, 5, 5, 6, 7, 7, 8};
	int n = sizeof(arr1)/sizeof(arr1[0]);
	int m = sizeof(arr2)/sizeof(arr2[0]);
	int k = 16;
	cout << kthElement(arr1, arr2, n, m, k);
	return 0;
}