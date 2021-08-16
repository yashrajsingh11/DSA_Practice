// First store the array in an unordered map according to their value
// For ith eleement in array find frequency [k-i]th element in the hashmap 
// If ith value is n/2 then first decrement then evaluate else first evaluate then decrement

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int getPairsCount(int a[], int n, int sum) {
	
	unordered_map<int, int> b;
	int count = 0;

    for (int i = 0; i < n; i++) {
        b[a[i]]++;
    }

    for(int i = 0; i < n; i++) {
    	if(sum - a[i] == a[i]) {
    		b[a[i]]--;
    		count = count + b[sum - a[i]];
    	}
    	else {
	    	count = count + b[sum - a[i]];
    		b[a[i]]--;
    	}
    }

    return count;
}

int main() {
	int a[] = {3, 3, 3, 3, 1, 5, 7, 1, 5};
	int k = 6;
	int n = sizeof(a)/sizeof(a[0]);
	cout << getPairsCount(a, n, k);
	return 0;
}