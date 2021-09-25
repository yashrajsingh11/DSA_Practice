// Approach 1 : Using Stack - Push -1 into stack as starting index. Push index of '(' into stack if encountered. If there is no '(' and 
// 			')' is encountered then change starting index from -1 to index of ')'. If a pair is matched then pop and length of valid  
//			substring is i - s.top(). Compare it with the global longest length. 

// Approach 2 : Using two variables left and right which keep track of number of '(' and ')'. If number of ')' is greater than number
// 			of '(' then reset left = right = 0 else if both are equal then length of valid string = 2 * left. We need check from both 
//			side of array to check for cases such as (() where left will always be larger than right. 

#include <iostream>
#include <string.h>
#include <stack>

using namespace std;

// ------>>> Approach 1 <<<-------

// int findMaxLen(string s) {
// 	stack<int>st;
// 	int counter = -1;
// 	st.push(counter);
// 	int result = 0;
// 	for(int i = 0; i < s.size(); i++) {
// 		if(s[i] == '(') {
// 			st.push(i);
// 		}
// 		else {
// 			if(st.top() == counter) {
// 				st.pop();
// 				counter = i;
// 				st.push(counter);
// 			}
// 			else{
// 				st.pop();
// 				int temp = st.top();
// 				int tempResult = i - temp;
// 				result = max(result, tempResult);
// 			}
// 		}
// 	}
// 	return result;
// }

// ------>>> Approach 2 <<<-------

int findMaxLen(string s) {
	int left = 0, right = 0;
	int result = 0;
	for(int i = 0; i < s.size(); i++) {
		s[i] == '(' ? left++ : right++;
		if(left == right) {
			result = max(result, right * 2);
		}
		if(right > left) {
			left = 0;
			right = 0;
		}
	}
	left = 0;
	right = 0;
	for(int i = s.size() - 1; i >= 0; i--) {
		s[i] == ')' ? left++ : right++;
		if(left == right) {
			result = max(result, right * 2);
		}
		if(right > left) {
			left = 0;
			right = 0;
		}
	}
	return result;
}

int main() {
	string A = "((()()()()(((())";
	cout << findMaxLen(A);
	return 0;
}