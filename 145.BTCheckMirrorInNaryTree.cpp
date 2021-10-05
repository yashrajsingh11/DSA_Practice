// Approach : While traversing the edge array of tree1 for each new node encountered insert the node value as key in the map and create 
// a new queue associated with the key and push the connected node into the queue. If node is already present just push the connected
// node into the associated queue. While traversing the edge array of tree2 for each new node encountered insert the node value as key 
// in the map and create a new stack associated with the key and push the connected node into the stack. If node is already present just 
// push the connected node into the associated stack.
// Now for each element in both the maps, if key is different then return false(different nodes in graphs). If one map is traversed and
// the other is not then return false(different size of graph). If the key is same then if the front of queue and top of stack is not 
// same then return false(not same edge connections). If same then pop both and check until both empty, if one empty and the other is 
// not then return false(not same edge connections). If the whole logic is traversed then return true.


#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <vector>

using namespace std;

int checkMirrorTree(int n, int e, int A[], int B[]) {
    map<int, queue<int>> tree1;
    map<int, stack<int>> tree2;
    for(int i = 0; i < 2 * e; i = i + 2) {
        if(tree1.find(A[i]) != tree1.end()) {
            tree1.find(A[i]) -> second.push(A[i + 1]);
        }
        else {
            queue<int> q;
            q.push(A[i + 1]);
            pair<int, queue<int>> p;
            p.first = A[i];
            p.second = q;
            tree1.insert(p);
        }
        if(tree2.find(B[i]) != tree2.end()) {
            tree2.find(B[i]) -> second.push(B[i + 1]);
        }
        else {
            stack<int> s;
            s.push(B[i + 1]);
            pair<int, stack<int>> p;
            p.first = B[i];
            p.second = s;
            tree2.insert(p);
        }
    }
    auto itr1 = tree1.begin();
    auto itr2 = tree2.begin();
    while(itr1 != tree1.end() and itr2 != tree2.end()) {
        if(itr1 -> first != itr2 -> first) {
            return false;
        }
        else {
            while(!itr1 -> second.empty() and !itr2 -> second.empty()){
                if(itr1 -> second.front() != itr2 -> second.top()) {
                    return false;
                }
                else {
                    itr1 -> second.pop();
                    itr2 -> second.pop();
                }
            }
            if(!itr1 -> second.empty() or !itr2 -> second.empty()) {
                return false;
            }
        }
        itr1++;
        itr2++;
    }
    if(itr1 != tree1.end() or itr2 != tree2.end()) {
        return false;
    }
    return true;
}

int main() {
    int n = 2;
    int e = 4;
    int A[] = {2, 4, 1, 2, 1, 3, 2, 5};
    int B[] = {1, 3, 1, 2, 2, 5, 2, 4};
    cout << checkMirrorTree(n, e, A, B);
    return 0;
}