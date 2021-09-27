// Approach : Using a normal queue we check while pushing if we reached the last element of array then we start pushing from front of 
// array until there is no space left. While popping we check if we reached the last element of array then we starting popping from front.

#include <iostream>

using namespace std;

class CircularQueue {
public:
	int* arr;
	int front, rear, size;

	CircularQueue(int s) {
		arr = new int[s];
		front  = -1;
		rear = -1;
		size = s;
	}

	bool isEmpty() {
		return front == -1;
	}

	bool isFull() {
		return (rear == size - 1 and front == 0) or (rear == front - 1); 
	}

	void push() {
		if(isFull()) {
			cout << "Queue is Full" << endl;
			return;
		}
		int val;
		cout << "Enter Value: ";
		cin >> val;
		if(rear == -1) {
			front = 0; 
			rear = 0;
			arr[rear] = val;
		}
		else {
			if(rear == size - 1) {
				rear = 0;
				arr[rear] = val;
			}
			else {		
				rear++;
				arr[rear] = val; 
			}
		}
	}

	void pop() {
		if(isEmpty()) {
			cout << "Queue is Empty" << endl;
			return;
		}
		cout << arr[front] << " is deleted" << endl;
		if(front == rear) {
			front = -1;
			rear = -1;
		}
		else {
			if(front == size - 1) {
				front = 0;
			}
			else {
				front++;
			}
		}
	}
};

int main() {
	int check, size;
	cout << "Enter the size of circular queue: ";
	cin >> size;
	CircularQueue cq(size);
	while(1) {
		cout << "Enter 1 to push into CircularQueue" << endl;
		cout << "Enter 2 to pop fron CircularQueue" << endl;
		cout << "Enter 3 to exit" << endl;
		cin >> check;
		switch(check) {
			case 1 : cq.push();
					break;
			case 2 : cq.pop();
					break;
			case 3 : exit(0);
					break;
			default : cout << "Enter Valid Number" << endl;
		}
	}
	return 0;
}