#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cout << str << " : " << t << endl;}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cout << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]";cout<<endl;}

const int b = 83;
const int mod = 1e9 + 9;
const int N = 1e6 + 1;
int pb[30];
int getHash(const string &s) {
	int f[26]; memset(f, 0, sizeof f);
	for (char ch : s) f[ch - 'a']++;
	int ans = 0;
	FOR (i, 0, 25) ans = (ans + pb[i] * 1LL * f[i]) % mod;
	return ans;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	pb[0] = 1;
	FOR (i, 1, 26) pb[i] = (pb[i - 1] * 1LL * b) % mod;

	int tc = 1;
	int t; cin >> t; while (t--) {
		int l; cin >> l;
		vector<string> q(l);
		FOR (i, 0, l - 1) cin >> q[i];
		char s1, s2;
		ll n, a, b, c, d;
		cin >> s1 >> s2 >> n >> a >> b >> c >> d;
		string s(n, 'a');
		vi x(n); x[0] = s1, x[1] = s2;
		FOR (i, 2, n - 1) {
			x[i] = (a * x[i - 1] + b * x[i - 2] + c) % d;
		}
		s[0] = s1, s[1] = s2;
		FOR (i, 2, n - 1) {
			s[i] = 97 + x[i] % 26;
		}
		
		map<int, vi> mp;
		FOR (i, 0, l - 1) mp[sz(q[i])].push_back(i);
		int ans = 0;
		for (auto& it : mp) {
			vector<pair<ii, int>> hashes;
			vector<int> vis(sz(it.S));
			for (int id : it.S) {
				hashes.emplace_back(ii(q[id][0], q[id].back()), getHash(q[id]));
			}
			sort(all(hashes));
			
			int k = it.F;
			vi f(26);
			FOR (i, 0, k - 1) f[s[i] - 'a']++;
			int h = getHash(s.substr(0, k));
			
			FOR (i, 0, n - 1) {
				int j = (i + k - 1);
				if (j >= n) break;
				if (i) {
					f[s[j] - 'a']++;
					h = h + pb[s[j] - 'a']; if (h >= mod) h -= mod;
					f[s[i - 1] - 'a']--;
					h = h - pb[s[i - 1] - 'a']; if (h < 0) h += mod;
				}

				auto here = make_pair(ii(s[i], s[j]), h);
				auto yo = lower_bound(all(hashes), here);
				if (yo != hashes.end() and *yo == here) {
					vis[yo - hashes.begin()] = 1;
				}
			}
			FOR (i, 1, sz(vis) - 1) if (hashes[i] == hashes[i - 1]) vis[i] |= vis[i - 1];
			ans += accumulate(all(vis), 0);
		}
		cout << "Case #" << tc << ": ";
		++tc;
		cout << ans << "\n";
	}

	return 0;
}
