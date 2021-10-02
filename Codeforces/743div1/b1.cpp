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

#define MAXN 300010
#define MOD 1000000007
#define INF 1000000000000000100

int n;
int v[MAXN];
vector<int> ans;
void solve(){
	cin >> n;
	ans.clear();
	int sum = 0;
	fr(i, n) cin >> v[i], sum += v[i];
	if(sum%2){
		cout << "NO" << endl;
		return;
	}


	int i = 0, z = 0, ini, carry = 0;
	while(i < n){
		if(!carry) ini = i;
		else carry = 0;
		while(i < n && v[i] == v[ini]) i++;
		if(v[ini] == 0){
			z += i;
			continue;
		}

		if((i - ini)%2 == 0){
			if(i == n && z == 0){
				cout << "NO" << endl;
				return;
			}
			else if(i < n){
				for(int j = i - 2; j >= ini; j-=2){
					ans.pb(j);
				}
			}
			else{
				for(int j = ini - 1; j + 2 < i; j+=2){
					ans.pb(j);
				}
			}
			z = i;
		}
		else{
			int j = i-1;
			while(v[j+1] != 1 && v[j+2] != 1) {
				ans.pb(j);
				v[j] = v[j+1] = v[j+2] = 1;
				j+=2;
			}


			if(v[j+1] == 0){
				/*tinha impar zeros*/
				ans.pb(j);
				v[j] = v[j+2] = 0;

				for(int k = j - 2; k >= ini; k-=2){
					ans.pb(k);
					v[k] = v[k+1] = v[k+2] = 0;
				}
				i = j + 3;
				z = j + 3;
			}
			else{
				carry = 1;
				i = j;
			}
		}
	} 
	cout << "YES" << endl;
	cout << ans.size() << endl;
	for(auto x: ans) cout << x+1 << " ";
	cout << '\n';
}

signed main(){
	fastio;
	int t;
	cin >> t;
	while(t--) solve();
}
