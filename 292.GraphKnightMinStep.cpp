// Approach : Use BFS traversal and keep track of number of turns taken to reach target position. Also keep track of the visited position
// using a hashmap. In the queue enter all the positions which are available for the knight.

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N) {
    int turns = 0;
    int count = 1;
    int tempcount = 0;
    
    queue<vector<int>> q;
    q.push(KnightPos);
    
    int hashmap[N + 1][N + 1];
    for(int i = 0; i < N + 1; i++) {
        for(int j = 0; j < N + 1; j++) {
            hashmap[i][j] = 0;
        }
    }
    hashmap[KnightPos[0]][KnightPos[1]] = 1;
    
    while(!q.empty()) {
        if(count == 0) {
            turns++;
            count = tempcount;
            tempcount = 0;
        }
        vector<int> temp = q.front();
        if(temp[0] == TargetPos[0] and temp[1] == TargetPos[1]) {
            return turns;
        }
        if(temp[0] + 2 <= N and temp[1] + 1 <= N) {
            if(hashmap[temp[0] + 2][temp[1] + 1] != 1) {
                hashmap[temp[0] + 2][temp[1] + 1] = 1;
                vector<int> faltu;
                faltu.push_back(temp[0] + 2);
                faltu.push_back(temp[1] + 1);
                q.push(faltu);
                tempcount++;
            }
        }
        if(temp[0] + 2 <= N and temp[1] - 1 >= 1) {
            if(hashmap[temp[0] + 2][temp[1] - 1] != 1) {
                hashmap[temp[0] + 2][temp[1] - 1] = 1;
                vector<int> faltu;
                faltu.push_back(temp[0] + 2);
                faltu.push_back(temp[1] - 1);
                q.push(faltu);
                tempcount++;
            }
        }
        if(temp[0] - 2 >= 1 and temp[1] + 1 <= N) {
            if(hashmap[temp[0] - 2][temp[1] + 1] != 1) {
                hashmap[temp[0] - 2][temp[1] + 1] = 1;
                vector<int> faltu;
                faltu.push_back(temp[0] - 2);
                faltu.push_back(temp[1] + 1);
                q.push(faltu);
                tempcount++;
            }
        }
        if(temp[0] - 2 >= 1 and temp[1] - 1 >= 1) {
            if(hashmap[temp[0] - 2][temp[1] - 1] != 1) {
                hashmap[temp[0] - 2][temp[1] - 1] = 1;
                vector<int> faltu;
                faltu.push_back(temp[0] - 2);
                faltu.push_back(temp[1] - 1);
                q.push(faltu);
                tempcount++;
            }
        }
        if(temp[0] + 1 <= N and temp[1] + 2 <= N) {
            if(hashmap[temp[0] + 1][temp[1] + 2] != 1) {
                hashmap[temp[0] + 1][temp[1] + 2] = 1;
                vector<int> faltu;
                faltu.push_back(temp[0] + 1);
                faltu.push_back(temp[1] + 2);
                q.push(faltu);
                tempcount++;
            }
        }
        if(temp[0] + 1 <= N and temp[1] - 2 >= 1) {
            if(hashmap[temp[0] + 1][temp[1] - 2] != 1) {
                hashmap[temp[0] + 1][temp[1] - 2] = 1;
                vector<int> faltu;
                faltu.push_back(temp[0] + 1);
                faltu.push_back(temp[1] - 2);
                q.push(faltu);
                tempcount++;
            }
        }
        if(temp[0] - 1 >= 1 and temp[1] + 2 <= N) {
            if(hashmap[temp[0] - 1][temp[1] + 2] != 1) {
                hashmap[temp[0] - 1][temp[1] + 2] = 1;
                vector<int> faltu;
                faltu.push_back(temp[0] - 1);
                faltu.push_back(temp[1] + 2);
                q.push(faltu);
                tempcount++;
            }
        }
        if(temp[0] - 1 >= 1 and temp[1] - 2 >= 1) {
            if(hashmap[temp[0] - 1][temp[1] - 2] != 1) {
                hashmap[temp[0] - 1][temp[1] - 2] = 1;
                vector<int> faltu;
                faltu.push_back(temp[0] - 1);
                faltu.push_back(temp[1] - 2);
                q.push(faltu);
                tempcount++;
            }
        }
        q.pop();
        count--;
    }
    return -1;
}

int main() {
	vector<int> kp = {4, 5};
	vector<int> tp = {1, 1};
	int n = 6;
	cout << minStepToReachTarget(kp, tp, n);
	return 0;
}