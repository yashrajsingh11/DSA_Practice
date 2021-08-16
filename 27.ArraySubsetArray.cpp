// Approach : Enter elements of a1 in a set and check if all elements of a2 are in the set or not.

#include <iostream>

using namespace std;

string isSubset(int a1[], int a2[], int n, int m) {
    int hashmap[100000] = {0};

    for(int i = 0; i < n; i++) {
    	hashmap[a1[i]] = 1;
    }

    for(int i = 0; i < m; i++) {
    	if(hashmap[a2[i]] == 0) {
    		return "No";
    	}
    }
    return "Yes";
}

int main() {
	int a1[] = {3231, 53858, 19, 5, 59, 498, 520, 7, 9, 10, 11, 12};
	int a2[] = {520, 7, 498, 59, 10, 6, 12};
	int n = sizeof(a1)/sizeof(a1[0]);
	int m = sizeof(a2)/sizeof(a2[0]);
	cout << isSubset(a1, a2, n, m);
	return 0;
}