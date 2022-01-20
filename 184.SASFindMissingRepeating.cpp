// Approach : Traverse the arra and taking the value of each element as index, make the value present at that index negative. If we find
// a negative value that means it has been traversed, so that index is repeating. Now only the value at the missing index will be positive
// so we search for positive element in the array.

#include <iostream>

using namespace std;

int* findTwoElement(int* arr, int n) {
    static int output[2] = {0, 0};
    for(int i = 0; i < n; i++) {
        if(arr[abs(arr[i]) - 1] < 0) {
            output[0] = abs(arr[i]);
        }
        else {
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        }
    }
    for(int i = 0; i < n; i++) {
        if(arr[i] > 0) {
            output[1] = i + 1;
        }
    }
    return output;
}

int main() {
    int arr[] = {7, 5, 2, 3, 1, 2, 6, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int* result = findTwoElement(arr, n);
    cout << result[0] << " " << result[1];
}