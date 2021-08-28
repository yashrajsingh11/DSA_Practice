// Approach : Use two pointers high and low and swap values accordingly

#include <bits/stdc++.h>

using namespace std;

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void threeWayPartition(vector<int>& array, int a, int b) {
	int low = 0, mid = 0, high = array.size() - 1;
	while(mid <= high) {
		
		if(array[mid] > b) {
			swap(array[mid], array[high]);
			high--;
		}
		
		else if(array[mid] < a) {
			swap(array[mid], array[low]);
			low++;
			mid++;
		}
		
		else {
			mid++;
		}
	}
}

int main() {
	vector<int> array = {87, 78, 16, 94};
	int a = 36;
	int b = 72;

	threeWayPartition(array, a, b);

	for(int i = 0; i < array.size(); i++) {
		cout << array[i] << " ";
	}

	return 0;
}