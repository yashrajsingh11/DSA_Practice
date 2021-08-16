// Approach : Sort intervals according to x and then merge all elements where max is greater than xi+1 and update max = max(Yi, Yi+1)
// Time - O(nlogn) 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
	sort(intervals.begin(), intervals.end());

    vector<vector<int>> result;
    int smallest = intervals[0][0];
    int largest = intervals[0][1];

    for(int i = 1; i < intervals.size(); i++) {
    	if(intervals[i][0] <= largest) {
    		largest = max(intervals[i][1], largest);
    	}
    	else {
    		vector<int> temp {smallest, largest};
    		result.push_back(temp);
    		smallest = intervals[i][0];
    		largest = intervals[i][1];
    	}
    }

    vector<int> temp {smallest, largest};
	result.push_back(temp);

    return result;
}

int main() {
	vector<vector<int>> intervals {
		{2, 6}, {15, 18}, {8, 10}, {1, 3}
	};
	intervals = merge(intervals);
	for(int i = 0; i < intervals.size(); i++) {
		for(int j = 0; j < intervals[i].size(); j++) {
			cout << intervals[i][j] << " ";
		}
		cout << endl;
	}
	return  0;
}