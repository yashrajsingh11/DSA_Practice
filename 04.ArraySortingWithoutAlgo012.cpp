// Approach 1: Counting number of 0, 1, 2 and changing the array accordingly
// Approach 2: Partition the array into groups of 0 1 and 2 "faster"

// ---------------->> Approach 1 <<--------------------

// void sort012(int a[], int n)
// {
//     int zeros = 0;
//     int ones = 0;
//     int twos = 0;
//     for(int i = 0; i < n; i++) {
//         if (a[i] == 0) {
//             zeros++;
//         } 
//         else if (a[i] == 1) {
//             ones++;
//         }
//         else {
//             twos++;
//         }
//     }
    
//     for(int j = 0; j < zeros; j++) {
//         a[j] = 0;
//     }
//     for(int i = zeros; i < zeros + ones; i++) {
//         a[i] = 1;
//     }
//     for(int i = zeros + ones; i < zeros + ones + twos; i++) {
//         a[i] = 2;
//     }
// }

// ---------------->> Approach 2 <<--------------------

// void sort012(int a[], int n) {
//     int low = 0;
//     int mid = 0;
//     int high = n-1;
    
//     while(mid <= high) {
//         if(a[mid] == 0) {
//             int temp = a[mid];
//             a[mid] = a[low];
//             a[low] = temp;
//             low++;
//             mid++;
//         }
//         else if(a[mid] == 1) {
//             mid++;
//         }
//         else {
//             int temp = a[mid];
//             a[mid] = a[high];
//             a[high] = temp;
//             high--;
//         }
//     }
// }

#include <iostream>

using namespace std;

void print(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

void simpleSort(int arr[], int n) {
    int low = 0;
    int mid = 0;
    int high = n - 1;
    while(mid < high) {
        if(arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1) {
            mid++;
        }
        else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main() {
    int arr[] = {1, 1, 2, 2, 1, 0, 0, 1, 0, 2, 1, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    simpleSort(arr, n);
    print(arr, n);
    return 0;
}