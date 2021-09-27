// Approach : Maintain a hashmap which keeps the track of the pointer to that key in DLL.
// While setting, if pointer of key in hashmap is not null then remove the node with pointer of key in dll and insert pointer of key at
// end of dll and change accordingly in hashmap. If count equal to size then remove from head and insert pointer of key at end of dll, 
// change accordingly in hashmap. Else simply insert at end and update count and hashmap. 
// While getting simply return the value of key from hashmap if it is not null and update the dll to remove get element and insert it
// at end of dll also update hashmap else return -1.

#include <iostream>

using namespace std;

struct node {
	int key;
	int value;
	struct node* prev;
	struct node* next;

	node(int x, int y) {
		key = x;
		value = y;
		prev = NULL;
		next = NULL;
	}
};

class LRUCache {
public: 
	struct node* address[1001];
	int count = 0;
	int size;
	struct node* head = NULL;
	struct node* tail = NULL;

	LRUCache(int cap) {
		size = cap;

		for(int i = 0; i < 1001; i++) {
			address[i] = NULL;
		}
	}

	void display() {
		struct node* ptr = head;
		while(ptr != NULL) {
			cout << ptr -> key << " ";
			ptr = ptr -> next;
		}
		cout << endl;
	}

	int get(int key) {
        if(address[key] != NULL) {
        	return address[key] -> value;
        }
        else {
        	return -1;
        }
    }

    void set(int key, int value) {
    	if(address[key] != NULL) {
    		struct node* temp = address[key];
    		address[key] = NULL;
    		
    		if(temp == head) {
    			head = head -> next;
    		}
    		if(temp == tail) {
    			tail = tail -> prev;
    		}
    		if(temp -> next != NULL) {
    			temp -> next -> prev = temp -> prev;
    		}
    		if(temp -> prev != NULL) {
    			temp -> prev -> next = temp -> next;
    		}
    		delete(temp);

    		if(head == NULL) {
	    		head = new node(key, value);
	    		tail = head;
	    	}
	    	else {
	    		tail -> next = new node(key, value);
	    		tail -> next -> prev = tail;
	    		tail = tail -> next;
	    	}
    		address[key] = tail;
    		return;
    	}
    	if(count == size) {
    		int temp = head -> key;
    		if(head == tail) {
    			struct node* temporary = head;
    			head = NULL;
    			tail = NULL;
    			delete(temporary);
    		}
    		else {
    			struct node* temporary = head;
    			head = head -> next;
    			head -> prev = NULL;
    			delete(temporary);
    		}
    		address[temp] = NULL;

    		if(head == NULL) {
	    		head = new node(key, value);
	    		tail = head;
	    	}
	    	else {
	    		tail -> next = new node(key, value);
	    		tail -> next -> prev = tail;
	    		tail = tail -> next;
	    	}
    		address[key] = tail;
    	}
    	else {
	    	if(head == NULL) {
	    		head = new node(key, value);
	    		tail = head;
	    	}
	    	else {
	    		tail -> next = new node(key, value);
	    		tail -> next -> prev = tail;
	    		tail = tail -> next;
	    	}
	    	count++;
	    	address[key] = tail;
	    }
    }
};

int main() {
	int size, check, value, key;
	cout << "Enter size of LRU Cache: ";
	cin >> size;
	LRUCache lru(size);
	while(1) {
		cout << "Enter 1 to set" << endl;
		cout << "Enter 2 to get" << endl;
		cout << "Enter 3 to exit" << endl;
		cout << "Enter 4 to display DLL" << endl;
		cin >> check;
		switch(check) {
			case 1 : cout << "Enter Key and Value" << endl;
					cin >> key;
					cin >> value;
					lru.set(key, value);
					break;
			case 2 : cout << "Enter key" << endl;
					cin >> key;
					cout << lru.get(key) << endl;
					break;
			case 3 : exit(0);
					break;
			case 4 : lru.display();
					break;
			default : cout << "Enter Valid Number" << endl;
		}
	}
	return 0;
}