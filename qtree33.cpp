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

const int MAX=  1e5+ 2;
ll n, q;
vector<ll> g[MAX];
void input()
{
    cin >> n >> q;
    ll x,y ;
    fr(i, 1, n - 1 ){
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
}
namespace sub1
{

    ll h[MAX], up[MAX][21], chain[MAX], chainID[MAX], time = 0, mtc = 1, sz[MAX], pos[MAX];
    void DFS(ll u, ll p )
    {
        up[u][0] = p;
        sz[u] = 1;
        fr(j, 1, lg(n)) up[u][j] = up[up[u][j - 1]][j - 1];
        for(int v : g[u]) if(v != p ) {
            h[v] = h[u] + 1;
            DFS(v, u);
            sz[u]+=sz[v];
        }
    }
    void hld(ll u, ll p)
    {
        if(!chain[mtc]) {
            chain[mtc] = u;
        }
        chainID[u] = mtc;
        pos[u] = time;
        int ans = 0;
        for(int v : g[u]) if(v != p ) {
            if(!ans || sz[v] > sz[ans]) ans = v;
        }
        if(ans) hld(ans, u);
        for(int v : g[u]) if(v != p && v != ans) {
            mtc++;
            hld(v, u);
        }
    }

    set<ll> st[MAX];
    ll get(ll x )
    {
        ll res = -1;
        ll tmp = chainID[x];
        while(1) {
            if(!st[tmp].empty()) {
                res = *st[tmp].begin();
            }
            if(tmp == 1) return res;
            x = up[chain[tmp]][0];
            tmp = chainID[x];
        }
    }
    void slv()
    {
        DFS(1, 0);
        hld(1, 0);
        ll x, k;
        while(q-- ){
            cin >> k >> x;
            if(!k)  {
                ll tmp = chainID[x];
                if(st[tmp].find(x) != st[tmp].end()) {
                    st[tmp].erase(x);
                }
                else {
                    st[tmp].insert(x);
                }
            }
            else {
                cout << get(x) << el;
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
    #define TASK ""
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


