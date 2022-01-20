// Approach : We keepa hashtable of prefix sum which store the frequency of occurence of prefix sum at each index. If same prefix sum
// occur more than once that means there was a zero sum subarray in between.

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

long long findSubarray(vector<long long> arr, int n ) {
    unordered_map<long long, long long> mp;
    long long count = 0;
    long long sum = 0;
    mp[sum] = 1;
    for(int i = 0; i < n; i++) {
        sum = sum + arr[i];
        if(mp.find(sum) == mp.end()) {
            mp[sum] = 1;
        }
        else {
            count = count + mp[sum];
            mp[sum]++;
        }
    }
    return count;
}

int main() {
	vector<long long> arr = {6, -1, -3, 4, -2, 2, 4, 6, -12, -7};
	cout << findSubarray(arr, arr.size());
}