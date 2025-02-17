#include <bits/stdc++.h>
using namespace std;

#define     TASK ""
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
#define     fr(i,a,b) for(int i=a;i<=b;i++)
#define     frd(i,a,b) for(int i=a;i>=b;i--)

const ll MN = 1e9+7;
const ll MF = 1e6+7;
const ll inf = 1e18+7;
const ll N = 1005;
const ll H = 311;
const ll F = 1e5 + 3;
const int dx[5] = {0, -1, 1, 0 , 0};
const int dy[5] = {0, 0, 0, -1, 1};

struct node{ll x,y;};
struct bg{ll id,ts;};
struct pll{ll fi,se;};
struct init{ll in,va;bool operator <(init const&a)const{return this->va>a.va;}};
ll mod(ll a, ll b) {return ((a%MN)*(b%MN))%MN;}
ll sum(ll a, ll b) {return (a + b)%MN;}

ll n, q, a[MF];
vector<ll> g[MF];
void input()
{
    cin >> n >> q;
    fr(i, 1, n) cin >> a[i];
    ll x, y;
    fr(i, 1, n - 1) {
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
}
namespace sub1
{
    ll h[MF], up[MF][21], sz[MF], t[MF], euler[MF], time = 1, chain[MF], mtc = 1;
    ll chainID[MF], pos[MF];
    // chain = xich,
    void dfs(ll u, ll p)
    {
        sz[u] = 1;
        for(int v : g[u]) if(v != p) {
            h[v] = h[u] + 1;
            up[v][0] = u;
            dfs(v, u);
            sz[u]+=sz[v];
        }
    }
    ll lca(ll u, ll v)
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
    void build(ll id, ll l, ll r)
    {
        if(l == r) {
            t[id] = a[euler[l]];
            return ;
        }
        ll m = (r + l) >> 1;
        build(id << 1, l, m);
        build(id << 1 | 1, m + 1, r);
        t[id] = max(t[id << 1], t[id << 1 | 1]);
    }
    void upd(ll id, ll l, ll r, ll i, ll val)
    {
        if(i > r || i < l) return ;
        if(l == r) {
            t[id] = val;
            return ;
        }
        ll m = (r + l) >> 1;
        upd(id << 1, l, m, i, val);
        upd(id << 1 | 1, m + 1, r, i, val);
        t[id] = max(t[id << 1], t[id << 1 | 1]);
    }
    ll get(ll id, ll l, ll r, ll u, ll v)
    {
        if(r < u || v < l) return 0;
        if(u <= l && r <= v) return  t[id];
        ll m = (r + l) >> 1;
        return max ( get(id << 1, l, m, u, v) , get(id << 1 | 1, m + 1, r, u, v) );
    }
    void hld(ll u, ll p)
    {
        if(!chain[mtc]) {
            chain[mtc] = u;
            // dinh dau tien cua chain
        }
        chainID[u] = mtc;
        // dinh u thuoc chain mtc;
        pos[u] = time;
        // vt cua u trong dfs;
        euler[time] = u;
        time++;
        // euler tour
        ll ans = 0;
        for(int v : g[u]) if(v != p) {
            if(sz[v] > sz[ans] || !ans) ans = v;
        }
        if(ans) hld(ans, u);
        // neu con duong di cua chain now -> van di tiep
        for(int v : g[u]) {
            if(v == p || v == ans) continue ;
            mtc++;
            // het chain cu -> new_chain -> multichain++;
            hld(v, u);

        }
    }
    void slv()
    {
        up[1][0] = 1;
        dfs(1, 0);
        fr(j, 1, lg(n)){
            fr(i, 1, n) {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }
        time = mtc = 1;
        hld(1, 0);
        build(1, 1, n);
  //      fr(i, 1, mtc) cout << chain[i] << " " ; cout << el;
  //      fr(i, 1, time--)cout << chainID[i] << " " ;
        ll key, x, y;
        while(q--) {
            cin >> key >> x >> y;
            if(key == 1) {
                upd(1, 1, n, pos[x], y);
            }
            else{
                ll u = lca(x, y), ans = 0;
                while(chainID[x] != chainID[u]) {
                    ans = max(ans, get(1, 1, n, pos[chain[chainID[x]]], pos[x]));
                    x = up[chain[chainID[x]]][0];
                }
                while(chainID[y] != chainID[u]) {
                    ans = max(ans, get(1, 1, n, pos[chain[chainID[y]]], pos[y]));
                    y = up[chain[chainID[y]]][0];
                }
                // neu 2 cai cung o 1 nhanh
                if(h[x] < h[y]) {
                    ans = max(ans, get(1, 1, n, pos[x], pos[y]));
                }
                else{
                    ans = max(ans , get(1, 1, n, pos[y], pos[x]));
                }
                cout << ans << " " ;
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









