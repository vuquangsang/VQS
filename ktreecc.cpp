#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
//#define ll long  long
#define ll int
#define pb push_back
#define sang ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fr(i, a, b) for(int i = a; i <= b; i++)
#define frd(i, a, b) for(int i = a; i >= b; i--)
#define el "\n"
#define lg(n)  __lg(n)
template<class X, class Y>
    bool mini(X &x, const Y &y)
    {
        if(x > y){
            x = y;
            return 1;
        }
        else return 0;
    }
const ll MF = 1e4 + 7;
ll n, m, a[MF];
vector<ll> g[MF];
void in()
{
    cin >> n;
    fr(i, 2, n) {
        ll x,y ;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
}
namespace sub2
{
    ll h[MF], up[MF][21];
    vector<ll> ke[(int)1e4 + 2];
    void DFS(ll u, ll p)
    {
        up[u][0] = p;
        fr(j, 1, lg(n)) up[u][j] = up[up[u][j - 1]][j - 1];
        for(int v : g[u]) if(v != p) {
            h[v] = h[u] + 1;
            DFS(v, u);
        }
    }
    ll lca(ll u, ll v)
    {
        if(h[u] < h[v]) swap(u, v) ;
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
    void build()
    {
        for(int j = 1; (1 << j) < N; j++) {
            for(int i = 0; i + (1 << j) - 1 < N; i++) {
                if(h[up[i][j - 1]] < h[])
            }
        }
    }
    ll dist(ll u, ll v)
    {
        return h[u] + h[v] - 2*h[lca(u, v)];
    }
    ll cal(ll u, ll key)
    {
        ll res = 1e4;
        for(int v : ke[key]) {
            mini(res, dist(v, u));
        }
        return res;
    }
    void slv()
    {
        DFS(1, 0);
        ll c, x;
        cin >> c;
        fr(i, 1, n) {
            cin >> x;
            ke[x].pb(i);
        }
        cin >> m;
        int u, key;
        while(m--) {
            cin >> u >> key ;
            cout << cal(u, key) << el;
        }
    }
}
signed main()
{
    sang;
    in();
    sub2::slv();
}

