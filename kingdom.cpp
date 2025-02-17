/* Vu Quang Sang from Le Khiet High School for Gifted */
#include <bits/stdc++.h>
using namespace std;

//#define   ll int
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
#define     BIT(msk, i) (msk&(1 << i))

const ll MN = 1e9+7;
const ll MF = 1e6+7;
const long long inf = 1e18+7;
const ll N = 1005;
const ll base = 311;
const ll F = 1e5 + 2;
const ll BLOCK = 320;
const int dx[5] = {0, -1, 1, 0 , 0};
const int dy[5] = {0, 0, 0, -1, 1};
const short LO = 17;

struct node{ll x,y;};
struct bg{ll id,ts;};
struct pll{ll fi,se;};
struct init{ll in,va;bool operator <(init const&a)const{return this->va>a.va;}};
ll mod(ll a, ll b) {return ((a%MN)*(b%MN))%MN;}
template<class X, class Y>
    bool mini(X &x, const Y &y)  {
        if(x > y) {
            x = y;
            return 1;
        }
        else return 0;
    }
template<class X, class Y>
    bool maxi(X &x, const Y &y)
    {
        if(x < y) {
            x = y;
            return 1;
        }
        else return 0;
    }
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}

ll n, m;
vector<ll> g[MF];
ll v[MF], c[MF];
void input()
{
    cin >> n >> m;
    fr(i, 2, n) cin >> v[i];
    fr(i, 2, n) cin >> c[i];
    ll x, y;
    fr(i, 2, n) {
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
}
namespace sub1
{

    ll sz[MF], f[105][2005], dp[105][2005];
    void DFS(ll u, ll p)
    {
        sz[u] = c[u];
        for(int v : g[u]) if(v != p) {
            DFS(v, u);
            sz[u]+=sz[v];
        }
        mini(sz[u], m);
    }
    void dfs(ll u, ll p)
    {
        f[u][c[u]] = v[u];
        for(int v : g[u]) if(v != p) {
            dfs(v, u);
            for(int x = sz[u]; x >= 0; x--) {
                for(int p = 0; p <= sz[v]; p++) {
                    if(p > x) continue;
                    maxi(dp[u][x], f[v][p] + dp[u][x - p]); // no co the co nhieu nhanh ->
                                                            // f[i][x] la trag thai toi uu tai goc i voi gtri la x
                                                            // dp[i][x]  cjhi la gia tri tam thoi de cho no khoi bi tính trùng
                }
            }
        }
        for(int x = c[u]; x <= sz[u]; x++) maxi(f[u][x], dp[u][x - c[u]] + v[u]);
    }
    void slv()
    {
        DFS(1, 0);
        dfs(1, 0);
        ll res = 0;
        fr(x, 0, m) maxi(res, f[1][x]);
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



