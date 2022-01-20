// Approach 1 : Take the profit and deadline arrays in pair. Sort them according to profit in descending order. Create an array equal
// to the size of the job with maximum deadline and initialize with 0. This array will hold the entire job schedule. For each job find
// if it can performed anywhere in between T = 0 to T = deadline, by finding the highest index which has a 0 between index 0 to
// index deadline in the job schedule array. Assign the job by changing 0 to 1 and update count and profit accordingly. 
// Time Complexity : O(n^2).

//Approach 2 : Using Max-Heap. Time Complexity : O(nlogn)

// ----------->>> Approach 1 <<<-----------

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

struct Job {
	int id;
	int dead;
	int profit;
};

vector<int> JobScheduling(Job arr[], int n) { 
    vector<pair<int, int>> info;
    vector<int> result;
    int maxDead = -1, profit = 0, count = 0;
    
    for(int i = 0; i < n; i++) {
        info.push_back(make_pair(arr[i].profit, arr[i].dead));
    }
    
    sort(info.rbegin(), info.rend());

    for(int i = 0; i < n; i++) {
        maxDead = max(info[i].second, maxDead);
    }
    
    int schedule[maxDead];
    for(int i = 0; i < maxDead; i++) {
        schedule[i] = 0;
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = info[i].second - 1; j >= 0; j--) {
            if(schedule[j] == 0) {
                schedule[j] = 1;
                count ++;
                profit += info[i].first;
                break;
            }
        }
    }
    result.push_back(count);
    result.push_back(profit);
    return result;
} 

int main() {
	Job arr[4];

	arr[0].id = 1;
	arr[0].dead = 4;
	arr[0].profit = 20;

	arr[0].id = 2;
	arr[0].dead = 1;
	arr[0].profit = 10;

	arr[0].id = 3;
	arr[0].dead = 1;
	arr[0].profit = 40;

	arr[0].id = 4;
	arr[0].dead = 1;
	arr[0].profit = 30;

	vector<int> res = JobScheduling(arr, 4);
	cout << res[0] << " " << res[1];
	return 0;
}