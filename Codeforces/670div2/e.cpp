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

#define MAXN 100010
#define MOD 1000000007
#define INF 2000000000000000100

ll np[MAXN];
vector<ll> p;

void sieve(ll n){
	for(ll i = 2; i < n; i++){
		if(!np[i]){
			p.pb(i);
			for(ll j = 2 *i; j < n; j += i) np[j] = 1;
		}
	}
}

ll ask(ll x){
	cout << "B " << x << endl;
	cin >> x;
	return x;
}

ll askA(ll x){
	cout << "A " << x << endl;
	cin >> x;
	return x;
}


ll get_max(ll pr, ll n){
	ll ret = 1, pwr = pr, aux = ask(pr);
	while(pwr <= n && ask(pwr) > 0){
		pwr *= pr;
		ret *= pr;
	}
	return ret;
}

signed main(){
	fastio;
	ll n, ans = 1;
	cin >> n;

	if(n == 1){
		cout << "C " << 1 << endl;
		return 0;
	}

	sieve(n + 1);
	
	ll i = 0;
	while(p[i] * p[i] <= n){
		ans *= get_max(p[i], n);
		i++;
	}

	ll last = askA(1), fim = p.size();
	while(i < fim){
		ll ini = i;
		while(i < (fim + ini + 1)/2) {
			if(ask(p[i]) >= 2){
				ans *= p[i];
				cout << "C " << ans << endl;
				return 0;
			}
			i++;
		}
		ll aux = askA(1);
		if(last - aux != i - ini){
			while(ini < i){
				if(askA(p[ini]) == 1){
					ans *= p[ini];
					break;
				}
				ini++;
			}
			break;
		}
		last = aux;
	}

	cout << "C " << ans << endl;
}
