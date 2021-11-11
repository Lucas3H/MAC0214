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

#define MAXN 1010
#define MOD 1000000007
#define INF 2000000000000000100

int n, m, k;

string get_byte(char c){
	if(c == '0') return "0000";
	if(c == '1') return "0001";
	if(c == '2') return "0010";
	if(c == '3') return "0011";
	if(c == '4') return "0100";
	if(c == '5') return "0101";
	if(c == '6') return "0110";
	if(c == '7') return "0111";
	if(c == '8') return "1000";
	if(c == '9') return "1001";
	if(c == 'a') return "1010";
	if(c == 'b') return "1011";
	if(c == 'c') return "1100";
	if(c == 'd') return "1101";
	if(c == 'e') return "1110";
	else return "1111";
}
void build(string & s, bitset<160> & v){
	int ind = 0;
	while(ind < 4 * k){
		string x = get_byte(s[ind / 4]);
		fr(i, 4) v[ind++] = (x[i] - '0');
	}
}

bitset<160> b[MAXN];
bitset<160> q[MAXN];
vector<pair<bitset<160>, int>> base;
int ans[MAXN];

bool is_base(bitset<160> & v){
	for(auto x : base){
		if(v[x.s]) v ^= x.f;
	}
	if(v.count()) return true;
	else return false;
}

int first_not_base = -1;

signed main(){
	fastio;
	mem(ans, -1);
	cin >> n >> m >> k;
	string s;
	fr(i, n){
		cin >> s;
		build(s, b[i]);
	}
	fr(i, m){
		cin >> s;
		build(s, q[i]);
	}

	fr(i, n){
		bitset<160> aux = b[i];
			
		if(is_base(aux)){
			int lsb = -1;
			fr(j, 160){
				if(aux[j] == 1){
					lsb = j;
					break;
				}
			}
			base.pb({aux, lsb});
			fr(j, m) {
				if(ans[j] == -1){
					aux = q[j];
					// dbg(lsb);
					// cout << aux << endl;
					// cout << base[0].f << endl;
					if(!is_base(aux)) ans[j] = i + 1;
				}
			}
		}
		else if(first_not_base == -1) first_not_base = i + 1;
	}
	fr(i, m) {
		if(q[i].count() == 0) cout << first_not_base << endl;
		else cout << ans[i] << endl;
	}
}
