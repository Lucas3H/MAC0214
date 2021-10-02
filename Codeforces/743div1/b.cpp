#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));
#define db cout << "Debug" << endl;
#define all(x) begin(x), end(x)
#define dbg(x)  cout << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define random mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define myrand(a, b) uniform_int_distribution<int>(a, b)(rng)

#define mp make_pair
#define pq priority_queue

#define MAXN 200010
#define MOD 1000000007
#define INF 1000000000000000100

int v[MAXN];
int n;

deque<pii> b;
vector<int> ans;

void solve(){
	cin>> n;
	int sum = 0;
	fr(i, n) cin >> v[i], sum += v[i];

	if(sum%2 == 1){
		cout << "NO" << endl;
		return;
	}

	b.clear(), ans.clear();
	int i = 0;
	while(i < n){
		int ini = i;
		while(i < n && v[i] == v[ini]) i++;

		/*tira os blocos pares*/
		if(v[ini] == 1 && (i - ini)%2 == 0){
			if(ini > 0){
				fr(j, (i - ini)/2) ans.pb(ini + 2*j - 1);
			}
			else if(i < n){
				int it = i;
				fr(j, (i - ini)/2) ans.pb(it - 2), it -= 2;
			}
			else{
				cout << "NO" << endl;
				return;
			}
			for(int j = ini; j < i; j++) v[j] = 0;
		}
	}
	i = 0;
	while(i < n){
		int ini = i;
		while(i < n && v[i] == v[ini]) i++;
		b.pb({v[ini], i - ini});
	}

	int pos = 0;


	while(b.size()){
		pii um = b.front();
		b.pop_front();

		if(um.f == 0){
			pos += um.s;
			continue;
		}

		pii zero = b.front();
		b.pop_front();

		pii nxt = b.front();
		b.pop_front();

		if(zero.s%2 == 0){
			fr(j, zero.s/2){
				ans.pb(pos + um.s + 2*j - 1);
			}
			if(pos == 0 && um.s + zero.s + nxt.s == n){
				cout << "NO" << endl;
				return;
			}
			else if(pos > 0){
				int tot = um.s + zero.s + nxt.s;
				fr(j, tot/2) ans.pb(pos - 1 + 2*j);
			}
			else{
				int tot = um.s + zero.s + nxt.s;
				int it = pos + um.s + zero.s + nxt.s;
				fr(j, tot/2) ans.pb(it - 2*j - 2);
			}

			pos += um.s + zero.s + nxt.s;
		}
		else{
			fr(j, zero.s/2){
				ans.pb(pos + um.s + 2*j - 1);
			}
			ans.pb(pos + um.s + zero.s - 2);
			
			int tot = um.s + zero.s - 2;
			int it = pos + tot;
			fr(j, tot/2) ans.pb(it - 2*j - 2);

			tot = nxt.s - 1;
			it = pos + um.s + zero.s + 1;
			fr(j, tot/2) ans.pb(it + 2*j);

			pos += um.s + zero.s + nxt.s;
		}
	}

	cout << "YES" << endl;
	cout << ans.size() << endl;
	for(auto x: ans) cout << x + 1 << " ";
	cout << endl;
}


signed main(){
	fastio;
	int t;
	cin >> t;

	while(t--){
		solve();
	}
}
