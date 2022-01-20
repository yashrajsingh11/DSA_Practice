// Approach : Sum of distance of points from a line is a U-shaped curve w.r.t the point on the line. So, we have to divide the line into
// 3 parts to get the minimum. We calculate the sum for 2 points, if sum for p1(left point) is larger than sum for p2(right point), then
// we discard all point to the left of p1 and take p1 as the new leftmost point and again divide. Similarly if sum for p2 is larger 
// than sum for p1 then we discard all points to the right of p2 and take p2 as the new rightmost point and divide again.

#include <iostream>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

struct line {
	int a;
	int b;
	int c;

	line(int A, int B, int C) {
		a = A;
		b = B;
		c = C;
	}
};

struct point {
	int x;
	int y;

	point(int X, int Y) {
		x = X;
		y = Y;
	}
};

double getMinimum(double X1, double Y1, double X2, double Y2) {
	return sqrt((X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2));
}

double getDistance(line l, point* points, double X, int n) {
	double Y = -1 * ((l.a * X) + l.c) / l.b;
	double result = 0;
	for(int i = 0; i < n; i++) {
		result = result + getMinimum(X, Y, points[i].x, points[i].y);
	}
	return result;
}

double getMinimumDistance(line l, point* points, double low, double high, int n) {
	while(high - low > 0.000001) {
		double mid1 = low + (high - low) / 3;
		double mid2 = high - (high - low) / 3;
		double d1 = getDistance(l, points, mid1, n);
		double d2 = getDistance(l, points, mid2, n);
		if(d1 < d2) {
			high = mid2;
		}
		else {
			low = mid1;
		}
	}
	return getDistance(l, points, (low + high) / 2, n);
}

int main() {
	line l(1, -1, -3);
	point p1(-3, -2);
	point p2(-1, 0);
	point p3(-1, 2);
	point p4(1, 2);
	point p5(3, 4);
	point points[] = {p1, p2, p3, p4, p5};
	int n = sizeof(points)/sizeof(points[0]);
	cout << getMinimumDistance(l, points, -6, 6, n);
	return 0;
} 