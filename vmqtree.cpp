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


const int N = 5e4 + 10;
int n, q;
vector<int> g[N];
void input()
{
    cin >> n;
    int x, y;
    fr(i, 1, n - 1) {
        cin >>x  >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    cin >> q;
}
namespace sub1
{
    bool check() {return 1;}

    int h[N], up[N][21], par[N];
    pair<int , int> f[N][3];
    void dfs(int u, int p) {
        up[u][0] = p;
        fr(j, 1, lg(n)) up[u][j] = up[up[u][j - 1]][j - 1];
        for(int v : g[u]) if(v != p) {
            h[v] = h[u] + 1;
            par[v] = u;
            dfs(v, u);

            int val = f[v][0].fi + 1;
            if(val > f[u][0].fi) {
                f[u][2] = f[u][1];
                f[u][1] = f[u][0];
                f[u][0] = {val, v};
            }
            else if(val > f[u][1].fi) {
                f[u][2] = f[u][1];
                f[u][1] = {val, v};
            }
            else if(mini(f[u][2].fi, val)) f[u][2].se = v;
        }
    }

    void DFS(int u, int p)
    {
        for(int v : g[u]) if(v != p) {

            int val = f[u][0].fi + 1, node = f[u][0].se;
            if(node == v) val = f[u][1].fi + 1;
            if(val > f[v][0].fi) {
                f[v][2] = f[v][1];
                f[v][1] = f[v][0];
                f[v][0] ={val, u};
            }
            else if(val > f[v][1].fi) {
                f[v][2] = f[v][1];
                f[v][1] = {val, u};
            }
            else if(val > f[v][2].fi) f[v][2] = {val, u};

            DFS(v, u);
        }

    }
    int lca(int u, int v)
    {
        if(h[u] < h[v]) swap(u, v);
        frd(j, lg(n), 0) {
            if(h[up[u][j]] >= h[v]) u = up[u][j];
        }
        if(u == v) return u;
        frd(j, lg(n), 0) {
            if(up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }
        return up[u][0];
    }
    int dist(int x, int y)
    {
        return h[x] + h[y] - 2*h[lca(x, y)];
    }
    int total(int u, int p, int x, int y)
    {
        int val = f[u][0].fi, node = f[u][0].se;
        int tmp = lca(node, x);
        int cnt = 0;
        if(tmp == node && u != p) {
            val = f[u][1].fi;
            node = f[u][1].se;
            cnt++;
        }
        tmp = lca(node, y);
        if(tmp == node && u != p) {
            if(cnt) {
                val = f[u][2].fi;
            }
            else {
                val = f[u][1].fi;
            }
        }
        return val;
    }
    int calc(int x, int y)
    {
        int p = lca(x, y);
        int ans = 0;
        int u = x, v = y, str = 0;
        while(u != p) {
            maxi(ans, total(u, p, x, y) + min(dist(u, x), dist(u, y)));
            u = par[u];
        }
        while(v != p) {

            maxi(ans, total(v, p, x, y) + min(dist(v, x), dist(v, y)));
            v = par[v];
        }
        maxi(ans, total(p, p, x, y) + min(dist(p, x), dist(p, y)));
        return ans;
    }
    void slv()
    {
        dfs(1, 1);
        DFS(1, 1);
        int o = 5;
//        fr(x, 0, 2) {
//            cout << f[o][x].fi << " " << f[o][x].se << el;
//        }
//        cout << total(o, 5, 5, 7) << " " << min(dist(5, 7), dist(5, 5)) << el;
        while(q--) {
            int x, y;
            cin >> x >> y;
            cout << calc(x, y) << el;
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
    #define TASK "task"
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    if( fopen( TASK".INP", "r") ){
        freopen( TASK".INP", "r", stdin);
        freopen( TASK".OUT", "w", stdout);
    }
    bool qs = 1;
    ll mtt = 1;
    if(qs) cin >> mtt;
    fr(i, 1, mtt){
        input();
        sub1::slv();
    //    sub2::slv();
    }
}


