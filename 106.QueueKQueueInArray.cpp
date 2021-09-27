// Approach : Maintain an array next of size n. When there is no queue element in ith index of arr, next keeps track of the next free 
// element in the array = next index and when data is entered in ith index of arr, next keeps track of the next element of queue in 
// the array = -1 for rear element. An array front of size k and rear of size k is used to store the front and rear of all queues present
// int the array. A pointer free is used to keep track of the next free space while queueing and dequeueing.
 
#include <iostream>

using namespace std;

class kQueue {
public: 
	int* arr;
	int* rear;
	int* front;
	int* next;
	int free, n, k;

	kQueue(int size, int num) {
		n = size;
		k = num;
		free = 0;
		arr = new int[size];
		next = new int[size];
		rear = new int[num];
		front = new int[num];

		for(int i = 0; i < size - 1; i++) {
			next[i] = i + 1;
		}
		next[size - 1] = -1;

		for(int i = 0; i < k; i++) {
			front[i] = -1;
		}
	}

	bool isEmpty(int qn) {
		return front[qn] == -1;
	}

	bool isFull() {
		return free == -1;
	}

	void enqueue(int qn) {
		if (isFull()) {
			cout << "Array is Full" << endl;
			return;
		}
		int val;
		cout << "Enter Value: ";
		cin >> val;
		int i = free;
		free = next[i];
		if(isEmpty(qn)) {
			front[qn] = i;
		}
		else {
			next[rear[qn]] = i;
		}
		rear[qn] = i;
		next[rear[qn]] = -1;
		arr[i] = val;
	}

	void dequeue(int qn) {
		if(isEmpty(qn)) {
			cout << "Queue is Empty" << endl;
			return;
		}
		int i = front[qn];
		cout << arr[i] << " is deleted" << endl;
		front[qn] = next[i];
		next[i] = free;
		free = i;
	}

};

int main() {
	int size, num, check, qn;
	cout << "Enter the size of array: ";
	cin >> size;
	cout << "Enter number of queues: ";
	cin >> num;
	if(num >= size) {
		cout << "Number of queues must be less than size of array" << endl;
		exit(0);
	}
	kQueue kq(size, num);
	while(1) {
		cout << "Enter 1 to push into any queue" << endl;
		cout << "Enter 2 to pop from any queue" << endl;
		cout << "Enter 3 to exit" << endl;
		cin >> check;
		switch(check) {
			case 1 : cout << "Enter queue number: ";
					cin >> qn;
					if(qn < 0 or qn >= num) {
						cout << "Invalid Queue Number" << endl;
						break;
					}
					kq.enqueue(qn);
					break;
			case 2 : cout << "Enter queue number: ";
					cin >> qn;
					if(qn < 0 or qn >= num) {
						cout << "Invalid Queue Number" << endl;
						break;
					}
					kq.dequeue(qn);
					break;
			case 3 : exit(0);
					break;
			default : cout << "Enter Valid Number" << endl;
		}
	}
	return 0;
}