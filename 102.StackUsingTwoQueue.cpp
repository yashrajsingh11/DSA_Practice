// Approach : for pop simply pop from queue1 for push, pop all elements from queue1 and push them into queue2 one by one then push the 
// 			desired element then pop all elements from queue2 and push them into queue1.

#include <iostream>
#include <queue>

using namespace std;

class QueueStack{
public:
    queue<int> q1;
    queue<int> q2;

    void push(int x) {
    	while(!q1.empty()) {
    		q2.push(q1.front());
    		q1.pop();
    	}
    	q1.push(x);
    	while(!q2.empty()) {
    		q1.push(q2.front());
    		q2.pop();
    	}
    }
    int pop() {
    	if(q1.empty()) {
    		return -1;
    	}
    	int temp = q1.front();
    	q1.pop();
    	return temp;
    }
};

int main() {
	QueueStack qstack;
	int check, val;
	while(1) {
		cout << "Enter 1 to push into QueueStack" << endl;
		cout << "Enter 2 to pop from QueueStack" << endl;
		cout << "Enter 3 to exit" << endl;
		cin >> check;
		switch(check) {
			case 1 : cout << "Enter Value: ";
					cin >> val; 
					qstack.push(val);
					break;
			case 2 : cout << qstack.pop() << " is deleted" << endl;
					break;		
			case 3 : exit(0);
					break;
			default : cout << "Enter Valid Number" << endl;
		}
	}
	return 0;
} 