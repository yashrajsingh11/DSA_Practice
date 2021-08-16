// Approach : Keep updating the smallest element and keep updating the maximum profit we can get from it.

#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {

    int minimum = 10001;
    int profit = 0;

    for(int i = 0; i < prices.size(); i++) {
    	if(prices[i] < minimum) {
    		minimum = prices[i];
    	}
    	else if(prices[i] - minimum > profit) {
    		profit = prices[i] - minimum;
    	}
    }

    return profit;
}

int main() {
	vector<int> prices {
		7, 1, 5, 3, 6, 4
	}; 
	cout << maxProfit(prices);
	return 0;
}