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
#define INF 1000000000000000100

set<pii> big_spells;
set<ll> fire_spells; // Ordem contraria
set<ll> light_spells; // Ordem contraria
ll no_l = 0, ans = 0;

void insert_l(ll d){
	light_spells.insert(-d);
	ans += d;

	if(fire_spells.size() && -*(fire_spells.begin()) >= -*(light_spells.begin())){
		big_spells.insert({-*(fire_spells.begin()), 0});
		ans -= *(fire_spells.begin());
		fire_spells.erase(fire_spells.begin());
	}
	else{
		big_spells.insert({-*(light_spells.begin()), 1});
		ans -= *(light_spells.begin());
		light_spells.erase(light_spells.begin());
		no_l++;
	}
}

void erase_l(ll d){
	if(light_spells.count(-d)){
		ans -= d;
		if((*(big_spells.begin())).s == 0){
			fire_spells.insert(-(*(big_spells.begin())).f);
			ans -= (*(big_spells.begin())).f;
			big_spells.erase(big_spells.begin());
		}
		else{
			light_spells.insert(-(*(big_spells.begin())).f);
			ans -= (*(big_spells.begin())).f;
			big_spells.erase(big_spells.begin());
			no_l--;
		}

		light_spells.erase(-d);
	}
	else{
		big_spells.erase({d, 1});
		ans -= 2*d;
		no_l--;
	}
}

void insert_f(ll d){
	fire_spells.insert(-d);
	ans += d;

	if(big_spells.size() == 0) return;

	if(-*(fire_spells.begin()) >= (*(big_spells.begin())).f){
		if( (*(big_spells.begin())).s == 0){
			fire_spells.insert(-(*(big_spells.begin())).f);
			ans -= (*(big_spells.begin())).f;
			big_spells.erase(big_spells.begin());


			big_spells.insert({-*(fire_spells.begin()), 0});
			ans -= *(fire_spells.begin());
			fire_spells.erase(fire_spells.begin());
		}
		else{
			light_spells.insert(-(*(big_spells.begin())).f);
			ans -= (*(big_spells.begin())).f;
			big_spells.erase(big_spells.begin());

			big_spells.insert({-*(fire_spells.begin()), 0});
			ans -= *(fire_spells.begin());
			fire_spells.erase(fire_spells.begin());
			no_l--;
		}
	}
}

void erase_f(ll d){
	if(fire_spells.count(-d)){
		fire_spells.erase(-d);
		ans -= d;
		return;
	}

	big_spells.erase({d, 0});
	ans -= 2*d;

	if(fire_spells.size() && -*(fire_spells.begin()) >= -*(light_spells.begin())){
		big_spells.insert({-*(fire_spells.begin()), 0});
		ans -= *(fire_spells.begin());
		fire_spells.erase(fire_spells.begin());
	}
	else if(light_spells.size()){
		big_spells.insert({-*(light_spells.begin()), 1});
		ans -= *(light_spells.begin());
		light_spells.erase(light_spells.begin());
		no_l++;
	}
}

signed main(){
	fastio;
	ll n;
	cin>> n;
	while(n--){
		ll op, d;
		cin >> op >> d;
		if(op == 0){
			if(d > 0) insert_f(d);
			else erase_f(-d);
		}
		else{
			if(d > 0) insert_l(d);
			else erase_l(-d);
		}

		
		// cout << "-------------------" << endl;
		// for(auto x: fire_spells) cout << -x << ' ';
		// cout << endl;


		// for(auto x: light_spells) cout << -x << ' ';
		// cout << endl;

		// for(auto x: big_spells) cout << x.f << " ";
		// cout << endl;
		// cout << "-------------------" << endl;
		// dbg(no_l);

		//dbg(big_spells.size());
		if(no_l != big_spells.size()) cout << ans << endl;
		else{
			if(no_l == 0) cout << ans << endl;
			else{
				ll tira = (*(big_spells.begin())).f;
				if(fire_spells.size()) tira += (*(fire_spells).begin());
				cout << ans - tira << endl;
			}
		}
	}
}