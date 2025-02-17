/* Vu Quang Sang from Le Khiet High School for Gifted */
#include <bits/stdc++.h>
using namespace std;

#define     lg(x) __lg(x)
#define     alla(a,n) a+1,a+n+1
#define     el "\n"
#define     pb push_back
#define     fr(i,a,b) for(int i = (a), _b = (b); i <= _b; i++)
#define     frd(i,a,b) for(int i = (a), _b = (b); i >= _b; i--)
#define     REP(i, a, b) for(int i = (a), _b = (b); i < _b; i++)

struct node{int x,y;};


const int N = 2e5 + 2;
int n, m;
node e[N];
void input()
{
    cin >> n >> m;
    fr(i, 1, m) {
        cin >> e[i].x >> e[i].y;
    }
}
namespace sub1
{

    struct DSU
    {
        int f[N];
        void init()
        {
            fr(i, 1, n) f[i] = -1;
        }
        int root(int x) {return f[x] < 0 ? x : f[x] = root(f[x]);}

        bool join(int u, int v)
        {
            int r1 = root(u), r2 = root(v);
            if(r1 == r2) return 0;
            int tmp = f[r1] + f[r2];
            if(f[r1] < f[r2]) {
                f[r1] = tmp;
                f[r2] = r1;
            }
            else {
                f[r2] = tmp;
                f[r1] = r2;
            }
            return 1;
        }
    } dsu;


    vector<int> nmst;
    vector<int> g[N];

    struct hld
    {
        int h[N], sz[N], head[N], chainID[N], time = 0, mtc = 1;
        int par[N];
        int st[8*N], lazy[8*N];
        int euler[N], pos[N];
        void dfs(int u, int p ) {
            sz[u] = 1;
            for(int v : g[u]) if(v != p) {
                h[v] = h[u]+ 1;
                par[v] = u;
                dfs(v, u);
                sz[u]+=sz[v];
            }
        }

        void dfs_hld(int u, int p)
        {
            if(!head[mtc]) {
                head[mtc] = u;
            }
            chainID[u] = mtc;
            euler[++time] = u;
            pos[u] = time;

            int ma = 0;
            for(int v : g[u]) if(v != p) {
                if(!ma || sz[v] > sz[ma]) ma = v;
            }
            if(ma) dfs_hld(ma, u);

            for(int v : g[u]) if(v != p && v != ma) {
                mtc++;
                dfs_hld(v, u);
            }
        }
        int lca(int u, int v)
        {
            while(chainID[u] != chainID[v]) {
                (chainID[u] > chainID[v] ? u = par[head[chainID[u]]] : v = par[head[chainID[v]]]);
            }
            return (h[u] < h[v] ? u : v);
        }

        void down(int id, int l, int mid, int r) {
            if(lazy[id]) {
                int val = lazy[id];
                st[id << 1] = (mid - l + 1);
                st[id << 1 | 1] = (r - mid);
                lazy[id << 1] = val;
                lazy[id << 1 | 1] = val;
                lazy[id] = 0;
            }
        }
        void upd(int id, int l, int r, int u, int v, int val)
        {
            if(r < u || v < l) return;
            if(u <= l && r <= v) {
                st[id] = (r - l + 1);
                lazy[id] = val;
                return;
            }
            int mid = (r + l) >> 1;
            down(id, l, mid, r);
            upd(id << 1, l, mid, u, v, val);
            upd(id << 1 | 1, mid + 1, r, u, v, val);
            st[id] = st[id << 1] + st[id << 1 | 1];
        }
        int get(int id, int l, int r, int u, int v)
        {
            if(r < u || v < l) return 0;
            if(u <= l && r <= v) return st[id];
            int mid = (r + l) >> 1;
            down(id, l, mid, r);
            return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
        }
        void update(int x, int y)
        {
            int p = lca(x, y);
            while(chainID[x] != chainID[p]) {
                upd(1, 1, n, pos[head[chainID[x]]], pos[x], 1);
                x = par[head[chainID[x]]];
            }
            while(chainID[y] != chainID[p]) {
                upd(1, 1, n, pos[head[chainID[y]]], pos[y], 1);
                y = par[head[chainID[y]]];
            }
            if(h[x] < h[y]) upd(1, 1, n, pos[x] + 1, pos[y], 1);
            else upd(1, 1, n, pos[y] + 1, pos[x], 1);
        }

        int calc(int x, int y)
        {
            int ans = 0;
            int p = lca(x, y);
            while(chainID[x] != chainID[p]) {
                ans += get(1, 1, n, pos[head[chainID[x]]], pos[x]);
                x = par[head[chainID[x]]];
            }
            while(chainID[y] != chainID[p]) {
                ans += get(1, 1, n, pos[head[chainID[y]]], pos[y]);
                y = par[head[chainID[y]]];
            }
            if(h[x] < h[y]) ans = ans + get(1, 1, n, pos[x] + 1, pos[y]);
            else ans += get(1, 1, n, pos[y] + 1, pos[x]);
            return ans;
        }
        int dist(int x, int y)
        {
            return h[x] + h[y] - 2*h[lca(x, y)];
        }
        void init()
        {
            dfs(1, 0);
            dfs_hld(1, 0);
        }
    } hld;
    void slv()
    {
        dsu.init();
        fr(i, 1, m) {
            int x = e[i].x;
            int y = e[i].y;
            if(dsu.join(x, y)) {
                g[x].pb(y);
                g[y].pb(x);
            }
            else {
                nmst.pb(i);
            }
        }
        hld.init();
        for(int i : nmst) {
            hld.update(e[i].x, e[i].y);
        }
        nmst.clear();
        int k, x, y;
        while(1) {
            cin >> k;
            if(!k) return;
            cin >> x >> y;
            if(k == 1) {
                hld.update(x, y);
            }
            else{
                cout << hld.dist(x, y) - hld.calc(x, y) << el;
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
    #define TASK "tas"
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    if( fopen( TASK".INP", "r") ){
        freopen( TASK".INP", "r", stdin);
        freopen( TASK".OUT", "w", stdout);
    }

    input();
    sub1::slv();
}


