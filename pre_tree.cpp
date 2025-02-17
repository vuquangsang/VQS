/* Vu Quang Sang from Le Khiet High School for Gifted */
#include <bits/stdc++.h>
using namespace std;

#define cerr cout
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
pll Q[MAX];
vector<pll> g[MAX];
void input()
{
    cin >> n >> q;
    int x, y, w;
    fr(i, 2, n) {
        cin >> x >> y >> w;
        g[x].pb({y, w});
        g[y].pb({x, w});
    }
    fr(i, 1, q) {
        int x, y;
        cin >> x >> y;
        Q[x].pb({id, y});
        Q[y].pb({id, x});
    }
}
namespace sub1
{
//    call f[u] is distance root -> u
//    euler tour to find
    int t[4*MAX], dp[MAX], in[MAX], out[MAX], euler[MAX], time = 0, f[MAX];
    void DFS(int u, int p)
    {
        in[u] = out[u] = ++time;
        euler[time] =  u;
        upd(1, 1, n, in[u], in[u], f[u]);
        for(pll t : g[u]) {
            int v = t.fi;
            int w = t.se;
            if(v == p) continue;
            f[v] = f[u] + w;
            f[v]%=MN;
            DFS(v, u);
        }
        out[u] = time;
    }
    void build(ll id, ll l, ll r)
    {
        if(l == r) {

        }
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
        t[id] = (t[id << 1] + t[id << 1 | 1])%MN;
    }
    ll get(ll id, ll l, ll r, ll u, ll v)
    {
        if(r < u || v < l) return;
        if(u <= l && r <= v) return t[id];
        int m = (r + l) >> 1;
        return (get(id << 1, l, m, u, v) + get(id << 1 | 1, m + 1, r, u, v))%MN;
    }

    int cal(int u, int p)
    {
        for(pll t : Q[u]) {
            int v = t.se;
            int id = t.fi;
            if(v == p) continue;
            int sub = get(1, 1, n, in[v], out[v]);
            int ans_out = get(1, 1, n, 1, n) - sub;
            res[id] = sub - ans_out;
        }
        for(pll t : g[u]) {
            int v = t.fi;
            int w = t.se;
            if(v == p) continue;
            upd(1, 1, n, 1, n, w);
            upd(1, 1, n, in[v], out[v], -2*w);
            cal(v, u);

            upd(1, 1, n, -w);
            upd(1, 1, n, in[v], out[v], 2*w);
//
        }
    }
    void slv()
    {
        memset(f, 1, sizeof f);
        DFS(1, 0);
        build(1, 1, n);
        cal(1, 0);
        fr(i, 1, q) cout << res[i] << " " ;
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


