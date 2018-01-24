#include <bits/stdc++.h>
#define size1 1000
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
using namespace std;
typedef struct team{
	string name;
	int pt;
	int wins;
	int goal_diff;
	int goals_scored;
	int games_played;
}team;

bool compare(const team& l, const team& r){
	int f;
	if(l.pt!=r.pt){
		if (l.pt>r.pt)
			f= 1;
		else
			f=0;
	}
	else{
		if(l.wins!=r.wins){
			if (l.wins>r.wins)
				f= 1;
			else
				f=0;
		}
		else{
			if(l.goal_diff!=r.goal_diff){
				if (l.goal_diff>r.goal_diff)
					f= 1;
				else
					f=0;
			}
			else{
				if(l.goals_scored!=r.goals_scored){
					if (l.goals_scored>r.goals_scored)
						f= 1;
					else
						f=0;
				}
				else{
					if(l.goals_scored!=r.goals_scored){
						if (l.games_played<r.games_played)
							f= 1;
						else
							f=0;
					}
					else{
						string s1 = l.name;
						string s2 = r.name;
						transform(l.name.begin(), l.name.end(), s1.begin(), ::tolower);
						transform(r.name.begin(), r.name.end(), s2.begin(), ::tolower);
						f = (s1<s2);
					}	
				}
			}
		}
	}
	return f;
}

int main(){
	int t;
	cin>>t;
	int f=0;
	char s[size1];
	fgets(s,size1,stdin);
	while(t--){
		fgets(s,size1,stdin);
		if(f)
			cout<<endl;
		f=1;
		cout<<s;
		int n;
		cin>>n;
		team temp;
		fgets(s,size1,stdin);
		vector<team> v;
		map<string,int> mymap;
		temp.pt=temp.wins=temp.goal_diff=temp.goals_scored=temp.games_played=0;
		while(n--) {
			fgets(s,size1,stdin);
			s[strlen(s)-1]='\0';
			temp.name = string(s);
			v.push_back(temp);
			// cout<<temp.pt<<endl;
			mymap[string(s)] = v.size()-1;
		}
		int m;
		cin>>m;
		fgets(s,size1,stdin);
		while(m--){
			// cout<<m<<endl;
			char team1[101],team2[101];
			int g1,g2;
			// fgets(s,size1,stdin);
			// cout<<s;
			scanf("%[^#]#%d@%d#%[^\n]",team1,&g1,&g2,team2);
			fgets(s,size1,stdin);
			// cout<<"bye"<<m<<endl;
			// cout<<team1<<endl;
			int i1 = mymap[string(team1)];
			int i2 = mymap[string(team2)];
			// cout<<i1<<" "<<i2<<endl;
			if(g1>g2){
				v[i1].wins++;
				v[i1].pt+=3;
			}
			else if(g1<g2){
				v[i2].wins++;
				v[i2].pt+=3;
			}
			else{
				v[i1].pt++;
				v[i2].pt++;
			}
			// team t1,t2;
			// t1.pt=1;t2.pt=1;
			// t1.name=string("asdf");
			// t2.name=string("asdfg");
			// t1.wins=2;t2.wins=2;
			// t1.goal_diff=0;t2.goal_diff=1;
			// t1.goals_scored=t2.goals_scored=1;
			// t1.games_played=t2.games_played=1;
			// cout<<"hello"<<compare(t2,t1)<<endl;
			v[i1].goals_scored+=g1;
			v[i2].goals_scored+=g2;
			v[i1].goal_diff += g1-g2;
			v[i2].goal_diff += g2-g1;
			v[i1].games_played++;
			v[i2].games_played++;
		}
		sort(all(v),compare);
		int j = 1;
		tr(v,i){ 
			int e,f;
			e = i->pt - 3*i->wins;
			f = i->games_played - e - i->wins;
			cout<<j++<<") "<<(*i).name<<" "<<(*i).pt<<"p, "<<i->games_played<<"g ";
			cout<<"("<<i->wins<<"-"<<e<<"-"<<f<<"), "<<i->goal_diff<<"gd ("<<i->goals_scored<<"-"<<(i->goals_scored-i->goal_diff)<<")"<<endl;
		}
		mymap.clear();
	}
}