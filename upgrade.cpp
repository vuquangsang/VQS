#include <bits/stdc++.h>
using namespace std;

//#define   ll int
//#define     int long long
#define     lg(x) log2(x)
#define     alla(a,n) a+1,a+n+1
#define     el "\n"
#define     all(x) x.begin(),x.end()
#define     pb push_back
#define     ll int
#define     fi first
#define     se second
#define     MASK(i) (1ll<<(i))
#define     c_bit(i) __builtin_popcountll(i)
#define     fr(i,a,b) for(ll i=a;i<=b;i++)
#define     frd(i,a,b) for(ll i=a;i>=b;i--)

const ll MN = 1e9+7;
const ll MF = 1e6+7;
const long long inf = 1e18+7;
const ll N = 1005;
const ll base = 311;
const ll F = (1e5 + 2);
const ll BLOCK = 320;
const int dx[5] = {0, -1, 1, 0 , 0};
const int dy[5] = {0, 0, 0, -1, 1};
const short LO = 19;

struct bg{ll id,ts;};
struct pll{ll fi; ll se;};
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
        if(x > y) {
            x = y;
            return 1;
        }
        else return 0;
    }
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/__gcd(a, b)*b;}
struct node
{
    ll x, y, w, id;
};
ll n, m;
node qr[F];
node chain[F];
void input()
{
    cin >> n >> m;
    fr(i, 1, m) {
        cin >> qr[i].x >> qr[i].y >> qr[i].w;
        qr[i].id = i;
        chain[i] = qr[i];
    }
}
namespace sub1
{

    ll f[F],  h[F], up[F][LO], ma[F][LO];
    pll high[F];
    vector<pll> g[F];
    bool vis[MF] = {0};
    ll goc(ll x)
    {
        while(f[x] > 0) {
            x = f[x];
        }
        return x;
    }
    void hn(ll r1, ll r2, ll w, ll x, ll y)
    {
        ll tmp = f[r1] + f[r2];
        if(f[r1] < f[r2]) {
            f[r1] = tmp;
            f[r2] = r1;
        }
        else{
            f[r2] = tmp;
            f[r1] = r2;
        }
        g[x].pb({y, w});
        g[y].pb({x, w});
    }
    void DFS(ll u, ll p, ll w)
    {
        up[u][0] = p;
        ma[u][0] = w;
        fr(j, 1, lg(n)) {
            up[u][j] = up[up[u][j - 1]][j - 1];
            ma[u][j] = min(ma[u][j - 1], ma[up[u][j - 1]][j - 1]);
        }
        for(pll x : g[u]) {
            ll v = x.fi;
            ll w = x.se;
            if(v == p) continue ;
            h[v] = h[u] + 1;
            DFS(v, u, w);
        }
    }
    pair<ll,ll> lca(ll u, ll v)
    {
        ll value = MN;
        if(h[u] < h[v]) swap(u, v);
        frd(j, lg(n), 0) {
            if(up[u][j] && h[up[u][j]] >= h[v]) {
                maxi(value, ma[u][j]);
                u = up[u][j];
            }
        }
        if(u == v) return make_pair(u, value);
        frd(j, lg(n), 0) {
            if(up[u][j] != up[v][j]) {
                maxi(value, ma[u][j]);
                maxi(value, ma[v][j]);
                u = up[u][j];
                v = up[v][j];
            }
        }
        maxi(value, ma[u][0]);
        maxi(value, ma[v][0]);
        return make_pair(up[u][0], value);
    }
    bool cmp(node a, node b) {return a.w > b.w;}
    void slv()
    {
        sort(alla(qr, m), cmp);
        fr(i, 1, n) f[i] = -1;
        ll e = 0;
        long long res = 0;
        fr(i, 1, m) {
            ll x = qr[i].x;
            ll y = qr[i].y;
            ll w = qr[i].w;
            ll id = qr[i].id;
            ll r1 = goc(x);
            ll r2 = goc(y);
            if(r1 != r2) {
                hn(r1, r2, w, x, y);
                vis[id] = 1;
                e++;
                if(e == n - 1) break;
            }
        }
        DFS(1, 1, MN);
        fr(i, 1, m) if(!vis[i]){
            ll u = chain[i].x;
            ll v = chain[i].y;
            ll w = chain[i].w;

            pair<ll,ll> pi = lca(u, v);
            res+=pi.se - w;
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
    #define TASK "upgrade"
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
