/* 29. 03. 2008 */
# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;
#define FOR(i, a, b) for(int i = a, _b = b; i <= _b; i++)
#define FORD(i, a, b) for(int i = a, _b = b; i >= _b; i--)
#define FORN(i, a, b) for(int i = a, _b = b; i < _b; i++)
#define ALL(V) V.begin(),V.end()
#define fi first
#define se second
#define pb push_back
#define SZ(_) (int)(_.size())
#define MASK(a) (1LL << a)
#define BIT(mask, i) ((mask>>(i))&1)
template <class T1, class G2>
	bool maxi(T1 &x, const G2 y){
		if(x < y){
			x = y;
			return true;
		} return false;
	}
template <class T1, class G2>
	bool mini(T1 &x, const G2 y){
		if(x > y){
			x = y;
			return true;
		} return false;
	}

const int N = 5e5 + 5;

int n, q;
int a[N];
vi g[N];
vector <pii> qry[N];

void init(){
	cin >> n >> q;
	int u, h;
	FOR(i, 2, n){
		cin >> u;
		g[u].pb(i);
	}
	string t; cin >> t;
	FOR(i, 0, t.size() - 1) a[i + 1] = t[i] - 'a';
	FOR(i, 1, q){
		cin >> u >> h;
		qry[u].push_back({h, i});
	}
}

int h[N], sz[N], heavy[N], in[N], out[N], arr[N], timer;
int node;

void dfs(int u, int p){
	in[u] = ++ timer;
	arr[in[u]] = u;
	sz[u] = 1;
	for(const int &v : g[u]){
		if(v == p) continue;
		h[v] = h[u] + 1;
		dfs(v, u);
		sz[u]+= sz[v];
		if(sz[v] > sz[heavy[u]]) heavy[u] = v;
	}
	out[u] = timer;
}

int cntOdd[N], cntChar[30][N], ans[N];

void add(int u){
	cntOdd[h[u]]-= cntChar[a[u]][h[u]];
	cntChar[a[u]][h[u]] ^= 1;
	cntOdd[h[u]]+= cntChar[a[u]][h[u]];
}

void del(int u){
	cntOdd[h[u]]-= cntChar[a[u]][h[u]];
	cntChar[a[u]][h[u]] ^= 1;
	cntOdd[h[u]]+= cntChar[a[u]][h[u]];
}

void getAns(int u, int p, bool keep){
	for(const int &v : g[u]) if(v != p && v != heavy[u])
		getAns(v, u, 0);

	if(heavy[u])
		getAns(heavy[u], u, 1);

	for(const int &v : g[u]) if(v != p && v != heavy[u]){
		FOR(i, in[v], out[v]) add(arr[i]);
	}
	add(u);

	for(const pii &it : qry[u]){
		int h = it.fi, id = it.se;
		ans[id] = (cntOdd[h] <= 1);
	}

	if(keep == 0) FOR(i, in[u], out[u]) del(arr[i]);
}

void solve(){
	h[1] = 1;
	dfs(1, 1);
	getAns(1, 0, 0);
	FOR(i, 1, q) cout << (ans[i] ? "Yes" : "No") << "\n";
}

int main(void){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	#define task "treerequests"
	if(fopen(task".inp","r")){
		freopen(task".inp","r",stdin);
		freopen(task".out","w",stdout);
	}

	init();
	solve();

	return void(cerr << "\nTime :" << 0.001 * clock() << "s "), 0;
}
/* Watbor */
