// Approach : Sort the power of soldiers and preprocess the array to store the cumulative power. Apply binary search to with key as bishu
// ki power and find the number of soldiers he can beat. Retrueve their cumulative power and print.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getIndex(vector<int> &soldiers, int n, int key) {
    int low = 0, high = n - 1, result = -1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(soldiers[mid] == key) {
            result = mid;
            low = mid + 1;
        }
        else if(soldiers[mid] < key) {
            result = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return result;
}

int main() {
    int n, rounds;
    cin >> n;
    vector<int> soldiers;
    vector<int> power;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        soldiers.push_back(temp);
    }
    
    cin >> rounds;
    for(int i = 0; i < rounds; i++) {
        int temp;
        cin >> temp;
        power.push_back(temp);
    }

    sort(soldiers.begin(), soldiers.end());
    vector<int> cmpower;
    int cmpow = 0;
    for(int i = 0; i < n; i++) {
        cmpow = cmpow + soldiers[i];
        cmpower.push_back(cmpow);
    }

    for(int i = 0; i < rounds; i++) {
        int count = getIndex(soldiers, soldiers.size(), power[i]);
        if(count == -1) {
            cout << 0 << " " << 0 << endl;
        }
        else {
            cout << count + 1 << " " << cmpower[count] << endl;
        }
    }
    return 0;
}