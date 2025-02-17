#include <bits/stdc++.h>
using namespace std;

//#define   ll int
#define     lg(x) log2(x)
#define     alla(a,n) a+1,a+n+1
#define     el "\n"
#define     all(x) x.begin(),x.end()
#define     pb push_back
#define     ll long long
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
const ll F = 1e5 + 2;
const ll BLOCK = 320;
const int dx[5] = {0, -1, 1, 0 , 0};
const int dy[5] = {0, 0, 0, -1, 1};
const short LO = 17;

struct node{ll x,y,w,id;};
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
ll lcm(ll a, ll b) {return a/__gcd(a, b)*b;}

int n, m;
node a[2*F], qr[2*F];
void input()
{
    cin >> n >> m;
    fr(i, 1, m) {
        cin >> a[i].x >> a[i].y >> a[i].w;
        a[i].id = i;
        qr[i] = a[i];
    }
}
namespace sub1
{

    bool cmp(node a, node b) {return a.w < b.w;}
    ll f[MF], up[2*F][LO], val[2*F][LO], h[MF], euler[MF], in[MF], out[MF], time = 0;
    bool vis[MF] = {0};
    vector<pll> g[MF];
    vector<pll> e[MF];
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
        else{
            f[r2] = tmp;
            f[r1] = r2;
        }
    }
    void DFS(ll u, ll p, ll w)
    {
        up[u][0] = p;
        val[u][0] = w;
        in[u] = ++time;
        euler[time] = u;
        fr(j, 1, lg(n)) {
            up[u][j] = up[up[u][j - 1]][j - 1];
            val[u][j] = max(val[u][j - 1], val[up[u][j - 1]][j - 1]);
        }

        for(pll x : g[u]) {
            ll v = x.fi;
            ll w = x.se;
            if(v == p) continue ;
            h[v] = h[u] + 1;
            DFS(v, u, w);
        }
        out[u] = time;
    }
    ll lca(ll u, ll v)
    {
        if(h[u] < h[v]) swap(u, v);
        ll value = -inf;
        frd(j, lg(n), 0) {
            if(h[up[u][j]] >= h[v]) {
                maxi(value, val[u][j]);
                u = up[u][j];
            }
        }
        if(u == v) return value;
        frd(j, lg(n), 0) {
            if(up[u][j] != up[v][j]) {
                maxi(value, val[u][j]) ;
                maxi(value, val[v][j]) ;
                u = up[u][j];
                v = up[v][j];
            }
        }
        maxi(value, val[u][0]);
        maxi(value, val[v][0]);
        return value;
    }
    void slv()
    {
        fr(i, 1, n) f[i] = -1;
        sort(alla(qr, m), cmp);
        if(m == n - 1) {
            fr(i, 1, m) cout << -1 << " " ;
            return ;
        }
        ll d = 0, res = 0;
        fr(i, 1, m) {
            ll r1 = goc(qr[i].x);
            ll r2 = goc(qr[i].y);
            ll x = qr[i].x;
            ll y = qr[i].y;
            ll w = qr[i].w;
            if(r1 != r2) {
                if(d == n - 1) continue;
                hn(r1, r2);
                vis[qr[i].id] = 1;
                cout << x << " " << y << " " << w << el;
                res+=qr[i].w;
                g[x].pb({y, w});
                g[y].pb({x, w});
            }
            else{
                e[x].pb({y, w});
                e[y].pb({x, w});
            }
        }
    //    cout << res << el;
        DFS(1, 0, 0);
        fr(i, 1, m) {
            if(vis[i]) {
                ll res = a[i].w + 1;
                ll value = inf;
                ll u = a[i].x, v = a[i].y;
                if(h[u] < h[v]) swap(u, v);
                for(auto it : g[u]) {
                    ll ke = it.fi;
                    ll w = it.se;
                    if(ke == v) continue ;
                    mini(value, w);
                }
                fr(x, in[u] + 1, out[u]) {
                    for(auto it : g[x]) {
                        ll ke = it.fi;
                        ll w = it.se;
                        mini(value, w);
                    }
                }
               if(value != inf) res = max(res, value);
               cout << res - 1 << " ";
            }
            else {
                cout << lca(a[i].x, a[i].y) - 1 << " ";
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
    #define TASK "tmp"
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


