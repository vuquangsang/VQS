/* Vu Quang Sang from Le Khiet High School for Gifted */
#include <bits/stdc++.h>
using namespace std;

#define     lg(x) __lg(x)
#define     alla(a,n) a+1,a+n+1
#define     el "\n"
#define     all(x) x.begin(),x.end()
#define     pb push_back
#define     ll unsigned long long
#define     fi first
#define     se second
#define     Mask(i) (1ll<<(i))
#define     c_bit(i) __builtin_popcountll(i)
#define     fr(i,a,b) for(int i = (a), _b = (b); i <= _b; i++)
#define     frd(i,a,b) for(int i = (a), _b = (b); i >= _b; i--)
#define     REP(i, a, b) for(int i = (a), _b = (b); i < _b; i++)

const ll MN = 1e9+7;
const long long inf = 1e18+7;
const ll base = 311;
const ll BLOCK = 320;
const int dx[5] = {0, -1, 1, 0 , 0};
const int dy[5] = {0, 0, 0, -1, 1};

struct node{ll x,y;};
struct pll{ll fi,se;};
ll mod(ll a, ll b) {return ((a%MN)*(b%MN))%MN;}
template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}
const int MAX = 2e5 + 2;
int n, q, a[MAX];
vector<int> g[MAX];
void input()
{
    cin >> n >> q;
    int x, y;
    fr(i, 2, n) {
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    fr(i, 1, n) cin >> a[i];
}
namespace sub1
{

    int h[MAX], euler[MAX], pos[MAX], chain[MAX], chainID[MAX], time = 0, sz[MAX], in[MAX], out[MAX];
    int mtc = 1, up[MAX][21];
    ll t[4*MAX], lazy[4*MAX];
    void DFS(int u, int p)
    {
        sz[u] = 1;
        up[u][0] = p;
        fr(j, 1, lg(n)) up[u][j] = up[up[u][j - 1]][j - 1];
        for(int v : g[u]) if(v != p) {
            h[v] = h[u] + 1;
            DFS(v, u);
            sz[u]+=sz[v];
        }
    }
    int lca(int u, int v)
    {
        if(h[u] < h[v]) swap(u, v);
        frd(j, lg(n), 0) {
            if(h[up[u][j]] >= h[v]) u = up[u][j];
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
    void hld(int u, int p)
    {
        if(!chain[mtc]) {
            chain[mtc] = u;
        }
        euler[++time] = u;
        in[u] = time;
        pos[u] = time;
        chainID[u] = mtc;
        int ans = 0;
        for(int v : g[u]) if(v != p) {
            if(!ans || sz[v] > sz[ans]) ans = v;
        }
        if(ans) hld(ans, u);
        for(int v : g[u]) if(v != ans && v != p) {
            mtc++;
            hld(v, u);
        }
        out[u] = time;
    }
    void down(ll id)
    {
        if(lazy[id]) {
            ll x = lazy[id];
            t[id << 1] = t[id << 1 | 1] = lazy[id << 1] = lazy[id << 1 | 1] = 0;
            t[id << 1]|=x;
            t[id << 1 | 1]|=x;
            lazy[id << 1]|=x;
            lazy[id << 1 | 1]|=x;
            lazy[id] = 0;
        }
    }
    ll MER(ll x, ll y)
    {
        ll res = (x|y);
        return res;
    }
    void build(ll id, ll l, ll r)
    {
        if(l == r) {
            t[id]|=(1LL << (a[euler[l]]));
            return;
        }
        int m = (r + l) >> 1;
        build(id << 1, l,m);
        build(id << 1 | 1, m + 1, r);
        t[id] = MER(t[id << 1], t[id << 1 | 1]);
    }
    void upd(ll id, ll l, ll r, ll u, ll v, ll val)
    {
        if(r < u || v < l) return;
        if(u <= l && r <= v) {
            t[id] = 0;
            lazy[id] = 0;
            t[id]|=(1LL << val);
            lazy[id]|=(1LL << val);
            return;
        }
        int m = (r + l) >> 1;
        down(id);
        upd(id << 1, l, m, u, v, val);
        upd(id << 1 | 1, m + 1, r, u, v, val);
        t[id] = MER(t[id << 1], t[id << 1 | 1]);
    }
    ll get(ll id, ll l, ll r, ll u, ll v)
    {
        if(r < u || v < l) return 0;
        if(u <= l && r <= v) return t[id];
        int m = (r + l) >> 1;
        down(id);
        return MER(get(id << 1, l, m, u, v), get(id << 1 | 1, m + 1, r, u, v));
    }
    void slv()
    {
        DFS(1, 1);
        time = 0;
        hld(1, 1);
        build(1, 1, n);
        ll k, x, y, val;
//        fr(i, 1, n) cout << euler[i] << " "; cout << el;
//        fr(i, 1, n) cout << a[euler[i]] << " " ; cout << el << el;
//        fr(i, 1, n) cout << in[i] << " " << out[i] << el;
//        ll tmp = 0;
//        fr(i, 1, n) tmp|=(1 << a[i]);
//        cout << tmp << el;
        while(q--) {
            cin >> k >> x;
            if(k == 1) {
                cin >> y >> val;
                int u = lca(x, y);
                while(chainID[x] != chainID[u]) {
                    upd(1, 1, n, pos[chain[chainID[x]]], pos[x], val);
                    x = up[chain[chainID[x]]][0];
                }
                while(chainID[y] != chainID[u]) {
                    upd(1, 1, n, pos[chain[chainID[y]]], pos[y], val);
                    y = up[chain[chainID[y]]][0];
                }
                if(h[x] < h[y]) {
                    upd(1, 1, n, pos[x], pos[y], val);
                }
                else upd(1, 1, n, pos[y], pos[x], val);
            }
            else if(k == 2) {
                cin >> val;
                upd(1, 1, n, in[x], out[x], val);
            }
            else if(k == 3) {
                cin >> y;
                ll res = 0;
                int u = lca(x, y);
                while(chainID[x] != chainID[u]) {
                    ll tmp = get(1, 1, n, pos[chain[chainID[x]]], pos[x]);
                    res = MER(res, tmp);
                    x = up[chain[chainID[x]]][0];
                }
                while(chainID[y] != chainID[u]) {
                    ll tmp = get(1, 1, n, pos[chain[chainID[y]]], pos[y]);
                    res = MER(res, tmp);
                    y = up[chain[chainID[y]]][0];
                }
                if(h[x] < h[y]) res = MER(res, get(1, 1, n, pos[x], pos[y]));
                else res = MER(res, get(1, 1, n, pos[y], pos[x]));
                cout << c_bit(res) << el;
//                cout << x << " " << y << " " << h[x] << " " << h[y] << " " << pos[x] << " " << pos[y] << el;
            }
            else {

                cout << c_bit(get(1, 1, n, in[x], out[x])) << el;
            }
        }
    }
}
namespace sub2
{
    bool check()
    {
        return (n <= 1000 && q <= 1000);
    }
    int h[MAX], euler[MAX], pos[MAX], chain[MAX], chainID[MAX], time = 0, sz[MAX], in[MAX], out[MAX];
    int mtc = 1, up[MAX][21], lazy[4*MAX];
    long long t[4*MAX];
    void DFS(int u, int p)
    {
        in[u] = ++time;
        euler[time] = u;
        pos[u] = time;
        up[u][0] = p;
        fr(j, 1, lg(n)) up[u][j] = up[up[u][j - 1]][j - 1];
        for(int v : g[u]) if(v != p) {
            h[v] = h[u] + 1;
            DFS(v, u);
        }
        out[u] = time;
    }
    int lca(int u, int v)
    {
        if(h[u] < h[v]) swap(u, v);
        frd(j, lg(n), 0) {
            if(h[up[u][j]] >= h[v]) u = up[u][j];
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
    void upd(ll u, ll v, ll x)
    {
        int p = lca(u, v);
        while(u != p) a[euler[pos[u]]] = x, u = up[u][0];
        while(v != p) a[euler[pos[v]]] = x, v = up[v][0];
        a[euler[pos[p]]] = x;
    }
    ll get(ll u, ll v)
    {
        set<int> res;
        int p = lca(u, v);
        while(u != p) res.insert(a[euler[pos[u]]]), u = up[u][0];
        while(v != p) res.insert(a[euler[pos[v]]]), v = up[v][0];
        res.insert(a[euler[pos[p]]]);
        return res.size();
    }
    void slv()
    {
        DFS(1, 1);
        int k, u, v, x;
        while(q--) {
            cin >> k >> u;
            if(k == 1) {
                cin >> v >> x;
                upd(u, v, x);
            }
            else if(k == 2) {
                cin >> x;
                fr(i, in[u], out[u]) a[euler[i]] = x;
            }
            else if(k == 3) {
                cin >> v;
                cout << get(u, v) << el;
            }
            else {
                set<int> res;
                fr(i, in[u], out[u]) res.insert(a[euler[i]]);
                cout << res.size() << el;
            }
        }
    }
}

main()
{
    #define TASK "COLTR"
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


