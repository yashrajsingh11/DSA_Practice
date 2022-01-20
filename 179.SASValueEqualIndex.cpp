// Approach : Linear search for elements with arr[i] == i + 1

#include <iostream>
#include <vector>

using namespace std;

vector<int> valueEqualToIndex(int arr[], int n) {
    vector<int> result;
    for(int i = 0; i < n; i++) {
        if(arr[i] == i + 1) {
            result.push_back(i + 1);
        }
    }
    return result;
}

int main() {
	int arr[] = {1, 3, 2, 4, 5, 7, 6};
	int n = sizeof(arr)/sizeof(arr[0]);
	vector<int> result = valueEqualToIndex(arr, n);
	for(int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	return 0;
}