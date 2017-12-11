https://threads-iiith.quora.com/Tutorial-on-Trie-and-example-problems

// tested on uva_icpc/4682 and spoj/SUBXOR
/*
 Trie class	(binary recursive)
 Insert and delete = O(L), Query = O(L)
 L is length of int i.e. 32
 Basically this is binary trie (binary tree)
*/

/* root level is 32, leaf level is 0, level in every function denotes level of the child */
class Trie{
private:
	typedef struct node{
		node* child[2];
		bool isleaf;
		node(){
			isleaf = false;
			child[0] = child[1] = NULL;
		}
	}node;
	node *tree;														// tree root node
	void delete_trie(node * root){									// recursively deletes the trie
		if(root==NULL)
			return;
		delete_trie(root->child[0]);
		delete_trie(root->child[1]);
		delete root;
		return;
	}
	bool search(node *root, int level,int x){
		if(root->isleaf)
			return true;
		bool f = x&(1<<level);
		if(root->child[f]==NULL)
			return false;
		return search(root->child[f],level-1,x);
	}
	void insert_item(node *root, int level, int x){
		bool f = x&(1<<level);
		if(root->child[f]==NULL)
			root->child[f] = new node();
		if(level==0){													// if child level is 0(child is a leaf)
			root->child[f]->isleaf = true;
			return;
		}
		insert_item(root->child[f],level-1, x);
	}
	bool remove_item(node *root, int level, int x){
		bool f = x&(1<<level);
		if(root->child[f]==NULL)										// x is not in trie
			return false;
		if(level==0){													// if child level is 0(child is a leaf)
			delete root->child[f];
			return true;
		}
		if(remove_item(root->child[f],level-1,x)){
			root->child[f] = NULL;
			if(root->child[f^1]==NULL&&level!=31){
				delete root;											// if both children doesn't exist anymore delete the node
				return true;
			}
		}
		return false;
	}
public:
	bool query(int x){
		return search(tree,31,x);
	}
	void insert(int x){
		insert_item(tree,31,x);
	}
	void remove(int x){												// remove if x exists in trie
		remove_item(tree,31,x);
	}
	Trie(){
		tree = new node();
	}
	~Trie(){
		delete_trie(tree);
	}
};

/*
	Trie class(iterative) (delete can't be implemented)
	change code to include the ascii value of the s[i](-'A' or 'a')
	insert and search = O(L), where L is length of the string added or searched
*/

// Tested on spoj/MORSE

class Trie
{
private:
	int x[MAX_NUMBER_OF_NODES][MAX_ASCII_CODE];							// stores respective node no.
	int isword[MAX_NUMBER_OF_NODES];									// stored is it word? (change it to store no. of words)
	int next;															// denotes the min index which is not given yet
public:
	void insert(string & s){
		int v = 0;
		for (int i = 0; i < s.size();i++){
			if(x[v][s[i]-'A'] == -1)
				x[v][s[i]-'A'] = next++;
			v = x[v][s[i]-'A'];
		}
		isword[v] = 1;													// change it isword[v]++ to store no. of words 
	}
	bool search(string & s){						/* Change code to return no. of words with given prefix or exact matching */
		int v = 0;
		for (int i = 0; i < s.size(); i++){
			if(x[v][s[i]-'A']==-1)										// return false if there is no further path
				return false;
			v = x[v][s[i]-'A'];
		}
		if(isword[v])
			return true;
		return false;
	}
	Trie(int n){
		for (int i = 0; i <= 20*n; ++i)
		{
			isword[i] = 0;									// no one is word till now
			for (int j = 0; j < 26; ++j)
			{
				x[i][j]=-1;									// initially all values are -1
			}
		}
		isword[0] = 1;										// ""(null string) is word(change it accordingly, if not needed)
		next = 1;
	}
}


/// Tested on InterviewBit->Hotel Reviews

class Trie
{
private:
	vector<vector<int> > x;									// stores respective nodes
	vector<int> isword;										// stored is it word? (change it to store no. of words)
	vector<int> dummy;										// dummy used for initializing every node of the trie(-1 for every character)
	int next;												// denotes the min index which is not given yet a.k.a total nodes
	void increase_size(){
		x.push_back(dummy);
		isword.push_back(0);
	}
public:
	void insert(const string& s){
		int v = 0;
		for (int i = 0; i < s.length();i++){
			if(x[v][s[i]-'a'] == -1){
				increase_size();
				x[v][s[i]-'a'] = next++;
			}
			v = x[v][s[i]-'a'];
		}
		isword[v] = 1;										// change it isword[v]++ to store no. of words 
	}
	bool search(const string& s){				/* Change code to return no. of words with given prefix or exact matching */
		int v = 0;
		for (int i = 0; i < s.length(); i++){
			if(x[v][s[i]-'a']==-1)							// return false if there is no further path
				return false;
			v = x[v][s[i]-'a'];
		}
		return isword[v];
	}
	Trie(){
		dummy.resize(26,-1);
		increase_size();
		next = 1;
	}
};