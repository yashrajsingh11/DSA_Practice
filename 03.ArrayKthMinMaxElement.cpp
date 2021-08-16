// Approach 1: Using QuickSort to sort the array and displaying the required index
// Approach 2: Incorporating the value of k into the quicksort algorithm to sort only the indices where k can be present("faster")
// ***** Time exceeding while using my own quicksort in approach 2 hence used approach 1 with inbuilt sort in the competition

// ---------------->> Approach 1 <<--------------------

// int partition(int arr[], int lb, int ub) {
    
//     int pivot = arr[ub];
//     int low = lb - 1;

//     for(int j = lb; j < ub; j++) {
//         if(pivot > arr[j]) {
//             low++;
//             int temp = arr[low];
//             arr[low] = arr[j];
//             arr[j] = temp;
//         }
//     }
    
//     int temp = arr[ub];
//     arr[ub] = arr[low + 1];
//     arr[low + 1] = temp;
//     return low + 1;
// }

// int * QuickSort(int arr[], int lb, int ub) {
//     if(lb < ub) {
//         int loc = partition(arr, lb, ub);
//         QuickSort(arr, lb, loc - 1);
//         QuickSort(arr, loc + 1, ub);
//     }
//     return arr;
// }

// int kthSmallest(int arr[], int l, int r, int k)
//     {
//         arr = QuickSort(arr, l, r);
//         return arr[k - 1];
//     }

// ---------------->> Approach 2 <<--------------------

#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
    
int partition(int arr[], int lb, int ub) {
    
    int pivot = arr[ub];
    int low = lb - 1;

    for(int j = lb; j < ub; j++) {
        if(pivot > arr[j]) {
            low++;
            swap(arr[low], arr[j]);
        }
    }
        
    swap(arr[ub], arr[low + 1]);
    return low + 1;
}

int kthSmallest(int arr[], int l, int r, int k) {
    int loc = partition(arr, l, r);
    if(loc > k - 1) {
        return kthSmallest(arr, l, loc - 1, k);
    }
    if(loc < k - 1) {
        return kthSmallest(arr, loc + 1, r, k);
    }
    if(loc == k - 1) {
        return arr[loc];
    }
    return arr[loc];
}

int main() {
	int arr[] = { 7, 10, 4, 20, 15 };
    int n = sizeof(arr)/sizeof(arr[0]);
	cout << kthSmallest(arr, 0, n - 1, 4) << endl;
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
	return 0;
}