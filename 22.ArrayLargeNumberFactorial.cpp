// Approach : Consider each element of an array as an element of the Factorial. Now apply simple mathematics rules of multiplication
// 			  on them to obtain the factorial in reversed order

#include <iostream>
#include <vector>
using namespace std;

vector<int> factorial(int N){
	vector<int> output;
	output.push_back(1);

	if(N < 2) {
		
		return output;
	}

	for(int i = 2; i <= N; i++) {
		int carry = 0;
		for(int j = 0; j < output.size(); j++) {
			int temp = output[j] * i + carry;
			output[j] = temp % 10;
			carry = temp/10;
		}
		if(carry > 0) {
			while(carry >= 1) {
				output.push_back(carry % 10);
				carry = carry/10;
			}
		}
	}

	return output;

}	

int main() {
	int num = 2000;
	vector<int> result;
	result = factorial(num);
	for(int i = 0; i < result.size(); i++) {
		cout << result[result.size() - i - 1];
	}
	return 0;
}