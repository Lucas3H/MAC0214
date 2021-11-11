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

#define MAXN 1000010
#define MOD 1000000007
#define INF 2000000000000000100

string a;
deque<char> s, t;
int ans = 0;
string x, y;

void print(string & a){
	int j = 0;
	while(a[j] == '0') j++;
	while(j < a.size()) cout << a[j++];
	cout << endl;
	exit (0);
}

void maior(){
	fr(i, x.size()){
		if(x[i] < y[i]){
			print(x);
		}
		else if(x[i] > y[i]){
			print(y);
		}
	}
	print(x);
}

void soma1(string &S){
	int n = S.size();
	int p = 0;

	reverse(all(S));
	
	while (p < n and S[p] == '9')
		p++;

	for (int i = 0; i < p; i++)
		S[i] = '0';

	if (p == n)
		S.pb('1');
	else{
		S[p] = (char)((int)(S[p]) + 1);
	}

	reverse(all(S));
}

signed main(){
	fastio;
	cin >> a;
	for(auto x: a) s.push_back(x);
	cin >> a;
	for(auto x: a) t.push_back(x);

	while(s.size() < t.size()) s.push_front('0');
	while(s.size() > t.size()) t.push_front('0');

	int carry = 0;

	while(s.size() && t.size()){
		int ds = s.back() - '0', dt = t.back() - '0';
		x.pb(s.back()), y.pb(t.back());
		s.pop_back(), t.pop_back();

		if(ds + dt + carry >= 10) carry = 1;
		else carry = 0;
		if(carry) ans = x.size();
	}
	if(ans == 0) {
		cout << 0 << endl;
		return 0;
	}

	while(x.size() > ans) x.pop_back(), y.pop_back();
	reverse(all(x)), reverse(all(y));

	for(auto & z : x){
		int aux = z - '0';
		aux = 9 - aux;
		z = aux + '0';
	}

	for(auto & z : y){
		int aux = z - '0';
		aux = 9 - aux;
		z = aux + '0';
	}

	soma1(x);
	soma1(y);

	maior();
}
