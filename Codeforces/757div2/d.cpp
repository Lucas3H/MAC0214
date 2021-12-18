#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(ll i = 0; i < n; i++)
#define frr(i, n) for(ll i = 1; i <= n; i++)
#define frm(i, n) for(ll i = (ll)n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<ll,ll> pii;

#define mem(v, k) memset(v, k, sizeof(v));
#define db cout << "Debug" << endl;
#define all(x) begin(x), end(x)
#define dbg(x)  cout << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define random mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define myrand(a, b) uniform_ll_distribution<ll>(a, b)(rng)

#define mp make_pair
#define pq priority_queue

#define MAXN 20000001
#define MOD 1000000007
#define INF 2000000000000000100

// vector<ll> p;
// ll last[MAXN];

ll num[MAXN], dp[MAXN];
ll n;

int lp[MAXN];
vector<int> pr;

void sieve(){
    for (int i = 2; i < MAXN; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for(auto p : pr){
        	if(p > lp[i] || i * p >= MAXN) break;
        	lp[i * p] = p;
        }
    }
}

vector<pair<int, int>> ret;
void decompose(int n){
    ret.clear();
    while(n > 1){
        pair<int, int> p = {lp[n], 0};
        while(lp[n] == p.first){
            p.second++;
            n /= p.first;
        }
        ret.push_back(p);
    }
}

int cur = 1;
void build(ll i){
	if(i == ret.size()) {
		num[cur]++;
		return;
	}
	build(i + 1);
	int pre = cur;
	fr(j, ret[i].s){
		cur *= ret[i].f;
		build(i + 1);
	}
	cur = pre;
}

signed main(){
	sieve();
	scanf("%d", &n);
	fr(i, n){
		int x;
		scanf("%d", &x);
		decompose(x);
		cur = 1;
		build(0);
	}

	for(ll i = MAXN - 1; i >= 1; i--){
		if(num[i] == 0) continue;
		dp[i] = max(dp[i], i * num[i]);
		ll tmp = i;
		while(tmp > 1){
			ll prev = i / lp[tmp], p = lp[tmp];
			if(num[prev])
				dp[prev] = max(dp[prev], dp[i] + (num[prev] - num[i]) * prev);

			while(tmp%p == 0) tmp /= p;
		}
	}

	printf("%lld\n", dp[1]);
}