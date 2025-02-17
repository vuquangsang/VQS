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

int n, q;
vector<int> g[MAX];
int A, B, c[MAX];
void input()
{
    cin >> n >> q;
    cin >> A >> B;
    fr(i, 1, n) cin >> c[i];
    fr(i, 2, n ){
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
}
namespace sub1
{

    int h[MAX], up[MAX][21];
    int sz[MAX], chain[MAX], chainID[MAX], time = 0, mtc = 0, pos[MAX], euler[MAX], lazy[4*MAX];
    pair<ll,ll> t[4*MAX];
    void DFS(ll u, ll p)
    {
        sz[u] = 1;
        up[u][0] = p;
        fr(j, 1, lg(n)) up[u][j] = up[up[u][j - 1]][j - 1];
        for(int v : g[u])if(v != p) {
            h[v] = h[u] + 1;
            DFS(v, u);
            sz[u]+=sz[v];
        }
    }
    ll lca(ll u, ll v)
    {
        if(h[u] < h[v]) swap(u, v);
        frd(j, lg(n), 0) if(h[up[u][j]] >= h[v]) u = up[u][j];
        if(u == v) return u;
        frd(j, lg(n), 0) {
            if(up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }
        return up[u][0];
    }
    void hld(ll u, ll p) {
        if(!chain[mtc]) chain[mtc] = u;
        chainID[u] = mtc;

        euler[++time] = u;
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
    pair<ll,ll> MER(pair<ll,ll> a, pair<ll,ll> b)
    {
        pair<ll,ll> res;
        res.fi = max(a.fi, b.fi);
        res.se = a.se + b.se;
        return res;
    }
    void build(ll id, ll l, ll r)
    {
        if(l == r) {
            ll value = c[euler[l]];
            t[id] = {value, (value*A + B) >= 0};
            return;
        }
        int m = (r + l) >> 1;
        build(id << 1, l, m);
        build(id << 1 | 1, m + 1, r);
        t[id] = MER(t[id << 1], t[id << 1 | 1]);
    }
    void down(ll id)
    {
        if(lazy[id]) {
            int x = lazy[id];
            t[id << 1].fi+=x;
            t[id << 1].fi+=x;

        }
    }
    void upd(ll id, ll l, ll r, ll u, ll v, ll val)
    {
        if(r < u || v < l) return;
        if(u <= l && r <= v) {
            t[id].fi+=val;
            lazy[id]+=val;
            return;
        }
        int m = (r + l) >> 1;
        down(id);
        upd(id << 1, l, m, u, v, val);
        upd(id << 1 | 1, m + 1, r, u, v, val);
        t[id] = MER(t[id << 1], t[id << 1 | 1]);
    }
    void slv()
    {

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
    bool qs = 1;
    ll mtt = 1;
    if(qs) cin >> mtt;
    fr(i, 1, mtt){
        input();
        sub1::slv();
    //    sub2::slv();
    }
}


