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
	Node(Node * p, char C){
		c = C, pai = p, anc.resize(logN + 1, nullptr);
		hash.resize(logN + 1, -1);
		anc[0] = p;
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

long long max_suf(Node * a, Node * b){
	long long tam = 0;
	for (long long i = logN; i >= 0; --i) {
        if (a->hash[i] != -1 && a->hash[i] == b->hash[i]){
        	a = a->anc[i];
        	b = b->anc[i];
        	tam += (1 << i);
        	if(a == nullptr || b == nullptr) break;
        }
   	}
   	return tam;
}

Node * nd[MAXN];

signed main(){
	fastio;
	long long q;
	
	cin >> n >> q;
	logN = (long long)ceil(log2(n));
	pwr[0] = 1;
	frr(i, MAXN - 1) pwr[i] = pwr[i - 1] * 26 %  MOD;

	nd[0] = nullptr;
	frr(i, n){
		char c;
		long long ind;
		cin >> c >> ind;
		nd[i] = new Node(nd[ind], c);
	}

	frr(i, q){
		long long a, b;
		cin >> a >> b;
		cout << max_suf(nd[a], nd[b]) << endl;
	}
}
