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

#define MAXN 100010
#define MOD 1000000007
#define INF 2000000000000000100

int n;
string s[MAXN];

void test(){
	int ok = 0;
	fr(i, n - 1){
		if(stoll(s[i]) > stoll(s[i + 1])){
			ok = 1;
			break;
		}
	}	

	if(ok){
		fr(i, n) cout << s[i] << " ";
		cout << endl;
		exit (0);
	}
}

void change(string & t){
	if(t.size() == 1){
		char aux = t[0];
		t[0] = '0';
		test();
		t[0] = aux;
	}
	fr(i, t.size()){
		if(i == 0) {
			frr(j, 9){
				char aux = t[i];
				t[i] = char('0' + j);
				test();
				t[i] = aux;
			}
		}
		else{
			fr(j, 10){
				char aux = t[i];
				t[i] = char('0' + j);
				test();
				t[i] = aux;
			}
		}
	}
}

signed main(){
	fastio;
	cin >> n;
	fr(i, n) cin >> s[i];
	fr(i, n) change(s[i]);
	cout<< "impossible" << endl;
}
