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

const int N = 2e5;
int n, q;
vector<pair<int, int>> adj[N];
struct eg
{
    int x, y, w;
} E[N];
void input()
{
    cin >> n >> q;
    int x, y, w;
    fr(i, 1, n - 1) {
        cin >> x >> y >> w;
        E[i] = {x, y, w};
        adj[x].pb({y, w});
        adj[y].pb({x, w});
    }
}
namespace sub1
{
    #define pii pair<int, int>
    int sz[N], h[N], par[N], cost[N];
    void DFS(int u, int p)
    {
        sz[u] = 1;
        for(pii i : adj[u]) {
            int v = i.fi, w = i.se;
            if(v == p) continue;
            h[v] = h[u] + 1;
            par[v] = u;
            cost[v] = w;
            DFS(v, u);
            sz[u] += sz[v];
        }
    }

    int chainID[N], time = 0, mtc = 1, head[N], pos[N], euler[N], in[N], out[N];
    void dfs_hld(int u, int p)
    {
        if(!head[mtc]) {
            head[mtc] = u;
        }
        chainID[u] = mtc;
        euler[++time] = u;
        pos[u] = time;
        in[u] = time;

        int ma = 0;
        for(pii i : adj[u]) {
            int v = i.fi, w = i.se;
            if(v == p) continue;
            if(!ma || sz[v] > sz[ma]) ma = v;
        }
        if(ma) dfs_hld(ma, u);

        for(pii i : adj[u]) {
            int v = i.fi, w = i.se;
            if(v == p || v == ma) continue;
            mtc++;
            dfs_hld(v, u);
        }
        out[u] = time;
    }
    int lca(int x, int y)
    {
        while(chainID[x] != chainID[y]) {
            (chainID[x] > chainID[y] ? x = par[head[chainID[x]]] : y = par[head[chainID[y]]]);
        }
        return (h[x] < h[y] ? x : y);
    }

    vector<int> st[4 * N];

    vector<int> MER(vector<int> a, vector<int> b)
    {
        vector<int> res(a.size() + b.size());
        merge(a.begin(), a.end(), b.begin(), b.end(), res.begin());
        return res;
    }
    void build(int id, int l, int r)
    {
        if(l == r){
            st[id].pb(cost[euler[l]]);
            return;
        }
        int mid = (r + l) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        st[id] = MER(st[id << 1], st[id << 1 | 1]);
    }
    int get(int id, int l, int r, int u, int v, int val)
    {
        if(r < u || v < l) return 0;
        if(u <= l && r <= v) {
            return (upper_bound(all(st[id]), val) - st[id].begin());
        }
        int mid = (r + l) >> 1;
        return get(id << 1, l, mid, u, v, val) + get(id << 1 | 1, mid + 1, r, u, v, val);
    }

    int calc(int x, int y, int w)
    {
        int p = lca(x, y);
        int ans = 0;
        while(chainID[x] != chainID[p]) {
            ans += get(1, 1, n, pos[head[chainID[x]]], pos[x], w);
            x = par[head[chainID[x]]];
        }
        while(chainID[y] != chainID[p]) {
            ans += get(1, 1, n, pos[head[chainID[y]]], pos[y], w);
            y = par[head[chainID[y]]];
        }
        if(h[x] > h[y]) swap(x, y);
        if(h[x] < h[y]) ans += get(1, 1, n, pos[x] + 1, pos[y], w);
        return ans;
    }
    int cal(int k, int w)
    {
        int x = E[k].x;
        int y = E[k].y;
        if(h[x] < h[y]) {
            return get(1, 1, n, in[y] + 1, out[y], w);
        }
        else {
            return get(1, 1, n, in[1] + 1, out[1], w) - get(1, 1, n, in[x] + 1, out[x], w);
        }
    }
    void slv()
    {

        DFS(1, 1);
        dfs_hld(1, 1);
        build(1, 1, n);
//        fr(i, 1, n) cout << pos[i] << " "; cout << el;
//        fr(i, 1, n) cout << chainID[i] << " "; cout << el;
//        fr(i, 1, n) cout << euler[i] << " "; cout << el;
        char type;
        while(q--) {
            cin >> type;
            if(type == 'P') {
                int x, y, w;
                cin >> x >> y >> w;
                cout << calc(x, y, w) << el;
            }
            else {
                int k, c;
                cin >> k >> c;
                cout << cal(k, c) << el;
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
    bool qs = 0;
    ll mtt = 1;
    if(qs) cin >> mtt;
    fr(i, 1, mtt){
        input();
        sub1::slv();
    //    sub2::slv();
    }
}


