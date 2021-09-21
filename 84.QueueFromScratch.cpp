// Approach: Queue from scratch with enqueue, dequeue, isEmpty, isFull, front-element, rear-element, size, display methods.

#include <bits/stdc++.h>

using namespace std;

class Queue {
public:
	int* arr;
	int size;
	int front;
	int rear;

	Queue(int mySize) {
		arr = new int[mySize];
		size = mySize;
		front = -1;
		rear = -1;
	}

	void enqueue() {
		if(isFull()) {
			cout << "Queue is full";
			exit(0);
		}

		int val;
		cout << "Enter Value: ";
		cin >> val;
		if(front == -1) {
			front = 0;
		}
		rear++;
		arr[rear] = val;
	}

	void dequeue() {
		if(isEmpty()) {
			cout << "Queue is empty";
			exit(0);
		}
		cout << ffront() << " deleted\n";
		front++;
	}

	bool isEmpty() {
		return front > rear or front == -1;
	}

	bool isFull() {
		return rear == size - 1;
	}

	int ffront() {
		if(isEmpty()) {
			cout << "Queue is Empty";
			exit(0);
		}
		return arr[front];
	}

	int rrear() {
		if(isEmpty()) {
			cout << "Queue is Empty";
			exit(0);
		}
		return arr[rear];
	}

	int ssize() {
		return rear - front + 1;
	}

	void display() {
		if(isEmpty()) {
			cout << "Queue is Empty";
			exit(0);
		}
		cout << "Queue: ";
		for(int i = front; i <= rear; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
};

int main() {
	int size, check, i = 1;
	cout << "Enter the size of Queue: ";
	cin >> size;

	Queue queue(size);
	while(i) {
		cout << "Enter 1 to add to queue" << endl;
		cout << "Enter 2 to remove from queue" << endl;		
		cout << "Enter 3 to check if empty" << endl;
		cout << "Enter 4 to check if full" << endl;
		cout << "Enter 5 to get front element" << endl;
		cout << "Enter 6 to get rear element" << endl;
		cout << "Enter 7 to get size of queue" << endl;
		cout << "Enter 8 to display the queue" << endl;
		cin >> check;
		switch(check) {
			case 1 : queue.enqueue();
					break;
			case 2 : queue.dequeue();
					break;
			case 3 : cout << "IsEmpty = " << queue.isEmpty() << endl;
					break;
			case 4 : cout << "IsFull = " << queue.isFull() << endl;
					break;
			case 5 : cout << "Front = " << queue.ffront() << endl;
					break;
			case 6 : cout << "Rear = " << queue.rrear() << endl;
					break;
			case 7 : cout << "Size = " << queue.ssize() << endl;
					break;
			case 8 : queue.display();
					break;
			default : cout << "Enter Valid Number" << endl;
		}
		cout << "Enter 0 to quit or 1 to continue: ";
		cin >> i;
	}
	return 0;
}