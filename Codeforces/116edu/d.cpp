#include<bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define pb push_back
#define f first
#define s second
#define all(x) begin(x), end(x)
#define fr(i, n) for(int i = 0; i < n; i++)

int r, c;
vector<vector<int>> m;
vector<vector<pair<int, int>>> pref, suf;

void build(){
	cin >> r >> c;
	m.resize(r);
	pref.resize(r), suf.resize(r);
	for(int i = 0; i < r; i++){
		m[i].resize(c), pref[i].resize(c), suf[i].resize(c);
		int minimo = MOD, maximo = 0;
		for(int j = 0; j < c; j++) {
			cin >> m[i][j];
			minimo = min(minimo, m[i][j]);
			maximo = max(maximo, m[i][j]);

			pref[i][j] = {minimo, maximo};
		}
		minimo = MOD, maximo = 0;
		for(int j = c - 1; j >= 0; j--) {
			minimo = min(minimo, m[i][j]);
			maximo = max(maximo, m[i][j]);

			suf[i][j] = {minimo, maximo};
		}
	}
}

vector<int> blue;

bool tenta(int col){
	blue.clear();
	/*
		{começo, ind}
	*/
	set<pair<int, int>> esq;

	/*
		{fim, fila}
	*/
	set<pair<int, int>> dir;

	int menor_da_direita = MOD;

	vector<array<int, 3>> fila;
	for(int i = 0; i < r; i++) {
		esq.insert({-pref[i][col].f, i});
		fila.pb({pref[i][col].s, pref[i][col].f, i});
	}
	for(int i = 0; i < r; i++) {
		dir.insert({suf[i][col + 1].s, i});
	}

	sort(all(fila));
	for(auto x: fila){
		int low = x[1], high = x[0], ind = x[2];
		esq.erase({-low, ind});
		dir.erase({suf[ind][col + 1].s, ind});
		menor_da_direita = min(menor_da_direita, suf[ind][col + 1].f);
		blue.pb(ind);

		auto it = esq.lower_bound({-high, -1});
		if(it != esq.end()) continue;
		
		it = dir.lower_bound({menor_da_direita, -1});
		if(it != dir.end()) continue;

		if(blue.size() == r) return false;
		return true;
	}
	return false;
}

vector<int> color;
int main(){
	int t;
	cin >> t;

	while(t--){
		build();

		int ans = -1;
		fr(i, c - 1){
			if(tenta(i)){
				ans = i + 1;
				break;
			}
		}
		if(ans == -1) cout << "NO" << endl;
		else{
			cout<< "YES" << endl;
			color.resize(r);
			fr(i, r) color[i] = 0;
			for(auto x: blue) color[x] = 1;
			fr(i, r) {
				if(color[i]) cout << 'B';
				else cout << "R";
			}
			cout << " " << ans << endl;
		}
	}
}