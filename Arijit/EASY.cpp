#include <bits/stdc++.h>
using namespace std;

void printa( int count )
{
	int n = count;
	if(n<=3){
        if(n==3) printf("2+2(0)");
        else if(n==2) printf("2");
        else if(n==1) printf("2(0)");
        else printf("ERROR");
        return;
    }

	cout<<"2(";
	int newcount = 0;
	while(n>0)
	{
		n = n/2;
		newcount++;
	}
	printa(newcount-1);
	cout<<")";
	int ans = pow(2,newcount-1);
	if(count-ans!=0) {
		cout<<"+"; printa(count-ans); }
	return;
}

int main()
{
	cout<<"137=";printa(137); cout<<endl;
	cout<<"1315=";printa(1315); cout<<endl;
	cout<<"73=";printa(73); cout<<endl;
	cout<<"136=";printa(136); cout<<endl;
	cout<<"255=";printa(255); cout<<endl;
	cout<<"1384=";printa(1384); cout<<endl;
	cout<<"16385=";printa(16385); cout<<endl;

}