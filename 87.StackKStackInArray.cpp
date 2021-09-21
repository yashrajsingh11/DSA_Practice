// Approach 1: Divide the array into n parts and implement a stack in in each part. (Wastage of memory)
// Approach 2: Maintain two arrays: top - which keeps track of the top element of each stack, next - keeps track of the next element
// 			if the element is empty and keeps track of the previous element in stack if not empty. A variable pointer which keeps
// 			track of the latest free space in case of pop. Update logic in code. (No wastage of memory)

// ---------->>> Approach 2 <<<-----------

#include <iostream>

using namespace std;

class KStacks {
public: 
	int* top;
	int* next;
	int* arr;
	int num;
	int size;
	int free;

	KStacks(int n, int k) {
		size = n;
		num = k;
		top = new int[num];
		next = new int[size];
		arr = new int[size];
		free = 0;

		for(int i = 0; i < num; i++) {
			top[i] = -1;
		}
		for(int i = 0; i < size - 1; i++) {
			next[i] = i + 1;
		}
		next[size - 1] = -1;
	}

	void push() {
		int i = 1, stack, val;
		while(i) {
			cout << "Enter Stack Number: ";
			cin >> stack;
			if(stack >= num) {
				cout << "Invalid Stack Number" << endl;
				return;
			}
			if(free == -1) {
				cout << "Array is Full" << endl;
				return;
			}
			cout << "Enter Value: ";
			cin >> val;
			// updating free to next free space, updating next to point to previous element in stack(useful in case of pop)
			// updating the top of stack, updating actual value.
			int temp = free;
			free = next[temp];
			next[temp] = top[stack];
			top[stack] = temp;
			arr[temp] = val;
			cout << "Enter 0 to exit" << endl;
			cout << "Enter 1 to push again" << endl;
			cin >> i;
		}
	}

	void pop() {
		int i = 1, stack;
		while(i) {
			cout << "Enter Stack Number: ";
			cin >> stack;
			if(stack >= num) {
				cout << "Invalid Stack Number" << endl;
				return;
			}
			if(top[stack] == -1) {
				cout << "Stack is Empty" << endl;
				return;
			}
			// updating top fo stack to point to previous element using next, newly create free space points to the previous free space
			// free is updated to point to the latest free state. 
			int temp = top[stack]; 
			cout << arr[temp] << " is deleted\n";
			top[stack] = next[temp];
			next[temp] = free;
			free = temp;
			cout << "Enter 0 to exit" << endl;
			cout << "Enter 1 to pop again" << endl;
			cin >> i;
		}
	}

	void display() {
		int i = 1, stack;
		while(i) {
			cout << "Enter Stack Number: ";
			cin >> stack;
			if(stack >= num) {
				cout << "Invalid Stack Number" << endl;
				return;
			}
			if(top[stack] == -1) {
				cout << "Stack is Empty" << endl;
				return;
			}
			int temp = top[stack];
			while(temp != -1) {
				cout << arr[temp] << " ";
				temp = next[temp];
			}
			cout << endl;
			cout << "Enter 0 to exit" << endl;
			cout << "Enter 1 to display again" << endl;
			cin >> i;
		}
	}
};

int main() {
	int n, k, check;
	cout << "Enter the size of array: ";
	cin >> n;
	cout << "Enter the number of stacks: ";
	cin >> k;
	if(k > n) {
		cout << "Stacks cannot be more than array size";
		exit(0);
	}
	KStacks kstacks(n, k);
	while(1) {
		cout << "Enter 1 to push" << endl;
		cout << "Enter 2 to pop" << endl;
		cout << "Enter 3 to display" << endl;
		cout << "Enter 4 to exit" << endl;
		cin >> check;
		switch(check) {
			case 1 : kstacks.push();
					break;
			case 2 : kstacks.pop();
					break;
			case 3 : kstacks.display();
					break;
			case 4 : exit(0);
					break;
			default : cout << "Enter Valid Number" << endl;
		}
	}
	return 0;
}