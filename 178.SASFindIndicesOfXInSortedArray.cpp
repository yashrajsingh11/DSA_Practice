// Approach : Use binary search to find the value in the sorted list. Linearly traverse to find the first and last occurence of the value.

#include <iostream>
#include <vector>

using namespace std;

int bsearch(int arr[], int low, int high, int x) {
    if(low > high) {
        return -1;
    }
    int mid = (low + high) / 2;
    if(arr[mid] == x) {
        return mid;
    }
    if(arr[mid] > x) {
        return bsearch(arr, low, mid - 1, x);
    }
    else {
        return bsearch(arr, mid + 1, high, x);
    }
} 

vector<int> find(int arr[], int n , int x) {
    int index = bsearch(arr, 0, n - 1, x);
    vector<int> result;
    if(index == -1) {
        result.push_back(-1);
        result.push_back(-1);
        return result;
    }
    int i = index;
    int j = index;
    while(j >= 0 and arr[j] == x) {
        j--;
    }
    result.push_back(j + 1);
    while(i < n and arr[i] == x) {
        i++;
    }
    result.push_back(i - 1);
    return result;
}

int main() {
	int arr[] = {1, 3, 5, 5, 5, 5, 67, 123, 125};
	int n = sizeof(arr)/sizeof(arr[0]);
	int x = 5;
	vector<int> result = find(arr, n, x);
	cout << result[0] << " " << result[1];
    return 0;
}