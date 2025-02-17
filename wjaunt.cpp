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

ll n, k, p;
vector<pll> g[MF];
void input()
{
    cin >> n >> p >> k  ;
    ll x, y, w;
    fr(i, 2, n) {
        cin >> x >> y >> w;
        g[x].pb({y, w});
        g[y].pb({x, w});
    }
}
namespace sub1
{

    ll h[MF], f[MF], up[MF][21];
    void DFS(ll u, ll p)
    {
        up[u][0] = p;
        fr(j, 1, lg(n)) {
            up[u][j] = up[up[u][j - 1]][j - 1];
        }
        for(pll c : g[u]) {
            int v = c.fi;
            int w = c.se;
            if(v == p) continue ;
            h[v] = h[u] + 1;
            f[v] = f[u] + w;
            DFS(v, u);
        }
    }
    ll lca(ll u, ll v)
    {
        if(h[u] < h[v]) swap(u, v);
        frd(j, lg(n), 0){
            if(h[up[u][j]] >= h[v]) u = up[u][j];
        }
        if(u == v) return u;
        frd(j, lg(n), 0){
            if(up[u][j] != up[v][j]){
                u = up[u][j];
                v = up[v][j];
            }
        }
        return up[u][0];
    }
    ll dist(ll u, ll v)
    {
        return h[u] + h[v] - 2*h[lca(u, v)] + 1;
    }
    ll kc(ll u, ll v)
    {
        return f[u] + f[v] - 2*f[lca(u, v)];
    }
    void slv()
    {
        h[1] = 1;
        DFS(1, 1);
        fr(i, 1, n) {
            fr(j, 1, n) {
                ll value = dist(i, j) - 1;
                ll tmp = kc(i, j);
                if(value == k&& tmp == p) {
                    cout << i << " " << j; return ;
                }
            }
        }
        cout << 0 << " " << 0;
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



