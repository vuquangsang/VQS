/* Try to do something */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ll,ll>  pll;
typedef vector<int> vi;
typedef vector<pii> vii;

#define     lg(x) __lg(x)
#define     alla(a,n) a+1,a+n+1
#define     el "\n"
#define     all(x) x.begin(),x.end()
#define     pb push_back
#define     ll long long
#define     fi first
#define     se second
#define     Mask(i) (1ll<<(i))
#define     c_bit(i) __builtin_popcountll(i)
#define     fr(i,a,b) for(int i = (a), _b = (b); i <= _b; i++)
#define     frd(i,a,b) for(int i = (a), _b = (b); i >= _b; i--)
#define     REP(i, a, b) for(int i = (a), _b = (b); i < _b; i++)
#define     sz(a) (int)a.size()
#define     uni(V) sort(all(V)), V.resize(unique(all(V)) - V.begin())


const int N = 2e6 + 5, base = 311, sm = 1e9 + 7;
const long long inf  = 1e18 + 2;
const int dx[5] = {0, -1, 1, 0 , 0};
const int dy[5] = {0, 0, 0, -1, 1};

struct node{ll x,y;};
template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}

int n, m;
vector<int> g[N];
int color[N];
void input()
{
    cin >> n >> m;
    fr(i, 1, n) cin >> color[i];
    fr(i, 2, n) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
}
namespace sub1
{
    const int MAX = 1e5 + 2;
    int h[MAX], up[MAX][21], sz[MAX], chain[MAX], chainID[MAX], in[MAX], out[MAX], time = 0, mtc = 1, pos[MAX];
    void DFS(int u, int  p)
    {
        up[u][0] = p;
        sz[u] = 1;
        fr(j, 1, lg(n)) up[u][j] = up[up[u][j - 1]][j - 1];
        for(int v : g[u]) if(v != p) {
            h[v] = h[u] + 1;
            DFS(v, u);
            sz[u]+=sz[v];
        }
    }

    set<int> st[N];
    void hld(int u, int p)
    {
        if(!chain[mtc]) {
            chain[mtc] = u;
        }
        st[color[u]].insert(++time);
        pos[u] = time;
        int ma = 0;
        for(int v : g[u]) if(v != p) {
            if(!ma || sz[v] > sz[ma]) ma = v;
        }
        if(ma) hld(ma, u);
        for(int v : g[u]) if(v != p && v != ma) {
            mtc++;
            hld(v, u);
        }
    }
    int lca(int u, int v)
    {
        int res = 0;
        if(h[u] < h[v]) swap(u, v);
        frd(j, lg(n), 0) {
            if(h[up[u][j]] >= h[u]) u = up[u][j];
        }
        if(u == v) return u;
        frd(j, lg(n), 0) {
            if(up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }
        return up[u][0];
    }
    bool inChain(int l, int r, int color)
    {
        auto it = st[color].lower_bound(l);
        if(it == st[color].end()) return 0;
        return *it <= r;
    }
    bool Query(int u, int x, int color)
    {
        while(chainID[x] != chainID[u]) {
            auto it = st[color].lower_bound(color);
            if(it != st[color].end()) return 1;

        }
    }
    void slv()
    {
        DFS(1, 0);
        hld(1, 0);
        for(int i = 1; i <= m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            cout << Query(a, b, c);
        }
    }
}
namespace sub2
{
    void slv()
    {

    }
}

main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    #define TASK ""
    if(fopen(TASK".INP", "r")) {
        freopen(TASK".INP", "r", stdin);
        freopen(TASK".OUT", "w", stdout);
    }

    bool qs = 0;

    int tt = 1;
    if(qs) cin >> tt;
    while(tt--) {
        input();
        sub1::slv();
    }
    cerr << "\nTime" << 0.001 * clock() << "s "; return 0;


}




