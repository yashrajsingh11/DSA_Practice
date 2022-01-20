// Approach: Activity Selection Problem - We are given n activities with their start and finish times. Select the maximum number of 
// activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.
// This problem is solved by greedy approach. 
// Sort starting time and ending time array based on the ending time array. Now count all the meetings where the starting time is less
// than the ending time of the previous meeting. Here we are finding the optimal solution at each stage and it leads to global optimal
// solution, this is why it is greedy approach.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int maxMeetings(int start[], int end[], int n) {
    vector<pair<int, int>> timings;
    
    for(int i = 0; i < n; i++) {
        timings.push_back(make_pair(end[i], start[i]));
    }

    sort(timings.begin(), timings.end());
    int startTime = -1;
    int result = 0;
    
    for(int i = 0; i < timings.size(); i++) {
        if(startTime < timings[i].second) {
            result++;
            startTime = timings[i].first;
        }
    }

    return result;
}

int main() {
    int start[] = {10, 12, 20};
    int end[] = {19, 25, 30};
    int n = sizeof(start)/sizeof(start[0]);
    cout << maxMeetings(start, end, n);
	return 0;
}