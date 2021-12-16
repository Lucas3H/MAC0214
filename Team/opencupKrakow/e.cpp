#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define endl '\n'
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()

#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

ll n, p, q;
vector<ll> a;
vector<ll> b;
ll opt;

set<int> resp;
vector<int> print;

int ans[200200];

bool advance(ll soma, ll pessoa, ll index){
	ll sum = soma + a[index];
	ll people = pessoa + 1;

	//dbg(sum);
	//dbg(people);

	if(a[index] * people * q <= p * sum) return true;
	return false; 
}

int find_opt(){
	int l = 0;
	int r = 0;
	int mx = 0;
	int tent = 0;

	ll soma = 0;
	ll pessoa = 0;

	while(r < n){

		while(r < n && advance(soma, pessoa, r)){
			soma += a[r];
			pessoa++;
			r++;
		}

		tent = r - l;
		mx = max(mx, tent);
		
		soma -= a[l];
		pessoa--;
		l++;
	}

	return mx;
}

bool decrease(ll soma, ll pessoas, ll l, int rr){
	ll sum = soma - a[l] + a[l - 1];

	if(a[rr] * q * pessoas <= p * sum) return true;
	return false;
}


void find_ans(){

	int rr = n - 1; // ultimo no intervalo
	int rl = n - 1; // primeiro a não estar

	int l; // ponta esquerda sozinha

	ll soma = 0;
	ll pessoas = 0;

	while(rr - rl + 1 != opt){
		soma += a[rl];
		pessoas++;
		rl--;
	}

	l = rl;
	soma += a[l];
	pessoas++;

	while(rl >= 0){
		if(a[rr] * q * pessoas <= p * soma){
			while(l > 0 && decrease(soma, pessoas, l, rr)){
				soma -= a[l];
				l--;
				soma += a[l];
			}

			ans[l]++;
			ans[rr + 1]--;
		}

		soma -= a[rr];
		rr--;
		soma += a[rl];
		rl--;

		while(l > rl){
			soma -= a[l];
			l--;
			if(l >= 0) soma += a[l];
		}
		
	}
}

int main(){

	fastio;

	int T;
	cin >> T;

	while(T--){
		cin >> n;

		fr(i, n + 2) ans[i] = 0;
		a.clear();
		b.clear();
		a.resize(n);
		b.resize(n);
		resp.clear();
		print.clear();


		fr(i, n) cin >> a[i];
		fr(i, n) b[i] = a[i];

		cin >> p >> q;

		sort(all(a));
		opt = find_opt();

		if(opt == 1){
			cout << 0 << endl;
			cout << endl;
		}
		else{
			find_ans();

			int at = 0;

			fr(i, n){
				at += ans[i];
				if(at != 0) resp.insert(a[i]);
			}

			for(int i = 0; i < n; i++){
				if(resp.find(b[i]) == resp.end()) print.pb(i + 1);
			}

			cout << print.size() << endl;

			for(int i = 0; i < print.size(); i++){
				if(i != 0) cout << ' ';
				cout << print[i];
			}
			gnl;
		}

	}

}
