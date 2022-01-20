// Approach : nth term of AP = a + (n - 1)d.

#include <iostream>
#include <math.h>

using namespace std;

int inSequence(int A, int B, int C){
    double diff = (double)B - (double)A;
    if(diff == 0) {
        return 1;
    }
    if(C == 0) {
        return 0;
    }
    double temp = diff / (double)C;
    if(floor(temp) == temp and temp >= 0) {
        return 1;
    }
    return 0;
}

int main() {
	int a = 1;
	int b = 2;
	int c = 3;
	cout << inSequence(a, b, c);
	return 0;
}