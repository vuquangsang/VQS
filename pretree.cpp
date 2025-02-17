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

const int N = 1e5 + 5;
ll n, a[N], q;
vector<pll> g[N];
void input()
{
    cin >> n >> q;
    fr(i, 2, n) {
        ll x,y , w;
        cin >> x >> y >> w;
        g[x].pb({y, w});
        g[y].pb({x, w});
    }
}
namespace sub1
{
    struct IT
    {
        ll sumsq, sum, len;
    } t[8*N];
    ll euler[N], h[N], time = 0, in[N], out[N], res[N], lazy[8*N];
    vector<pll> Q[N];
    void build(ll id, ll l, ll r)
    {
        if(l == r) {
            t[id].len = 1;
            return;
        }
        int m = (r + l) >> 1;
        build(id << 1, l, m);
        build(id << 1 | 1, m + 1, r);
        t[id].len = t[id << 1].len + t[id << 1 | 1].len;
    }
    void cal(ll id, ll val)
    {
        val = val + 1LL*sm*sm;
        val%=sm;

        t[id].sumsq = t[id].sumsq + 2*t[id].sum*val%sm + 1LL*val*val%sm*t[id].len%sm;
        t[id].sumsq%=sm;

        t[id].sum = t[id].sum + 1LL*val*t[id].len%sm;
        t[id].sum%=sm;
    }
    void down(ll id)
    {
        if(lazy[id]) {
            ll val = lazy[id];
            cal(id << 1, lazy[id]);
            cal(id << 1 | 1, lazy[id]);
            (lazy[id << 1] += val) %= sm;
            (lazy[id << 1 | 1] += val) %= sm;
            lazy[id] = 0;
        }
    }
    void upd(ll id, ll l, ll r, ll u, ll v, ll val)
    {
        if(r < u || v < l) return;
        if(u <= l && r <= v) {
            cal(id, val);
            (lazy[id] += val) %= sm;
            return;
        }
        int m = (r + l) >> 1;
        down(id);
        upd(id << 1, l, m, u, v, val);
        upd(id << 1 | 1, m + 1, r, u, v, val);

        t[id].len = t[id << 1].len + t[id << 1 | 1].len;

        t[id].sumsq = t[id << 1].sumsq + t[id << 1 | 1].sumsq;
        t[id].sumsq%=sm;

        t[id].sum = t[id << 1].sum + t[id << 1 | 1].sum;
        t[id].sum %= sm;
    }
    ll get(ll id, ll l, ll r, ll u, ll v)
    {
        if(r < u || v < l) return 0;
        if(u <= l && r <= v) return t[id].sumsq%sm;
        int m = (r + l) >> 1;
        down(id);
        return (get(id << 1, l, m, u, v) + get(id << 1 | 1, m + 1, r, u, v))%sm;
    }
    void DFS(int u, int p)
    {
        in[u] = ++time;
        upd(1, 1, n, in[u], in[u], h[u]);
        for(pll x : g[u] ) {
            ll v = x.fi, w = x.se;
            if(v == p) continue;
            h[v] = h[u] + w;
            h[v]%=sm;
            DFS(v, u);
        }
        out[u] = time;
    }
    void Sol(ll u, ll p)
    {
        for(pll x : Q[u]) {
            ll v = x.fi, id = x.se;
            ll sub = get(1, 1, n, in[v], out[v]);
            ll out = get(1, 1, n, 1, n) - sub;
            res[id] = sub - out + 1ll*sm*sm;
            res[id]%=sm;
        }

        for(pll x : g[u]) {
            ll v = x.fi, w = x.se;
            if(v == p) continue;
            upd(1, 1, n, 1, n, w);
            upd(1, 1, n, in[v], out[v], (1LL*-2*w + 1LL*sm*sm%sm)%sm);
            Sol(v, u);

            upd(1, 1, n, 1, n, (-w + 1LL*sm*sm)%sm);
            upd(1, 1, n, in[v], out[v], 1LL*2*w%sm);
        }
    }
    void slv()
    {
        int x, y;
        fr(i, 1, q) {
            cin >> x >> y;
            Q[x].pb({y, i});
        }
        build(1, 1, n);
        DFS(1, 1);
        Sol(1, 1);
        fr(i, 1, n) cout << res[i] << el;
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


