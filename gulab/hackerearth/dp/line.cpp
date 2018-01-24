#include <bits/stdc++.h>
#define rem 1000000009
using namespace std;

typedef struct point
{
	int x,y;
} point;

bool same_side_line(point p1,point p2,point t1,point t2){
	double m = ((double)p2.y-p1.y)/(p2.x-p1.x);
	double c = p2.y - m*p2.x;
	double d1 = t1.y - m*t1.x -c;
	double d2 = t2.y - m*t2.x -c;
	if((d1>0 && d2<0 )||(d1<0 && d2>0))
		return false;
	return true;
}

double ans(point *p, int n, int h){
	
}