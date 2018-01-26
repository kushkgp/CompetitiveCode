/*
	Author	:	Gulab Arora
	Institue:	IIT Kharagpur
*/

#include <bits/stdc++.h>
#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define allr(c) (c).rbegin(),(c).rend()
#define asort(c) sort(all(c))
#define dsort(c) sort(allr(c))
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define FOR(i, n) for (int i = 0; i < n; i++)
#define ff first
#define ss second
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<int,ll> pill;
typedef vector<pii> vpii;

class Trie{
private:
	typedef struct node{
		node* child[2];
		int no_of[2];
		node(){
			child[0] = child[1] = NULL;
			no_of[0] = no_of[1] = 0;
		}
	}node;
	void delete_trie(node * root){
		if(root==NULL)
			return;
		delete_trie(root->child[0]);
		delete_trie(root->child[1]);
		delete root;
		return;
	}
	node *tree;
	int search(node *root, int level,int x,int k){
		if(root==NULL)
			return 0;
		bool f = x&(1<<level);
		bool g = k&(1<<level);
		if(g)
			return root->no_of[f]+search(root->child[f^1],level-1,x,k);
		return search(root->child[f],level-1,x,k);
	}
	void insert_item(node *root, int level, int x){
		if(level==-1)
			return;
		bool f = x&(1<<level);
		root->no_of[f]++;
		if(root->child[f]==NULL)
			root->child[f] = new node();
		insert_item(root->child[f],level-1, x);
	}
public:
	int query(int x, int k){
		return search(tree,31,x,k);
	}
	void insert(int x){
		insert_item(tree,31,x);
	}
	Trie(){
		tree = new node();
	}
	~Trie(){
		delete_trie(tree);
	}
};


int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		Trie T;
		int temp,x = 0;
		ll result = 0;
		T.insert(0);
		for (int i = 0; i < n; ++i)
		{
			cin>>temp;
			x^=temp;
			result += T.query(x,k);
			T.insert(x);
		}
		cout<<result<<endl;
	}
	return 0;
}