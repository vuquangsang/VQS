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


const int N = 1e4 + 2;
struct eg
{
    int x, y, w;
} Q[N];
int n;
vector<pll> g[N];
void input()
{
    cin >> n;
    int x, y, w;
    fr(i, 1, n - 1) {
        cin >> x >> y >> w;
        g[x].pb({y, w});
        g[y].pb({x, w});
        Q[i] = {x, y, w};
    }
}
namespace sub1
{

    int sz[N], h[N], par[N], cost[N];
    void DFS(int u, int p)
    {
        sz[u] = 1;
        for(pll i : g[u]) {
            int v = i.fi;
            int w = i.se;
            if(v == p) continue;
            cost[v] = w;
            par[v] = u;
            h[v] = h[u] + 1;
            DFS(v, u);
            sz[u] += sz[v];
        }
    }

    int head[N], chainID[N], pos[N], euler[N], time = 0, mtc = 1;
    void dfs_hld(int u, int p)
    {
        if(!head[mtc]) {
            head[mtc] = u;
        }

        chainID[u] = mtc;
        pos[u] = ++time;
        euler[time] = u;

        int ma = 0;
        for(pll i : g[u]) {
            int v = i.fi;
        if(v == p) continue;
            if(!ma || sz[v] > sz[ma]) ma = v;
        }
        if(ma) dfs_hld(ma, u);
        for(pll i : g[u]) {
            int v = i.fi;
            if(v == ma || v == p) continue;
            mtc++;
            dfs_hld(v, u);
        }
    }

    int st1[8*N], st2[8*N], lz[8*N];
    void build(int id, int l, int r)
    {
        if(l == r) {
            st1[id] = st2[id] = cost[euler[l]];
            return;
        }
        int mid = (r + l) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        st1[id] = max(st1[id << 1], st1[id << 1 | 1]);
        st2[id] = min(st2[id << 1], st2[id << 1 | 1]);
    }

    void down(int id, int l, int mid, int r)
    {
        if(lz[id]) {
            int val = lz[id];
            st1[id << 1] = -st1[id << 1];
            st1[id << 1 | 1] = - st1[id << 1 | 1];

            st2[id << 1] = -st2[id << 1];
            st2[id << 1 | 1] = -st2[id << 1 | 1];
            swap(st1[id << 1], st2[id << 1]);
            swap(st1[id << 1 | 1], st2[id << 1 | 1]);

            lz[id << 1] += val;
            lz[id << 1 | 1] += val;
            lz[id << 1] %= 2;
            lz[id << 1 | 1] %= 2;
            lz[id] = 0;
        }
    }
    void upd(int id, int l, int r, int i, int val)
    {
        if(i > r || i < l) return;
        if(l == r) {
            st1[id] = st2[id] = val;
            return;
        }
        int mid = (r + l) >> 1;
        down(id, l, mid, r);
        upd(id << 1, l, mid, i, val);
        upd(id << 1 | 1, mid + 1, r, i, val);
        st1[id] = max(st1[id << 1], st1[id << 1 | 1]);
        st2[id] = min(st2[id << 1], st2[id << 1 | 1]);
    }

    void upd_neg(int id, int l, int r, int u, int v, int val)
    {
        if(r < u || v < l) return;
        if(u <= l && r <= v) {
            st1[id] = -st1[id];
            st2[id] = -st2[id];
            swap(st1[id], st2[id]);
            lz[id] += val;
            lz[id] %= 2;
            return;
        }
        int mid = (r + l) >> 1;
        down(id, l, mid, r);
        upd_neg(id << 1, l, mid, u, v, val);
        upd_neg(id << 1 | 1, mid + 1, r, u, v, val);
        st1[id] = max(st1[id << 1], st1[id << 1 | 1]);
        st2[id] = min(st2[id << 1], st2[id << 1 | 1]);
    }
    int lca(int x, int y)
    {
        while(chainID[x] != chainID[y]) {
            (chainID[x] > chainID[y] ? x = par[head[chainID[x]]] : y = par[head[chainID[y]]]);
        }
        return (h[x] < h[y] ? x : y);
    }
    void _negate(int x, int y)
    {
        int p = lca(x, y);

        while(chainID[x] != chainID[p]) {
            upd_neg(1, 1, n, pos[head[chainID[x]]], pos[x], 1);
            x = par[head[chainID[x]]];
        }
        while(chainID[y] != chainID[p]) {
            upd_neg(1, 1, n, pos[head[chainID[y]]], pos[y], 1);
            y = par[head[chainID[y]]];
        }
        if(h[x] < h[y]) upd_neg(1, 1, n, pos[x] + 1, pos[y], 1);
        else upd_neg(1, 1, n, pos[y] + 1, pos[x], 1);


    }
    int get(int id, int l, int r, int u, int v)
    {
        if(r < u || v < l) return 0;
        if(u <= l && r <= v) return st1[id];
        int mid = (r + l) >> 1;
        down(id, l, mid, r);
        return max(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
    }
    int calc(int x, int y)
    {
        int p = lca(x, y);

        int ans = 0;
        while(chainID[x] != chainID[p]) {
            maxi(ans, get(1, 1, n, pos[head[chainID[x]]], pos[x]));
            x = par[head[chainID[x]]];
        }
        while(chainID[y] != chainID[p]) {
            maxi(ans, get(1, 1, n, pos[head[chainID[y]]], pos[y]));
            y = par[head[chainID[y]]];
        }
        if(h[x] < h[y]) maxi(ans, get(1, 1, n, pos[x] + 1, pos[y]));
        else maxi(ans, get(1, 1, n, pos[y] + 1, pos[x]));

        return ans;
    }
    void slv()
    {

        DFS(1, 1);
        dfs_hld(1, 1);

        fr(i, 1, n) cout << cost[euler[i]] << " "; cout << el;
        build(1, 1, n);


        string k;
        int x, y;
        while(cin >> k) {
            if(k == "DONE") break;
            cin >> x >> y;
            if(k == "CHANGE") {
                int u = Q[x].x;
                int v = Q[x].y;
                if(h[u] < h[v]) swap(u, v);
                if(u == v) continue;
                upd(1, 1, n, pos[v], y);
            }
            else if(k == "NEGATE") {
                _negate(x, y);
            }
            else  {
                if(x == y) {
                    cout << 0 << el;
                    continue;
                }
                cout << calc(x, y) << el;
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


