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

string s;
int fr[30];

void solve(){
	fr(i, 30) fr[i] = 0;
	for(auto x: s) fr[x - 'a']++;

	fr(i, 26) if(fr[i] == 1){
		cout << (char)('a' + i);
		fr[i]--;
		fr(j, 26){
			while(fr[j]--) cout << (char)('a' + j);
		}
		cout << endl;
		return ;
	}

	int primeiro = -1;
	fr(i, 26){
		if(fr[i]){
			fr[i]--;
			primeiro = i;
			break;
		}
	}

	if(2 * (fr[primeiro] - 1) <= (int)s.size() - 2){
		fr[primeiro]--;
		cout << (char)(primeiro + 'a') << (char)(primeiro + 'a');
		for(int i = primeiro + 1; i < 26; i++){
			while(fr[i]) {
				fr[i]--;
				cout << (char)(i + 'a');
				if(fr[primeiro]) {
					cout << (char)(primeiro + 'a');
					fr[primeiro]--;
				}
			}
		}

		cout << endl;
		return;
	}

	int segundo = primeiro;
	for(int i = primeiro + 1; i < 26; i++){
		if(fr[i]){
			segundo = i;
			fr[i]--;
			break;
		}
	}

	if(segundo == primeiro){
		cout << s << endl;
		return;
	}

	int terceiro = segundo;
	for(int i = segundo + 1; i < 26; i++){
		if(fr[i]){
			terceiro = i;
			break;
		}
	}

	if(terceiro == segundo){
		cout << (char)(primeiro + 'a') << (char)(segundo + 'a');
		fr(j, fr[segundo]) cout << (char)(segundo + 'a');
		fr(j, fr[primeiro]) cout << (char)(primeiro + 'a');
		cout << endl;
		return;
	}
	else{
		cout << (char)(primeiro + 'a') << (char)(segundo + 'a');
		fr(j, fr[primeiro]) cout << (char)(primeiro + 'a');
		cout << (char)(terceiro + 'a');
		fr[terceiro]--;
		for(int i = segundo; i < 26; i++){
			while(fr[i]) {
				fr[i]--;
				cout << (char)(i + 'a');
			}
		}
		cout << endl;
	}

}

signed main(){
	fastio;
	int t;
	cin >> t;

	while(t--){
		cin >> s;
		solve();
	}
}
