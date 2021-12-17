#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = (int)n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<int,int> pii;

#define mem(v, k) memset(v, k, sizeof(v));
#define db cout << "Debug" << endl;
#define all(x) begin(x), end(x)
#define dbg(x)  cout << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define random mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define myrand(a, b) uniform_int_distribution<int>(a, b)(rng)

#define mp make_pair
#define pq priority_queue

#define MAXN 100010
#define MOD 1000000007
#define INF 2000000000000000100

struct RMQ{
    int N = 0;
    vector<vector<int>> t;
    RMQ() {}

    template<typename F>
    RMQ(vector<int>& v, F op) : N(int(v.size())), t(__lg(N) + 1) {
        t[0].resize(N);
        for (int i = 0; i < N; ++i) t[0][i] = v[i];
        for (int a = 1; a < int(t.size()); ++a) {
            t[a].resize(N - (1 << a) + 1);
            for (int b = 0; b + (1 << a) <= N; ++b)
                t[a][b] = op(t[a-1][b], t[a-1][b + (1 << (a-1))]);
        }
    }
    template<typename F>
    int query(int a, int b, F op) {
        int lg = __lg(b - a + 1);
        return op(t[lg][a], t[lg][b - (1 << lg) + 1]);;
    }
};

RMQ<logical_or<int>()> or_rmq[31];
RMQ<logical_and<int>()> and_rmq[31];
int n, q;
vector<int> a[31][2];
int acu[31][MAXN];

bool solve(int l, int r, int qa){
	int suf[32];
	suf[31] = (1 << 30) - 1;
	frm(i, 31) suf[i] = (suf[i + 1] & and_rmq[i].query(l, r)); 
	int pref = 0, tot = 0;
	fr(i, 31){
		if(acu[i][r + 1] - acu[i][l] > 1){
			int val = and_rmq[i].query(l, r); 
			if(__builtin_popcount(val) == i) if((pref | val) == (suf[i + 1] & val)) {
				//if(qa == 2 && n == 99998) cout << l << " | " << r << " " << (pref | val) << endl;
				return true;
			}
			
		}
		tot += acu[i][r + 1] - acu[i][l];
		pref |= or_rmq[i].query(l, r);
		if(tot > 0 && tot < r - l + 1 && pref == suf[i + 1]) {
			// if(qa == 2 && n == 99998) {
			// 	tot = 0;
			// 	frm(j, 31) {
			// 		tot += acu[j][r + 1] - acu[j][l];
			// 		cout << suf[j] << " " << tot << endl;
			// 	}
			// 	cout << l << " " << r << " " << pref << " " << i << " " << tot << endl;
			// }
			return true;
		}
	}
	return false;
}

signed main(){
	fastio;
	cin >> n >> q;
	fr(i, 31) 
		a[i][0].resize(n, 0), a[i][1].resize(n, (1 << 30) - 1);
	fr(i, n) {
		int x;
		cin >> x;
		a[__builtin_popcount(x)][0][i] = x;
		a[__builtin_popcount(x)][1][i] = x;

		acu[__builtin_popcount(x)][i + 1] = 1;
	}
	fr(i, 31){
		or_rmq[i] = RMQ<logical_or<int>()>(a[i][0]);
		and_rmq[i] = RMQ<logical_and<int>()>(a[i][1]);

		frr(j, n) acu[i][j] += acu[i][j - 1];
	}

	frr(i, q){
		int l, r;
		cin >> l >> r;
		cout << (solve(l - 1, r - 1, i) ? "YES" : "NO") << endl;
	}
}
