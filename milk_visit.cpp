
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

const int N = 1e5 + 5;
int n, q;
int color[N];
vector<int> g[N];
void input()
{
    cin >> n >> q;
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

    int sz[N], h[N], par[N];
    void DFS(int u, int p)
    {
        sz[u] = 1;
        for(int v : g[u]) if(v != p) {
            h[v] = h[u] + 1;
            par[v] = u;
            DFS(v, u);
            sz[u]+=sz[v];
        }
    }

    int chain[N], chainID[N], pos[N], time = 0, mtc = 1, euler[N];
    void hld(int u, int p)
    {
        if(!chain[mtc]) {
            chain[mtc] = u;
        }
        chainID[u] = mtc;
        pos[u] = ++time;
        euler[time] = u;

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
        while(chainID[u] != chainID[v]) {
            (chainID[u] > chainID[v] ? u = par[chain[chainID[u]]] : v = par[chain[chainID[v]]]);
        }
        return (h[u] < h[v] ? u : v);
    }
    set<int> st[4*N];

    set<int> MER(set<int> a, set<int> b)
    {
        if(a.size() < b.size()) swap(a, b);
        set<int> res = a;
        for(int x : b) res.insert(x);
        return res;
    }
    void build(int id, int l, int r)
    {
        if(l == r) {
            st[id].insert(color[euler[l]]);
            return;
        }
        int mid = (r + l) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        st[id] = MER(st[id << 1], st[id << 1 | 1]);
    }
    bool get(int id, int l, int r, int u, int v, int val)
    {
        if(r < u || v < l) return 0;
        if(u <= l && r <= v) return (st[id].find(val) != st[id].end());
        int mid = (r + l) >> 1;
        return get(id << 1, l, mid, u, v, val) | get(id << 1 | 1, mid + 1, r, u, v, val);
    }
    bool calc(int x, int y, int c)
    {
        int u = lca(x, y);

        bool ok = 0;
        while(chainID[x] != chainID[u]) {
            ok |= get(1, 1, n, pos[chain[chainID[x]]], pos[x], c);
            if(ok) return 1;
            x = par[chain[chainID[x]]];
        }
        while(chainID[y] != chainID[u]) {
            ok |= get(1, 1, n, pos[chain[chainID[y]]], pos[y], c);
            if(ok) return 1;
            y = par[chain[chainID[y]]];
        }
        if(h[x] > h[y]) swap(x, y);
        if(h[x] <= h[y]) ok |= get(1, 1, n, pos[x], pos[y], c);
//        else ok |= get(1, 1, n, pos[y], pos[x], c);
        return ok;
    }
    void slv()
    {
        DFS(1, 0);
        hld(1, 0);
        build(1, 1, n);
        while(q--) {
            int a, b, c;
            cin >> a >> b >> c;
            cout << calc(a, b, c);
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
    #define TASK "task"
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


