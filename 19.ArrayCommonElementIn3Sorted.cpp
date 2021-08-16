// Approach : Check if two elements of array are similar if true then check if third array has the same element
//            First check for redundant values.

#include <iostream>
#include <vector>

using namespace std;

vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3) {
    int i = 0, j = 0, k = 0;
    vector<int> result;
    int prevA = -1;
    int prevB = -1;
    int prevC = -1;

    while(i < n1 and j < n2 and k < n3) {

    	if(A[i] == B[j] and B[j] == C[k]) {
    		result.push_back(A[i]);
    		prevA = A[i];
    		prevB = B[j];
    		prevC = C[k];
    		i++;
    		j++;
    		k++;
    	}

        else if(A[i] < B[j]) {
        	prevA = A[i];
        	i++;
        } 
        
        else if(C[k] < A[i] and C[k] < B[j]) {
        	prevC = C[k];
        	k++;
        }
        
        else {
        	prevB = B[j];
        	j++;
        }

    	while(prevA == A[i] and i < n1) {
    		prevA = A[i];
    		i++;
    	}
    	while(prevB == B[j] and j < n2) {
    		prevB = B[j];
    		j++;
    	}
    	while(prevC == C[k] and k < n3) {
    		prevC = C[k];
    		k++;
    	}
    }
    return result;
}

int main() {
	int A[] = {1, 5, 10, 20, 20, 40, 80};
	int B[] = {6, 7, 20, 80, 100};
	int C[] = {3, 4, 15, 20, 30, 70, 80, 120};
	int n1 = sizeof(A)/sizeof(A[0]);
	int n2 = sizeof(B)/sizeof(B[0]);
	int n3 = sizeof(C)/sizeof(C[0]);
	vector<int> result;
	
	result = commonElements(A, B, C, n1, n2, n3);
	
	for(int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}

	return 0;
}