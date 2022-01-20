// Approach : Find the majority element using Moore's voting algorithm then count if the majority element is greater than n/2.

#include <iostream>

using namespace std;

int majorityElement(int a[], int size) {
    int majority_index = 0;
    int count = 1;
    for(int i = 1; i < size; i++) {
        if(a[i] == a[majority_index]) {
            count++;
        }
        else {
            count--;
        }
        if(count == 0) {
            majority_index = i;
            count = 1;
        }
    }
    int majority = a[majority_index];
    int n = 0;
    for(int i = 0; i < size; i++) {
        if(a[i] == majority) {
            n++;
        }
    }
    if(n > size / 2) {
        return majority;
    }
    return -1;
}

int main() {
    int arr[] = {3, 1, 1, 1, 1, 3, 2, 3, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << majorityElement(arr, size);
    return 0;
}