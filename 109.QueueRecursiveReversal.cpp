// Approach 1 : Recursively reach the end of queue while poping. Then push the elements to reverse the queue.
// Approach 2 : Use a stack to push all elements from queue into it. Then push all elements from stack to queue.

// ---------->>> Approach 1 <<<------------

// #include <iostream>
// #include <queue>

// using namespace std;

// void reverse(queue<int> &q) {
//     if(q.empty()) {
//         return;
//     }
//     int temp = q.front();
//     q.pop();
//     reverse(q);
//     q.push(temp);
// }

// queue<int> rev(queue<int> q) {
//     reverse(q);
//     return q;
// }

// void display(queue<int> q) {
//     while(!q.empty()) {
//         cout << q.front() << " ";
//         q.pop();
//     }
// }

// int main() {
//     queue<int> q;
//     q.push(1);
//     q.push(2);
//     q.push(3);
//     q.push(4);
//     q.push(5);
//     q = rev(q);
//     display(q);
//     return 0;
// }

// ---------->>> Approach 2 <<<------------

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

queue<int> rev(queue<int> q) {
    stack<int> s;
    while(!q.empty()) {
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    return q;
}

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q = rev(q);
    display(q);
    return 0;
}