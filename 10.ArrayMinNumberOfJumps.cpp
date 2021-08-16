// Approach : steps is the number of elements still left to compare with maxrange in order to find the maximum distance that can be 
// travelled in one jump. max range is the maximum distance that can be travelled in one jump. We compare the maximum distance each
// ith element can allow us to travel with the maximum distance we currently can travel for one jump for the number of steps we have
// when steps are 0 then we have certainly jumped once though it can be from any index let us say j, but we know that all the elements
// from j to steps couldnt contribute in jumps since the max range is already larger when we dont consider them for jump now we update
// steps to check all remaining elements in range i to maxrange and repeat until we reach end or a point where maxrange is equal to i
// eg - [1, 4, 3, 2, 1, 0, 1, 2] in this case we return -1 otherwise the number of jumps is returned. 

int minJumps(int a[], int n) {
	if(n <= 1) {
		return 0;
	}

	if(a[0] == 0) {
		return -1;
	}

	int step = a[0];
	int maxRange = a[0];
	int jump = 1;

	for(int i = 1; i < n; i++) {
		if(i == n - 1) {
			return jump;
		}

		maxRange = max(i+ a[i], maxRange);
		step = step - 1;
		if(step == 0) {
			jump++;
			if(i >= maxRange) {
				return -1;
			}
			step = maxRange - i;
		}
	}	
	return -1;
}
