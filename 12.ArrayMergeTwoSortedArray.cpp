// Approach 1 : Compare first element of b with ith element of a, swap accordingly and quick sort b until the end of a is reached.
// Approach 2 : Apply logic such that each element is in the correct array then sort both the array O((n + m)log(n + m)) "faster"
// ***** Time exceeding while using my own quicksort in approach 2 but not while using inbuilt sort. 

// ---------------->> Approach 2 <<--------------------

#include <algorithm>

void merge(int a[], int b[], int n, int m) {
	int i = 0, j = 0, k = n - 1;
	while(i <= k and j < m) {
		if(a[i] < b[j]) {
			i++;
		} 
    	else {
			int temp = b[j];
			b[j] = a[k];
			a[k] = temp;
			k--;
			j++;
		}
	}
	sort(a, a + n);
	sort(b, b + m);
}