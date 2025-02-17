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

const int MAX = 1e5 + 2;
int n, q;
int e[MAX];
vector<int> g[MAX];
void input()
{
    cin >> n >> q;
    fr(i, 1, n) cin >> e[i];
    int x, y;
    fr(i, 2, n) {
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
}
namespace sub1
{
    #define ll int
    int up[MAX][19], h[MAX], sz[MAX];
    int t[4*MAX];
    int chain[MAX], chainID[MAX], euler[MAX], pos[MAX], time = 0, mtc = 1;
    void DFS(ll u, ll p)
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
    int lca(ll u, ll v)
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
    }
    void build(ll id, ll l, ll r)
    {
        if(l == r) {
            t[id] = e[euler[l]];
            return;
        }
        int m = (r + l) >> 1;
        build(id << 1, l, m);
        build(id << 1 | 1, m + 1, r);
        t[id] = (t[id << 1]^t[id << 1 | 1]);
    }
    void upd(ll id, ll l, ll r, ll i, ll val)
    {
        if(i > r || i < l) return;
        if(l == r) {
            t[id] = val;
            return;
        }
        int m = (r + l) >> 1;
        upd(id << 1, l, m, i, val);
        upd(id << 1 | 1, m + 1, r, i, val);
        t[id] = (t[id << 1]^t[id << 1 | 1]);
    }
    ll get(ll id, ll l, ll r, ll u, ll v)
    {
        if(r < u || v < l) return 0;
        if(u <= l && r <= v) return yt[id];
        int m = (r + l) >> 1;
        return get(id << 1, l, m, u, v)^(get(id << 1 | 1, m + 1, r, u, v));
    }
    void slv()
    {
        DFS(1, 1);
        hld(1, 1);
        build(1, 1, n);
        int k, x, y, val;
//        fr(i, 1, n) cout << euler[i] << " "; cout << el << el;
        while(q--) {
            cin >> k >> x;
            if(k == 1) {
                cin >> val;
                upd(1, 1, n, pos[x], val);
            }
            else {
                cin >> y;
                int res = 0;
                int u = lca(x, y);
                while(chainID[x] != chainID[u]) {
                    res = res^(get(1, 1, n, pos[chain[chainID[x]]], pos[x]));
                    x = up[chain[chainID[x]]][0];
                }
                while(chainID[y] != chainID[u]) {
                    res = res^(get(1, 1, n, pos[chain[chainID[y]]], pos[y]));
                    y = up[chain[chainID[y]]][0];
                }


                if(h[x] < h[y])res= res^(get(1, 1, n, pos[x], pos[y]));
                else res^=(get(1, 1, n, pos[y], pos[x]));
                cout << res << el;
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


