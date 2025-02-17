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

const ll MN = 1e9+7;
const long long inf = 1e18+7;
const ll base = 311;
const ll BLOCK = 320;
const int dx[5] = {0, -1, 1, 0 , 0};
const int dy[5] = {0, 0, 0, -1, 1};

struct node{ll x,y;};
struct pll{ll fi,se;};
ll mod(ll a, ll b) {return ((a%MN)*(b%MN))%MN;}
template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}
const int MAX = 1e5 + 2;
int n, q;
vector<pll> g[MAX];
node Q[MAX];
void input()
{
    cin >> n;
    int x, y, w;
    fr(i, 1, n) g[i].clear();
    fr(i, 1, n - 1) {
        cin >> x >> y >> w;
        g[x].pb({y, w});
        g[y].pb({x, w});
        Q[i] = {x, y};
    }
}
namespace sub1
{

    int h[MAX], pos[MAX], t[4*MAX], sz[MAX], up[MAX][20], euler[MAX], chain[MAX], chainID[MAX];
    int time = 0, mtc = 1, st[MAX], rmq[MAX][20];
    void DFS(ll u, ll p)
    {
        up[u][0] = p;
        fr(j, 1, lg(n)) up[u][j] = up[up[u][j - 1]][j - 1];
        sz[u] = 1;
        for(pll x : g[u]) {
            ll v = x.fi;
            ll w = x.se;
            if(v == p) continue;
            h[v] = h[u] + 1;
            DFS(v, u);
            sz[u]+=sz[v];
        }
    }
    ll lca(ll u, ll v)
    {
        if(h[u] < h[v]) swap(u, v);
        frd(j, lg(n), 0) if(h[up[u][j]] >= h[v]) u = up[u][j];
        if(u == v) return u;
        frd(j, lg(n), 0) {
            if(up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }
        return up[u][0];
    }
    void hld(ll u, ll p, ll w)
    {
        if(!chain[mtc]) {
            chain[mtc] = u;
        }
        st[u] = w;
        chainID[u] = mtc;
        euler[++time] = u;
        pos[u] = time;

        int ma = 0, ans = 0;
        for(pll x : g[u]) {
            ll v = x.fi;
            ll w = x.se;
            if(v == p) continue;
            if(!ma || sz[v] > sz[ma]) {
                ma = v;
                ans = w;
            }
        }
        if(ma) hld(ma, u, ans);
        for(pll x : g[u]){
            int v = x.fi;
            int w = x.se;
            if(v != p && v != ma) {
                mtc++;
                hld(v, u, w);
            }
        }
    }
    void upd(ll id, ll l, ll r, ll i, ll val)
    {
        if(i > r || i < l) return;
        if(l == r) {
            t[id] = val;
            return;
        }
        int m = (r + l) >> 1;
        upd(id << 1, l, m, i, val);
        upd(id << 1 | 1, m + 1, r, i, val);
        t[id] = max(t[id << 1], t[id << 1 | 1]);
    }
    ll get(ll id, ll l, ll r, ll u, ll v)
    {
        if(r < u || v < l) return -1e9;
        if(u <= l && r <= v) return t[id];
        int m = (r + l) >> 1;
        return max(get(id << 1, l, m, u, v), get(id << 1 | 1, m + 1, r, u, v));
    }
//    void build_rmq()
//    {
//        fr(i, 1, n) rmq[i][1] = st[euler[i]];
//
//        for(int j = 1; (1 << j) - 1 <= n; j++ ){
//            for(int i = 1; i + (1 << j) - 1 <= n; i++) {
//                rmq[i][j] = max(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
//            }
//        }
//    }
//    int get(int l, int r)
//    {
//        int j = lg(r - l + 1);
//        return min(rmq[l][j], rmq[r - (1 << j) + 1][j]);
//    }
    ll get_max(int x, int u)
    {
        ll ans = -1e9;
        while(chainID[x] != chainID[u]) {
            maxi(ans, get(1, 1, n, pos[chain[chainID[x]]], pos[x]));
//          maxi(ans, get(pos[chain[chainID[x]]], pos[x]));
            x = up[chain[chainID[x]]][0];
        }
        return ans;
    }
    void slv()
    {
        time = 0;
        mtc = 1;
        memset(t, 0, sizeof t);
        fr(i, 1, n) {
            chain[i] = pos[i] = chainID[i] = euler[i] = h[i] = sz[i]= st[i] = 0;
            fr(j, 0, lg(n)) up[i][j] = 0;
        }
//        fr(i, 1, n) cout << chain[i] << " "; cout << el;
        DFS(1, 1);
        hld(1, 1, 0);
//        fr(i, 1, n) cout << st[i] << " "; cout << el;
//        fr(i, 1, n) cout << chainID[i] << " "; cout << el;
//        fr(i, 1, n) cout << pos[i] << " "; cout << el;
        fr(i, 1, n) upd(1, 1, n, pos[i], st[i]);
//        fr(i, 1, 7) cout << t[i] << " "; cout << el;
//        build_rmq();
        string key;
        int x, y;
        while(cin >> key) {
            if(key == "DONE") {
                break;
            }
            if(key == "QUERY") {
                cin >> x >> y;
//                if(x == y) {
//                    cout << 0 << el;
//                    continue;
//                }
                int u = lca(x, y);
//                cout << u << el;
                ll ans = -1e9;

                maxi(ans, max(get_max(x, u), get_max(y, u)));
                if(h[x] < h[y]) maxi(ans, get(1, 1, n, pos[x] + 1, pos[y]));
                else maxi(ans, get(1, 1, n, pos[y] + 1, pos[x]));
//                if(h[x] > h[y]) swap(x, y);
//                maxi(ans, get(pos[x], pos[y]));

                cout << ans << el;
            }
            else {
                cin >> x >> y;
                int u = Q[x].x;
                int v = Q[x].y;
                if(h[u] < h[v]) swap(u, v);
                upd(1, 1, n, pos[u], y);
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
    cerr << clock() << "ms";
}


