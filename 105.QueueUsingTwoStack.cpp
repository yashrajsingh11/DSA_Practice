// Approach : pop from s1 normally. For push pop each element from s1 one by one and push into s2 then push the desired element then
// 			pop each element from s2 one by one and push into s1. 

#include <iostream>
#include <stack>

using namespace std;

class StackQueue{
public:
    stack<int> s1;
    stack<int> s2;

    void push(int val) {
    	while(!s1.empty()) {
	        s2.push(s1.top());
	        s1.pop();
	    }
	    s1.push(val);
	    while(!s2.empty()) {
	        s1.push(s2.top());
	        s2.pop();
	    }
    }

    int pop() {
	    if(s1.empty()) {
	        return -1;
	    }
	    int temp = s1.top();
	    s1.pop();
	    return temp;
    }
};

int main() {
	StackQueue sq;
	int check, val;
	while(1) {
		cout << "Enter 1 to push to StackQueue" << endl;
		cout << "Enter 2 to pop from StackQueue" << endl;
		cout << "Enter 3 to quit" << endl;
		cin >> check;
		switch(check) {
			case 1 : cout << "Enter Value: ";
					cin >> val;
					sq.push(val);
					break;
			case 2 : cout << sq.pop() << " is deleted" << endl;
					break;
			case 3 : exit(0);
					break;
			default : cout << "Enter Valid Number" << endl;
		}
	}
}