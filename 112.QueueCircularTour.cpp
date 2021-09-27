// Approach : For every ith element start the queue from ith element. If we can reach the next petrol pump then add that petrol pump to
// queue else set i equal to rear + 1 and update all variables accordingly. If we are checking after reaching the end then it is the 
// final check if we cannot reach next petrol pump return -1 or if we reach last element and we cannot reach first element from there
// return -1. If front == rear then we completed one loop return front.

#include <iostream>

using namespace std;

struct petrolPump {
	int petrol;
	int distance;
};

int tour(petrolPump p[],int n) {
	int i = 0;
	int front = -1;
	int rear = -1;
	bool nogoingback = false;
	int currentPetrol = 0;
	while(i < n) {
		front = i;
		rear = i;
		while(front != -1) {
			if(currentPetrol + p[rear].petrol < p[rear].distance) {
				if(rear == n - 1 or nogoingback == true) {
					return -1;
				}
				i = rear + 1;
				cout << i << " ";
				currentPetrol = 0;
				front = -1;
				rear = -1;
			}
			else {
				currentPetrol = currentPetrol + p[rear].petrol - p[rear].distance;
				if(rear == n - 1) {
					rear = 0;
					nogoingback = true;
				}
				else {
					rear++;
				}
				if(front == rear) {
					return front;
				}
			}
		}

	}	
}

int main() {
	int n;
	cout << "Enter number of petrol pumps: ";
	cin >> n;
	petrolPump p[n];
	cout << "Enter n values for petrol and distance: " << endl;
	for(int i = 0; i < n; i++) {
		cin >> p[i].petrol;
		cin >> p[i].distance;
	}
	cout << tour(p, n);
	return 0;
}