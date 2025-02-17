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


const int MAX = 105;
int n, m, k;
vector<int> g[MAX];
void input()
{
    cin >> n >> m >> k;
    fr(i, 2, n) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
}
namespace sub1
{
    const int MAX = 105;
    ll h[MAX], up[MAX][10], fac[MAX], mod_fac[MAX];
    void DFS(ll u, ll p)
    {
        up[u][0] = p;
        fr(j, 1, lg(n)) up[u][j] = up[up[u][j - 1]][j - 1];
        for(int v : g[u]) if(v != p) {
            h[v] = h[u] + 1;
            DFS(v, u);
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
//    ll C(ll k, ll n)
//    {
//        if(k > n) return 0;
//        return mod(mod(fac[n], mod_fac[n - k]), mod_fac[k]);
//    }
    ll cal(ll x)
    {
        ll ans = 1;
        fr(i, 1, x) {
            ans = ans*(k - i + 1);
            ans%=MN;
        }
        return ans;
    }
    ll Pow(ll a, ll n)
    {
        if(!n) return 1;
        ll res = Pow(a, n/2);
        res = mod(res, res);
        if(n&1) res = mod(res, a);
        return res;
    }
    void slv()
    {
//        fac[0] = mod_fac[0] = 1;
//        fr(i, 1, n) fac[i] = mod(fac[i - 1], i);
//        fac[n] = Pow(fac[n], MN - 2);
//        frd(i, n - 1, 1) mod_fac[i] = mod(mod_fac[i + 1], i + 1);
        DFS(1, 0);
        ll x, y;
        while(m--) {
            cin >> x >> y;
            ll u = lca(x, y);
            ll dist = h[x] + h[y] - 2*h[u];
            cout << cal(dist) << el;
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
    #define TASK "coloring"
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


