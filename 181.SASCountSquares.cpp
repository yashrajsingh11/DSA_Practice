// Approach : Take sqrt of the number. If its an integer return after subtracting 1(we cannot count the given index's sqrt) else return.

#include <iostream>
#include <math.h>

using namespace std;

int countSquares(int N) {
    double temp = sqrt(N);
    if(temp == (int)temp) {
        return temp - 1;
    }
    return temp;
}	

int main() {
	cout << countSquares(9);
}