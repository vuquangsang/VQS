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

const int N = 1e5 + 2;
int n;
vector<int> g[N];
int root = 0;
void input()
{
    cin >> n;
    fr(i, 1, n) {
        int p;
        cin >> p;
        if(!p) root = i;
        else g[p].pb(i);
    }
}
namespace sub1
{
    int sz[N], par[N], h[N];
    void DFS(int u)
    {
        sz[u] = 1;
        for(int v : g[u]) {
            par[v] = u;
            h[v] = h[u] + 1;
            DFS(v);
            sz[u] += sz[v];
        }
    }

    int chainID[N], head[N], time = 0, mtc = 1, pos[N], euler[N];
    void dfs_hld(int u)
    {
        if(!head[mtc]) {
            head[mtc] = u;
        }
        chainID[u] = mtc;
        pos[u] = ++time;;
        euler[time] = u;
        int ma = 0;
        for(int v : g[u]) {
            if(!ma || sz[v] > sz[ma]) ma = v;
        }
        if(ma)  dfs_hld(ma);
        for(int v : g[u]) if(v != ma) {
            mtc++;
            dfs_hld(v);
        }
    }

    ll st[8*N], lz[8*N];

    void down(int id, int l, int mid, int r)
    {
        if(lz[id]) {
            int val = lz[id];
            st[id << 1] += 1ll*(mid - l + 1)*val%sm;
            st[id << 1 | 1] += 1ll*(r - mid)*val%sm;
            lz[id << 1] += val;
            lz[id << 1 | 1] += val;
            lz[id << 1] %= sm;
            lz[id << 1 | 1] %= sm;
            lz[id] = 0;
        }
    }
    void upd(int id, int l, int r, int u, int v, int val)
    {
        if(r < u || v < l) return;
        if(u <= l && r<= v) {
            st[id] += 1ll*(r - l + 1)*val%sm;
            lz[id] += val;
            lz[id] %= sm;
            return;
        }
        int mid = (r + l) >> 1;
        down(id, l, mid, r);
        upd(id << 1, l, mid, u, v, val);
        upd(id << 1 | 1, mid + 1, r, u, v, val);
        st[id] = (st[id << 1] + st[id << 1 | 1]) % sm;
    }
    ll get(int id, int l, int r, int u, int v)
    {
        if(r < u || v < l) return 0;
        if(u <= l && r <= v) return st[id];
        int mid = (r + l) >> 1;
        down(id, l, mid, r);
        return (get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v)) % sm;
    }

    ll res[N];

    void slv()
    {
        DFS(root);
        dfs_hld(root);
        upd(1, 1, n, 1, n, 1);
//        fr(i, 1, n) cout << pos[i] << " "; cout << el;
        fr(i, 1, n) {
            int x;
            cin >> x;
            ll val = get(1, 1, n, pos[x], pos[x]);
            res[x] = val;
            if(x == root) continue;
            x = par[x];
            while(chainID[x] != chainID[root]) {
                upd(1, 1, n, pos[head[chainID[x]]], pos[x], val);
                x = par[head[chainID[x]]];
            }
            if(h[x] >= h[root]) upd(1, 1, n, pos[root], pos[x], val);
        }
        fr(i, 1, n) {
            cout << res[i] << " ";
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


