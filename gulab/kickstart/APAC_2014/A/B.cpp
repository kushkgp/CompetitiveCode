/*
	Author		:	Gulab Arora
	Institute	:	IIT Kharagpur
*/

#include <bits/stdc++.h>

#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define inf INT_MAX

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

#define all(c) (c).begin(),(c).end()
#define allr(c) (c).rbegin(),(c).rend()
#define asort(c) sort(all(c))
#define dsort(c) sort(allr(c))

#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;


void transform(vvi & m, int n){
	for(int j = 0; j < n; j++){
		int k = n-1,prev=0;
		for(int i = n-1; i>=0; i--){
			if(prev && m[i][j]){
				if(prev == m[i][j]){
					m[k--][j]=prev<<1;
					prev = 0;
				}
				else{
					m[k--][j]=prev;
					prev=m[i][j];
				}
			}
			else if(m[i][j])
				prev=m[i][j];
		}
		if(prev)
			m[k--][j]=prev;
		for(int i = k; i>=0; i--)
			m[i][j]=0;
	}
}

int main(){
	int t;
	cin>>t;
	int cnt =1;
	while(t--){
		int n;
		string dir;
		cin>>n>>dir;
		vvi m(n,vi(n));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				cin>>m[i][j];
		vvi temp = m;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++){
				if(dir=="right")
					m[i][j]=temp[j][i];
				else if(dir=="up")
					m[i][j]=temp[n-1-i][j];
				else if(dir=="left")
					m[i][j]=temp[j][n-1-i];
			}
		transform(m,n);
		temp = m;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++){
				if(dir=="right")
					m[i][j]=temp[j][i];
				else if(dir=="up")
					m[i][j]=temp[n-1-i][j];
				else if(dir=="left")
					m[i][j]=temp[n-1-j][i];
			}
		printf("Case #%d:\n",cnt++);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cout<<m[i][j]<<" ";
			cout<<endl;
		}
	}
}