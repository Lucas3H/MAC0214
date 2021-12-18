#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(long long i = 0; i < n; i++)
#define frr(i, n) for(long long i = 1; i <= n; i++)
#define frm(i, n) for(long long i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<long long,long long> pii;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));
#define db cout << "Debug" << endl;
#define all(x) begin(x), end(x)
#define dbg(x)  cout << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define random mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define myrand(a, b) uniform_long long_distribution<long long>(a, b)(rng)

#define mp make_pair
#define pq priority_queue

#define MAXN 100010
#define MOD 1000000007
#define INF 2000000000000000100

long long pwr[MAXN];
long long logN, n;

struct Node{
	char c;
	Node * pai;
	vector<Node *> anc;
	vector<long long> hash;
	int h;
	Node(Node * p, char C){
		c = C, pai = p, anc.resize(logN + 1, nullptr);
		hash.resize(logN + 1, -1);
		anc[0] = p;
		if(p == nullptr) h = 1;
		else h = p->h + 1;

		hash[0] = (c - 'a' + 1);
		for(long long i = 1; i <= logN; i++){
			if(anc[i - 1] != nullptr) {
				anc[i] = anc[i - 1]->anc[i - 1];
				if(anc[i - 1]->hash[i - 1] != -1)
					hash[i] = (hash[i - 1] +  pwr[1 << (i - 1)] * anc[i - 1]->hash[i - 1]) % MOD;
			}
		}
	}
};

// Return true if ans(a) > ans(b);
bool maior(Node * a, Node * b){
	long long tam = 0;
	for (long long i = logN; i >= 0; --i) {
		if(a == nullptr || b == nullptr) break;
        if (a->hash[i] != -1 && a->hash[i] == b->hash[i]){
        	a = a->anc[i];
        	b = b->anc[i];
        	tam += (1 << i);
        }
   	}
   	if(a == nullptr) return false;
   	else if(b == nullptr) return true;
   	else return a->hash[0] > b->hash[0]; 
}

Node * nd[MAXN];
string s;

string get_ans(Node * a){
	string ret = "";
	Node * aux = a;
	while(a != nullptr && ret.size() <= 10){
		ret.pb(a->c);
		a = a->anc[0];
	}
	if(ret.size() <= 10) return ret;

	ret = "";
	a = aux;
	while(ret.size() < 5){
		ret.pb(a->c);
		a = a->anc[0];
	}
	
	for (long long i = logN; i >= 0; --i) {
        if (a->anc[i] != nullptr && a->anc[i]->anc[0] != nullptr){
        	a = a->anc[i];
        }
   	}
   	
   	fr(i, 3)ret.pb('.');
   	ret.pb(a->c);
   	ret.pb(a->anc[0]->c);
   	return ret;
}

string ans[MAXN];

signed main(){
	fastio;
	
	cin >> s;
	n = s.size();
	logN = (long long)ceil(log2(n));
	pwr[0] = 1;
	frr(i, MAXN - 1) pwr[i] = pwr[i - 1] * 26 %  MOD;

	nd[n] = nullptr;
	nd[n - 1] = new Node(nd[n], s[n - 1]);  
	
	for(int i = n - 2; i >= 0; i--){
		nd[i] = new Node(nd[i + 1], s[i]);
		if(s[i] == s[i + 1] && maior(nd[i], nd[i + 2]))
			nd[i] = nd[i + 2];
	}
	fr(i, n){
		if(nd[i] == nullptr) cout << 0 << endl;
		else cout << nd[i]->h << " " << get_ans(nd[i]) << endl;
	}

}
