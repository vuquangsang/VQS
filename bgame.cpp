/* Vu Quang Sang from Le Khiet High School for Gifted */
#include <bits/stdc++.h>
using namespace std;

//#define   ll int
#define     lg(x) __lg(x)
#define     alla(a,n) a+1,a+n+1
#define     el "\n"
#define     all(x) x.begin(),x.end()
#define     pb push_back
#define     ll int
#define     fi first
#define     se second
#define     Mask(i) (1ll<<(i))
#define     c_bit(i) __builtin_popcountll(i)
#define     fr(i,a,b) for(int i = (a), _b = (b); i <= _b; i++)
#define     frd(i,a,b) for(int i = (a), _b = (b); i >= _b; i--)
#define     REP(i, a, b) for(int i = (a), _b = (b); i < _b; i++)
#define     BIT(msk, i) (msk&(1 << i))

const ll MN = 1e9+7;
const ll MF = 1e5 + 2;
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
template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}
struct edge
{
    int x, y, w;
    bool operator<(edge const&a) const
    {
        return this-> w > a.w;
    }
};
ll n, m;
edge e[F];
void input()
{
    cin >> n >> m;
    fr(i, 1, m) cin >> e[i].x >> e[i].y >> e[i].w;
    sort(e + 1, e + m + 1);
}
namespace sub1
{
    struct line
    {
        ll x, w;
    };
    vector<line> g[MF];
    ll f[F], h[MF], up[F][LO], ma[F][LO];
    bool dd[MF];
    ll goc(ll x)
    {
        while(f[x] > 0) {
            x = f[x];
        }
        return x;
    }
    void hn(ll r1, ll r2)
    {
        ll tmp = f[r1] + f[r2];
        if(f[r1] < f[r2]) {
            f[r1] = tmp;
            f[r2] = r1;
        }
        else {
            f[r2] = tmp;
            f[r1] = r2;
        }

    }
    void DFS(ll u, ll p, ll w)
    {
        up[u][0] = p;
        ma[u][0] = w;
        fr(j, 1, lg(n)) {
            up[u][j] = up[up[u][j - 1]][j - 1];
            ma[u][j] = max(ma[u][j - 1], ma[up[u][j - 1]][j - 1]);
        }
        for(line it : g[u]) {
            int v = it.x;
            int w = it.w;
            if(v == p) continue;
            h[v] = h[u] + 1;
            DFS(v, u, w);
        }
    }
    ll lca(ll u, ll v)
    {
        if(h[u] < h[v]) swap(u, v);
        ll ans = 0;
        int dis = h[u]-h[v] ;
        for(int i= 0 ;i<LO;i++)
        {
            if(dis>>i&1)
            {
                ans=max(ans,ma[u][i]) ;
                u= up[u][i] ;
            }
        }
        if(u == v) return ans;
        frd(j, lg(n), 0) {
            if(up[u][j] != up[v][j]) {
                ans = max(ans, max(ma[u][j], ma[v][j]));
                u = up[u][j];
                v = up[v][j];
            }
        }
        ans = max(ans, max(ma[u][0], ma[v][0]));
        return ans;
    }
    void slv()
    {
        fr(i, 1, n) f[i] = -1;
        fr(i, 1, m ){
            ll x = e[i].x;
            ll y = e[i].y;
            ll w = e[i].w;
            ll r1 = goc(x);
            ll r2 = goc(y);
            if(r1 != r2) {
                dd[i] = 1;
                g[x].pb({y, w});
                g[y].pb({x, w});
                hn(r1, r2);
            }
        }
        h[1] = 1;
        DFS(1, 0, 0);
        ll res = 0;
        fr(i, 1, m) if(!dd[i]) {
            ll x = e[i].x;
            ll y = e[i].y;
            maxi(res, lca(x, y) + e[i].w);
        }
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



