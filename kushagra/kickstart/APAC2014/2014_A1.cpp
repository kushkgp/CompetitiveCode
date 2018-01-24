#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ff first
#define ss second

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vp ;
typedef vector<vp> vvp;

int get_integer(string s){
	int t = stoi(s);
	int ans=0;
	for(int k=0;t;k++,t=t/10){
		ans += (t%2)<<k;
	}
	return ans;
}
string get_string(int n){
	string ans = "";
	for(int i=0;i<7;i++,n>>=1){
		ans += to_string(n%2);
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main(){
	int poss[10];
	int corr[10];
	int incor[10];
	int actual[10];

	actual[0] = get_integer("1111110");
	actual[1] = get_integer("0110000");
	actual[2] = get_integer("1101101");
	actual[3] = get_integer("1111001");
	actual[4] = get_integer("0110011");
	actual[5] = get_integer("1011011");
	actual[6] = get_integer("1011111");
	actual[7] = get_integer("1110000");
	actual[8] = get_integer("1111111");
	actual[9] = get_integer("1111011");

	int t;
	cin >> t;
	int cnt=1;
	while(t--){
		for(int i=0;i<10;i++){
			corr[i]=0,incor[i]=0,poss[i]=1;
		}
		int n;
		cin >> n;
		int k;
		for(k=0;k<n;k++){
			string s;
			cin >> s;
			int number = get_integer(s);
			// cout << number << endl;
			for(int i=0;i<10;i++){
				if(poss[i]){
					int crt = actual[((i - k)%10 + 10)%10];
					// cout<<crt<<endl;
					if(crt != (crt|number)){
						poss[i]=0;
						// cout << i << endl;
						continue;
					}
					corr[i] = corr[i]|number;
					int missing = crt & (~number);
					incor[i] = incor[i]|missing;
					if(incor[i]&corr[i])
						poss[i] = 0;
				}
			}
		}
		int ans = -1;
		for(int i=0;i<10;i++){
			if(poss[i]){
				// cout << i << endl;
				int crt = actual[((i - k)%10 + 10)%10];
				// cout << crt << endl;
				int temp = crt & ~incor[i];
				// cout << get_string(temp) << endl;
				int doubt = (crt & ~(corr[i]|incor[i]));
				// cout << doubt << " "<< get_string(crt) <<" " << get_string(((1<<7)-1)&~(corr[i]|incor[i])) << endl;
				if( doubt == 0){
					// cout << get_string(temp) << "  " << get_string(ans) << endl;
					if(ans == -1)
						ans = temp;
					else if(ans!=temp)
						ans = -2;
				}
				else
					ans = -2;
				// cout << i << " " << get_string(ans) << endl;
			}
		}
		// cout << ans << endl;
		// cout << "dfghjk "  << ans << endl;
		cout << "Case #" << cnt++ <<": ";
		if(ans>=0)
			cout << get_string(ans) << endl;
		else
			cout << "ERROR!" << endl;
	}
}