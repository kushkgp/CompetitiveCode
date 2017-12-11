#include <bits/stdc++.h>
using namespace std;
typedef struct node{
	int total;
	int left;
	int no;
	int maxdp[2][2];
	int mindp[2][2];
}node;

void DFS()								// preorder
{
	stack<node> stack;
 	int i=0;
	char c;
	cin>>c;
	node s;
	s.total = c-'0';
	s.left = s.total;
	s.no = i++;
	stack.push(s);
	while (!stack.empty())
	{
		s = stack.top();
		node p;
		stack.pop();
		if(!s.left){
			int maxdp[2],mindp[2];
			if(s.total == 0){
				maxdp[0] = 0;
				maxdp[1] = 1;
				mindp[0] = 0;
				mindp[1] = 1;
			}
			else if(s.total == 1){
				maxdp[0] = max(s.maxdp[0][0],s.maxdp[0][1]);
				maxdp[1] = 1+s.maxdp[0][0];
				mindp[0] = min(s.mindp[0][0],s.mindp[0][1]);
				mindp[1] = 1+s.mindp[0][0];
			}
			else{
				maxdp[0] = max(s.maxdp[0][0]+s.maxdp[1][1],s.maxdp[0][1]+s.maxdp[1][0]);
				maxdp[1] = 1+s.maxdp[0][0]+s.maxdp[1][0];
				mindp[0] = min(s.mindp[0][0]+s.mindp[1][1],s.mindp[1][0]+s.mindp[0][1]);
				mindp[1] = 1+s.mindp[0][0]+s.mindp[1][0];
			}
			if(stack.empty()){
				cout<<max(maxdp[0],maxdp[1])<<" "<<min(mindp[0],mindp[1])<<endl;
				return;
			}
			p = stack.top();
			stack.pop();
			int f=0;
			if(p.total==2&&!p.left)
				f=1;
			p.maxdp[f][0] = maxdp[0];
			p.maxdp[f][1] = maxdp[1];
			p.mindp[f][0] = mindp[0];
			p.mindp[f][1] = mindp[1];
			stack.push(p);
		}
		else{
			s.left--;
			stack.push(s);
			cin>>c;
			s.total = c -'0';
			s.left = s.total;
			s.no = i++;
			stack.push(s);
		}
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		char c;
		DFS();
	}
	return 0;
}