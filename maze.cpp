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

const int MAX = 3e5 + 2;
int n;
vector<pll> g[MAX];
void input()
{
    cin >> n;
    int x, y, w;
    fr(i, 2, n) {
        cin >> x >> y >> w;
        g[x].pb({y, w});
        g[y].pb({x, w});
    }
}
namespace sub1
{

    pll f[MAX][3];
    void dfs(ll u, ll p)
    {
        f[u][0] = f[u][1] = f[u][2] = {0, 0};
        for(pll x : g[u]) {
            ll v = x.fi;
            ll w = x.se;
            if(v == p) continue;
            dfs(v, u);

            if(f[v][0].fi + w > f[u][0].fi) {
                f[u][2] = f[u][1];
                f[u][1] = f[u][0];
                f[u][0] = {f[v][0].fi + w, v};
            }
            else if(f[v][0].fi + w > f[u][1].fi) {
                f[u][2] = f[u][1];
                f[u][1] = {f[v][0].fi + w, v};
            }
            else if(maxi(f[u][2].fi, f[v][0].fi + w)) f[u][2].se = v;
        }
    }
    void DFS(ll u, ll p, ll value)
    {
        if(value > f[u][0].fi) {
            f[u][2] = f[u][1];
            f[u][1] = f[u][0];
            f[u][0] = {value, p};
        }
        else if(value > f[u][1].fi) {
            f[u][2] = f[u][1];
            f[u][1] = {value, p};
        }
        else if(maxi(f[u][2].fi, value)) f[u][2].se = p;

        for(pll x : g[u]) {
            ll v = x.fi;
            ll w = x.se;
            if(v == p) continue;

            if(v != f[u][0].se) DFS(v, u, f[u][0].fi + w);
            else DFS(v, u, f[u][1].fi + w);
        }
    }
    void slv()
    {
        ll res = 0;

        dfs(1, 0);
        DFS(1, 0, 0);

        fr(u, 1, n) maxi(res, f[u][0].fi*(f[u][1].fi + f[u][2].fi));
        cout << res;
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
    #define TASK "maze"
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


