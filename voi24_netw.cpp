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

const ll sm = 998244353;
const long long inf = 1e18+7;
const ll base = 311;
const ll BLOCK = 320;
const int dx[5] = {0, -1, 1, 0 , 0};
const int dy[5] = {0, 0, 0, -1, 1};

struct node{ll x,y;};
struct pll{ll fi,se;};
template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}


struct eg
{
    int x, y, w;
};
const int N = 1e5 + 2;
int n;
vector<pll> g[N];
eg edge[N];
void input()
{
    cin >> n;
    fr(i, 2, n) {
        int x, y, w;
        cin >> x >> y >> w;
        g[x].pb({y, w});
        g[y].pb({x, w});
    }
}
namespace sub1
{

    bool check() {return n <= 5000;}

    int up[N][21], h[N],mi[N][21];
    ll f[N];
    ll res = 0;

    ll sq(ll x)
    {
        return x*x%sm;
    }
    void DFS(int u, int p)
    {
        for(auto it : g[u]) {
            int v = it.fi;
            int w = it.se;
            if(v == p) continue;

            h[v] = h[u] + 1;
            f[v] = min((ll)w, f[u]);
            res = res + f[v]*sq(h[v])%sm;
            res%=sm;
            DFS(v, u);
        }
    }

    void slv()
    {
//        cout << f[3] << " " << f[4] << " " << f[1]; return;
        for(int i = 1; i <= n; i++ ) {
            h[i] = 0;
            f[i] = inf;
            res = 0;
            DFS(i, 0);
            cout << res << el;
        }
    }
}
namespace sub2
{
    bool check() {
        fr(i, 1, n) {
            for(pll x : g[i]) if(x.se != 1) return 0;
        }
        return 1;
    }


    int in[N], out[N] time = 0;
    int h[N];

    int f[N];
    void dfs(int u, int p) {
        in[u] = ++time;
        for(pair<int, int> e : adj[u]) {
            int v = e.fi, w = e.se;
            f[v] = f[u] + w; if(f[v] > sm) d[v]-=sm;
            dfs(v, u);
        }

        out[u] = time;
    }


    void DFS(int u, int p) {
        for(pair<int, int> e : g[u]) {
            int v = e.fi, w = e.se;
            if(v == P) continue;
            down[]
        }
    }
    void slv()
    {
        build();
    }
}

main()
{
    #define TASK "NETW"
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
        sub1::slv(); return 0;
        if(sub1::check()) sub1::slv();
        if(sub2::check()) sub2::slv();
    }
}


