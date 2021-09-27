// Approach : Use two stacks to store each half of the queue. Reverse the stack using queue so that the first element is at the top.
// 			Alternatively add the elements from each stack.

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

queue<int> interleave(queue<int> q) {
	int n = q.size()/2;
	stack<int> first;
	stack<int> second;

	for(int i = 0; i < n; i++) {
		first.push(q.front());
		q.pop();
	}
	for(int i = 0; i < n; i++) {
		second.push(q.front());
		q.pop();
	}

	while(!first.empty()) {
		q.push(first.top());
		first.pop();
	}
	for(int i = 0; i < n; i++) {
		first.push(q.front());
		q.pop();
	}
	
	while(!second.empty()) {
		q.push(second.top());
		second.pop();
	}
	for(int i = 0; i < n; i++) {
		second.push(q.front());
		q.pop();
	}

	int check = 0;
	while(!second.empty()) {
		if(check == 0) {
			q.push(first.top());
			first.pop();
			check = 1;
		}
		else {
			q.push(second.top());
			second.pop();
			check = 0;
		}
	}
	return q;
}

void display(queue<int> q) {
	while(!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
}

int main() {
	queue<int> q;
	q.push(11);
	q.push(12);
	q.push(13);
	q.push(14);
	q.push(15);
	q.push(16);
	q.push(17);
	q.push(18);
	q.push(19);
	q.push(20);
	q = interleave(q);
	display(q);
	return 0;
}