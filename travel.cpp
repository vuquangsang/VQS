/* Vu Quang Sang from Le Khiet High School for Gifted */
#include <bits/stdc++.h>
using namespace std;

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

const ll sm = 1e9+7;
const long long inf = 1e18+7;
const ll base = 311;
const ll BLOCK = 320;
const int dx[5] = {0, -1, 1, 0 , 0};
const int dy[5] = {0, 0, 0, -1, 1};

struct node{ll x,y;};
struct pll{ll fi,se;};
template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}

const int N = 1e5 + 2;
int n, q, a[N];
vector<int> g[N];
void input()
{
    cin >> n >> q;
    fr(i, 1, n) cin >> a[i];
    int x, y;
    fr(i, 2, n) {
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
}
namespace sub1
{
    int h[N], sz[N], par[N], up[N][21];
    void DFS(int u, int p)
    {
        up[u][0] = p;
        fr(j, 1, lg(n)) up[u][j] = up[up[u][j - 1]][j- 1];
        sz[u] = 1;
        for(int v : g[u]) if(v != p) {
            h[v] = h[u] + 1;
            par[v] = u;
            DFS(v, u);
            sz[u] += sz[v];
        }
    }

    int head[N], chainID[N], pos[N], euler[N], mtc = 1, time = 0;

    void dfs_hld(int u, int p)
    {
        if(!head[mtc]) {
            head[mtc] = u;
        }

        chainID[u] = mtc;
        pos[u] = ++time;
        euler[time] = u;

        int ma = 0;
        for(int v : g[u]) if(v != p) {
            if(!ma || sz[v] > sz[ma]) ma = v;
        }
        if(ma) dfs_hld(ma, u);
        for(int v : g[u]) if(v != p && v != ma) {
            mtc++;
            dfs_hld(v, u);
        }
    }

    ll st[4*N];

    void build(int id, int l, int r)
    {
        if(l == r) {
            st[id] = max(abs(a[euler[l]] - a[par[euler[l]]]), abs(a[euler[l]] + a[par[euler[l]]]));
            return;
        }
        int mid = (r + l) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        st[id] = st[id << 1] + st[id << 1 | 1];
    }
    void upd(int id, int l,  int r, int i, int val)
    {
        if(i > r || i < l) return;
        if(l == r) {
            st[id] = val;
            return;
        }
        int mid = (r + l) >> 1;
        upd(id << 1, l, mid, i, val);
        upd(id << 1 | 1, mid + 1, r, i, val);
        st[id] = st[id << 1] + st[id << 1 | 1];
    }

    ll get(int id, int l, int r, int u, int v)
    {
        if(r < u || v < l) return 0;
        if(u <= l && r <= v) return st[id];
        int mid = (r + l) >> 1;
        return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
    }

    int lca(int x, int y)
    {
        while(chainID[x] != chainID[y]) {
            (chainID[x] > chainID[y] ? x = par[head[chainID[x]]] : y = par[head[chainID[y]]]);
        }
        return (h[x] < h[y] ? x : y);
    }
    ll calc(int x, int y)
    {
        int p = lca(x, y);

        ll ans = 0;
        while(chainID[x] != chainID[p]) {
            ans += get(1, 1, n, pos[head[chainID[x]]], pos[x]);
            x = par[head[chainID[x]]];
        }
        while(chainID[y] != chainID[p]) {
            ans += get(1, 1, n, pos[head[chainID[y]]], pos[y]);
            y = par[head[chainID[y]]];
        }
        if(h[x] < h[y]) ans += get(1, 1, n, pos[x] + 1, pos[y]);
        else ans += get(1, 1, n, pos[y] + 1, pos[x]);

        return ans;
    }
    void slv()
    {

        DFS(1, 1);
        dfs_hld(1, 1);
        build(1, 1, n);
        int k, x, y;
        while(q--) {
            cin >> k >> x >> y;
            if(k == 1) {
                upd(1, 1, n, pos[x], max(abs(y + a[par[x]]), abs(y - a[par[x]])));
                for(int v : g[x]) if(v != par[x]){
                    upd(1, 1, n, pos[v], max(abs(y + a[v]), abs(y - a[v])));
                }
                a[x] = y;
            }
            else{
                cout << calc(x, y) << el;
            }
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
    #define TASK ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    if( fopen( TASK".INP", "r") ){
        freopen( TASK".INP", "r", stdin);
        freopen( TASK".OUT", "w", stdout);
    }
    bool qs = 0;
    ll mtt = 1;
    if(qs) cin >> mtt;
    fr(i, 1, mtt){
        input();
        sub1::slv();
    //    sub2::slv();
    }
}


