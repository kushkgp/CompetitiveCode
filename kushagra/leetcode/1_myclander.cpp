#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

typedef vector<int> vi;
using vvi = vector<vi>;
pair<int, int> dir[4];

string makeLargestSpecial(string S) {
    string dp[50][50];
    vvi is_bal(50, vi(50,0));
    vi pref(51, 0);
    pref[0]=0;
    for(int i=1;i<=(int)S.size();i++){
        if(S[i-1]=='1')
            pref[i] = pref[i-1]+1;
        else
            pref[i] = pref[i-1]-1;
    }
    // cout << endl;
    for(int i=0;i<=(int)S.size();i++){
        for(int j=i+1;j<=(int)S.size();j++){
            if(pref[i]==pref[j]){
            	int ans = 1;
            	int sum = 0;
            	for(int k=i;k<j;k++){
            		sum+=2*(S[k]-'0')-1;
            		if(sum<0){
            			ans=0;
            			break;
            		}
            	}
            	if(ans==1){
		        	// cout << i << "->" << j-1 << endl;
		            is_bal[i][j-1] = 1;
            	}
            }
        }
    }
    for(int l=2;l<=S.size();l+=2){
    	for(int i=0;i<(int)S.size();i++){
    		int j = i+l-1;
    		if(j>S.size())
    			break;
    		dp[i][j] = S.substr(i,j-i+1);
    		for(int k=i+1;k<j-1;k++){
                string possible = S.substr(k+1,j-k) + S.substr(i,k-i+1);
                if(is_bal[i][k]&&is_bal[k+1][j] &&  possible > dp[i][j]){
                	// cout << i << " " << k << ":" << k+1 << " " << j << endl;
                    dp[i][j] = possible;
                }
            }
            if(is_bal[i][j] && j-i>1 && S.substr(i+1,j-i-1) < dp[i+1][j-1])
            	dp[i][j] = "1"+ dp[i+1][j-1]+"0";
    	}
    }
    // cout << dp[1][6] << endl;
    if(S=="")
        return S;
    return dp[0][(int)S.size()-1];
}




int getstate(vector<vector<int>>& board){
    int ans = 0;
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++)
            ans |= (board[i][j]<<(3*(3*i+j)));
    }
    return ans;
}

vi get_nbr(int state){
    vector<vector<int>> board(2, vi(3,0));
    vi ans;
    int zi, zj = 0;
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            board[i][j] = ((state >> (3*(3*i+j))) & ((1<<3)-1)); 
            cout << board[i][j] << " ";
            if(board[i][j]==0){
                zi = i, zj = j;
            }
        }
        cout << endl;
    }
    int crt = getstate(board);

    for(int i=0;i<4;i++){
    	int x = zi + dir[i].ff;
    	int y = zj + dir[i].ss;
    	if(x>=0 && x<=1 && y>=0 && y<=2){
    		vvi nboard = board;
    		swap(nboard[zi][zj], nboard[x][y]);
    		ans.pb(getstate(nboard));
    	}
    }
    return ans;
}

int slidingPuzzle(vector<vector<int>>& board) {
    vector<int> vis(1<<19,-1);
    queue<int> q;
    q.push(getstate(board));
    vis[getstate(board)] = 0;
    while(!q.empty()){
        int crt = q.front();
        q.pop();
        vi a = get_nbr(crt);
        for(auto it : a){
            if(vis[it]==-1){
                vis[it] = vis[crt] + 1;
                q.push(it);
            }
        }
    }
    board[0][0] = 1;
    board[0][1] = 2;
    board[0][2] = 3;
    board[1][0] = 4;
    board[1][1] = 5;
    board[1][2] = 0;

    return vis[getstate(board)];

}

int main(){
	// dir[0] = mp(0,1);
	// dir[1] = mp(0,-1);
	// dir[2] = mp(-1,0);
	// dir[3] = mp(1,0);
	// vector<vi> board(2,vi(3,0));
	// board[0][0] = 1;
 //    board[0][1] = 2;
 //    board[0][2] = 3;
 //    board[1][0] = 4;
 //    board[1][1] = 5;
 //    board[1][2] = 0;

 //    vi a = get_nbr(getstate(board));

 //    for(auto it : a){
 //    	get_nbr(it);
 //    	cout << endl;
 //    }

	cout << makeLargestSpecial("11011000") << endl;
	return 0;
}