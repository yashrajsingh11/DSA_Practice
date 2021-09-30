// Approach : For each element if it has hashmap value 0(not present) then add it to queue and increment value. If it has value > 0 then 
// increment. Now check if front is unque(hashmap value = 1) until it is unique or the queue is empty and update string as # is queue
// is empty else update it to front of queue.

#include <iostream>
#include <queue>
#include <string>
using namespace std;

string FirstNonRepeating(string A) {
	int hashmap[26] = {0};
	queue<char> characters;
	for(int i = 0; i < A.size(); i++) {
		int temp = A[i] - 'a';
		if(hashmap[temp] == 0) {
			characters.push(A[i]);
			hashmap[temp]++;
		}
		else {
			hashmap[temp]++;
		}
		while(!characters.empty() and hashmap[characters.front() - 'a'] != 1) {
			characters.pop();
		}
		if(characters.empty()) {
			A[i] = '#';
		}
		else {
			A[i] = characters.front();
		}
	}
	return A;
}

int main() {
	string A;
	cout << "Enter a string: ";
	cin >> A;
	cout << FirstNonRepeating(A);
	return 0;
}