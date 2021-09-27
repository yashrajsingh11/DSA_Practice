// Approach : Use a stack to reverse first k element and use a queue to store the output

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void display(queue<int> q) {
	while(!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
}

queue<int> modifyQueue(queue<int> q, int k) {
    stack<int> s;
    queue<int> result;
    for(int i = 0; i < k; i++) {
    	s.push(q.front());
    	q.pop();
    }
    while(!s.empty()) {
    	result.push(s.top());
    	s.pop();
    }
    while(!q.empty()) {
    	result.push(q.front());
    	q.pop();
    }
    return result;
}

int main() {
	int k;
	cout << "Enter value of k: " << endl;
	cin >> k;
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q = modifyQueue(q, k);
	display(q);
	return 0;
} 