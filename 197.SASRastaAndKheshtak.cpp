// Approach : Use binary search to find the maximum size of common subsquare. Compare each subsquare of size mid of matrix 1 with each
// subsquare of size mid of matrix 2. If same found then update low, if not found then update high. This process can be optimized, by 
// using sliding window for storing the maps in sets in n^2 time instead of n^4. Havent applied it yet though. 

#include <iostream>
#include <unordered_map>
#include <set>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    cin >> m;
    int matrix1[n][m];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> matrix1[i][j];
        }
    }
    int x, y;
    cin >> x;
    cin >> y;
    int matrix2[x][y];
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            cin >> matrix2[i][j];
        }
    }

    int low = 1;
    int high = min(min(min(n, m), x), y);
    int answer = 0;
    while(low <= high) {
    	bool check = false;
    	int mid = low + (high - low) / 2;
    	unordered_map<int, int> mp;
    	set<string> st;

    	for(int i = 0; i < n - mid + 1; i++) {
    		for(int j = 0; j < m - mid + 1; j++) {
    			for(int k = i; k < mid + i; k++) {
    				for(int l = j; l < mid + j; l++) {
    					mp[matrix1[k][l]]++;
    				}
    			}
    			string temp = "";
    			for(auto it = mp.begin(); it != mp.end(); it++) {
    				temp.push_back(it -> first);
    				temp.push_back(it -> second);
    			}
    			st.insert(temp);
    			mp.clear();
    		}
    	}

    	for(int i = 0; i < x - mid + 1; i++) {
    		for(int j = 0; j < y - mid + 1; j++) {
    			for(int k = i; k < mid + i; k++) {
    				for(int l = j; l < mid + j; l++) {
    					mp[matrix2[k][l]]++;
    				}
    			}
    			string temp = "";
    			for(auto it = mp.begin(); it != mp.end(); it++) {
    				temp.push_back(it -> first);
    				temp.push_back(it -> second);
    			}
    			if(st.find(temp) != st.end()) {
    				answer = max(answer, mid);
    				low = mid + 1;
    				i = 701;
    				j = 701;
    				check = true;
    			}
    			mp.clear();
    		}
    	}
    	if(check == false) {
    		high = mid - 1;
    	}
    }
    cout << answer;
    return 0;
}
