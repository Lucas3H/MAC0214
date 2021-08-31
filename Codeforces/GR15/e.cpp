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

#define mp make_pair
#define pq priority_queue

#define MAXN 100010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 1000000000000000100

int n, k;
deque<int> r[MAXN], l[MAXN];
int a[MAXN];
pii ans[MAXN];
deque<int> available;
bool comp(int x, int y){
	return r[x].front() < r[y].front();
}

int main(){
	fastio;
	cin >> n >> k;
	fr(i, n*k){
		cin >> a[i];
		r[a[i]].pb(i);
	}	
	frr(i, n) {
		available.pb(i);
		l[i] = r[i];
		r[i].pop_front();
	}
	sort(all(available), comp);
	//for(auto x: available) dbg(x);
	int lim = (int)ceil((double)n/(k-1));
	while(available.size()){
		sort(all(available), comp);
		for(int i = 0; i < lim && available.size(); i++){
			int davez = available.front();
			available.pop_front();
			ans[davez] = mp(l[davez].front(), r[davez].front());
		}

		for(auto x: available){
			l[x].pop_front();
			r[x].pop_front();
		}
	}

	frr(i, n) cout << ans[i].f+1 << " " << ans[i].s+1 << endl;
}
