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

#define MAXN 1000010
#define MOD 1000000007
#define INF 2000000000000000100

ll inversion_count=0;
void merge(ll arr[],ll l,ll mid,ll r){
    ll* temp = new ll[r-l+1];
    ll i=l,j=mid+1;
    ll t=0;
    while(i<=mid && j<=r){
        if(arr[i]<=arr[j]){
            temp[t++]=arr[i++];
        }
        else{
            temp[t++]=arr[j++];
            inversion_count+=(mid-i+1);
        }
    }
    while(i<=mid){
        temp[t++]=arr[i++];
    }
    while(j<=r){
        temp[t++]=arr[j++];
    }
    t=0;
    for(ll i=l;i<=r;i++){
        arr[i]=temp[t++];
    }
    delete [] temp;
}
void merge_sort(ll arr[],ll l,ll r){
    if(l>=r) return;
    
    ll mid=(l+r)/2;
    
    merge_sort(arr,l,mid);      //recursive calls to sort left part
    merge_sort(arr,mid+1,r);    //recursive calls to sort right part
    
    merge(arr,l,mid,r);
}

ll n, m;
ll a[MAXN], b[MAXN], ans[MAXN];
ll pref[MAXN], suf[MAXN];

void solve(ll l, ll r, ll bl, ll br){
	if(bl > br) return;
	ll m = (bl + br)/2;
	pref[l] = 0;
	for(ll i = l + 1; i <= r; i++)
		pref[i] = pref[i - 1] + (a[i - 1] > b[m]);
	suf[r] = 0;
	for(ll i = r - 1; i >= l; i--)
		suf[i] = suf[i + 1] + (a[i] < b[m]);
	ll val = MOD;
	for(ll i = l; i <= r; i++){
		if(val > suf[i] + pref[i]){
			val = suf[i] + pref[i];
			ans[m] = i;
		}
	}

	if(bl < br){
		solve(l, ans[m], bl, m - 1);
		solve(ans[m], r, m + 1, br);
	}
}

ll v[2*MAXN];

signed main(){
	fastio;
	ll t;
	cin >> t;

	while(t--){
		inversion_count = 0;
		cin >> n >> m;
		frr(i, n) cin >> a[i];
		a[n + 1] = MOD;
		frr(i, m) cin >> b[i];
		sort(b + 1, b + m + 1);
		solve(1, n + 1, 1, m);
		//frr(i, m) dbg(ans[i]);

		ll ind = 0, it = 1;
		for(ll i = 1; i <= n; i++){
			while(it <= m && ans[it] == i){
				v[ind++] = b[it++]; 
			}
			v[ind++] = a[i];
		}
		while(it <= m) v[ind++] = b[it++];
		//fr(i, n + m) dbg(v[i]);
		
		merge_sort(v, 0, n + m - 1);
		cout << inversion_count << endl;
	}	
}
