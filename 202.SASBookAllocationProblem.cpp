// Approach : Check Notes.

#include <iostream>
#include <climits>

using namespace std;

bool isValid(int* A, int N, int M, int mid) {
    int student = 1;
    int sum = 0;
    for(int i = 0; i < N; i++) {
        sum = sum + A[i];
        if(sum > mid) {
            student++;
            sum = A[i];
        }
    }
    if(student > M) {
        return false;
    }
    return true;
}

int findPages(int A[], int N, int M) {
    int low = INT_MIN;
    int high = 0;
    for(int i = 0; i < N; i++) {
        low = max(low, A[i]);
        high = high + A[i];
    }
    int result = -1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(isValid(A, N, M, mid) == true) {
            result = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return result;
}

int main() {
	int n = 4;
	int A[] = {12, 34, 67, 90};
	int m = 2;
	cout << findPages(A, n, m);
	return 0;
}