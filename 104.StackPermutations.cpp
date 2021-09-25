// Approach : For each element of input array if it is not equal to current element of output array push it in stack. If it is equal then 
// 			while top of stack is equal to next of current of output array keep poping and updating the current pointer. If the stack
// 			is empty then it is valid stack permuatation else it is not.

#include <iostream>
#include <stack>

using namespace std;

bool checkStackPermutations(int input[], int output[], int n) {
	stack<int> s;
	int i = 0, j = 0;

	while(i < n) {
		if(input[i] != output[j]) {
			s.push(input[i]);
			i++;
		}
		else {
			j++;
			i++;
			while(s.top() == output[j]) {
				s.pop();
				if(s.empty()) {
					return true;
				}
				j++;
			}
		}
	}
	return false;
}

int main() {
	int input[] = {1, 2, 3};
	int output[] = {3, 1, 2};
	int n = sizeof(input)/sizeof(input[0]);
	cout << checkStackPermutations(input, output, n);
	return 0;
}