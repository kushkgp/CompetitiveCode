/* A program to find day of a given date */
#include <bits/stdc++.h>
using namespace std;
int dayofweek(int d, int m, int y)
{
	static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
	y -= m < 3;
	return ((y+y/4-y/100+y/400+t[m-1]+d)%7+7)%7;
}

/* Driver function to test above function */
int main()
{
	cout<<"Enter date month year:";
	int d,m,y;
	cin>>d>>m>>y;
	const string day[] = {"Sun","Mon","Tues","Wednes","Thurs","Fri","Sat","Sun"}; 
	cout<<day[dayofweek(d,m,y)]+"day"<<endl;
	return 0;
}