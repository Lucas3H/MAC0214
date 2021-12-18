#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(ll i = 0; i < n; i++)
#define frr(i, n) for(ll i = 1; i <= n; i++)
#define frm(i, n) for(ll i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));
#define db cout << "Debug" << endl;
#define all(x) begin(x), end(x)
#define dbg(x)  cout << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define random mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define myrand(a, b) uniform_ll_distribution<ll>(a, b)(rng)

#define mp make_pair
#define pq priority_queue

#define MAXN 2001	
#define MOD 1000000007
#define INF 2000000000000000100

string ans;
ll tri[MAXN];
ll p[MAXN];
vector<ll> pos;
ll sum[10];

void back_tracking(ll ind){
	if(ind == pos.size()){
		frr(i, pos.size()){
			frr(j, i){
				if((sum[i] - sum[j - 1])%7 == 0) return;
			}
		}
//		frr(i, pos.size()) cout << sum[i] << endl;

		reverse(all(ans));
		cout << ans << endl;
		exit(0);
	}

	fr(i, 10){
		ans[pos[ind]] = i + '0';
		sum[ind + 1] = sum[ind] + p[pos[ind]] * i;
		back_tracking(ind + 1);
	}
}

signed main(){
	fastio;
	ll n;
	fr(i, MAXN) tri[i] = i * (i + 1) / 2;
	p[0] = 1;
	frr(i, MAXN - 1) p[i] = p[i - 1] * 10 % 7;

	cin >> n;
	for(ll i = MAXN - 1; i > 0;){
		if(tri[i] <= n){
			n -= tri[i];
			fr(j, i) ans.pb('7');
			pos.pb(ans.size());
			ans.pb('0');
		}
		else i--;
	}
	ans.pop_back();
	pos.pop_back();

	back_tracking(0);
}