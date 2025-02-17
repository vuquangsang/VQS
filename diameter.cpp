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

const int MAX = 1e6 + 2;
int n, m, q;
node Q[MAX];
void input()
{
    cin >> n >> m >> q;
    fr(i, 1, m) cin >> Q[i].x >> Q[i].y;
}
namespace sub1
{

    bool check() {return (m == n - 1);}
    void slv()
    {
        ll x, y;
        while(q--){
            cin >> x >> y;
            cout << 0 << el;
        }
    }
}
namespace sub2
{
    bool check() {return (n <= 100 && m <= 100 && q <= 100);}
    ll f[MAX], dist[MAX], dia1[MAX], dia2[MAX];
    vector<ll> g[MAX], path[MAX];
    ll goc(ll x)
    {
        while(f[x] > 0) {
            x = f[x];
        }
        return x;
    }
    void hn(ll r1, ll r2)
    {
        ll tmp = f[r1] + f[r2];
        if(f[r2] < f[r1]) swap(r1, r2);
        f[r1] = tmp;
        f[r2] = r1;
        for(int x : g[r2]) g[r1].pb(x);
        g[r2].clear();
    }
    void DFS(ll u, ll p)
    {
        for(int v : path[u]) {
            if(v != p) {
                dist[v] = dist[u] + 1;
                DFS(v, u);
            }
        }
    }
    ll dia_t(ll u, ll k)
    {
        memset(dist, 0, sizeof dist);
        DFS(u, 0);
        if(k == 1) return *max_element(alla(dist, n));
        else {
            ll value = 0, root;

            fr(i, 1, n) if(maxi(value, dist[i])){
                root = i;
            }
            memset(dist, 0, sizeof dist);
            DFS(root, 0);
            return *max_element(alla(dist, n));
        }
    }
    ll cal(ll x, ll y)
    {
        ll r1 = goc(x);
        ll r2 = goc(y);
        if(r1 == r2) return 0;
        ll res = 0;

        for(int u : g[r1]) {
            ll ans = dia_t(u, 2);
            for(int v : g[r2]){
                maxi(ans, dia_t(v, 2));
                maxi(ans, dia_t(u, 1) + dia_t(v, 1) + 1);
            }
            res+=ans;
        }
        return res;
    }
    void slv()
    {
        fr(i, 1, n) f[i] = -1, g[i].pb(i);
        fr(i, 1, m){
            ll x = Q[i].x;
            ll y = Q[i].y;
            path[x].pb(y);
            path[y].pb(x);
            ll r1 = goc(x);
            ll r2 = goc(y);
            if(r1 != r2) {
                hn(r1, r2);
            }
        }

//        cout << dia_t(4, 2) << " " << dia_t(1, 1) << " " << el; return;

        ll x, y;
        while(q--){
            cin >> x >> y;
            cout << cal(x, y) << el;
        }
    }
}
namespace sub3
{
    ll f[MAX], dist[MAX], dia1[MAX], dia2[MAX];
    vector<ll> g[MAX], path[MAX];
    bool check() {
        return (m == n - 2);
    }
    ll goc(ll x)
    {
        while(f[x] > 0) {
            x = f[x];
        }
        return x;
    }
    void hn(ll r1, ll r2)
    {
        ll tmp = f[r1] + f[r2];
        if(f[r2] < f[r1]) swap(r1, r2);
        f[r1] = tmp;
        f[r2] = r1;
        for(int x : g[r2]) g[r1].pb(x);
        g[r2].clear();
    }
    void DFS(ll u, ll p)
    {
        for(int v : path[u]) {
            if(v != p) {
                dist[v] = dist[u] + 1;
                DFS(v, u);
            }
        }
    }
    ll dia_t(ll u, ll k)
    {
        memset(dist, 0, sizeof dist);
        DFS(u, 0);
        if(k == 1) return *max_element(alla(dist, n));
        else {
            ll value = 0, root;

            fr(i, 1, n) if(maxi(value, dist[i])){
                root = i;
            }
            memset(dist, 0, sizeof dist);
            DFS(root, 0);
            return *max_element(alla(dist, n));
        }
    }
    ll cal(ll x, ll y)
    {
        ll r1 = goc(x);
        ll r2 = goc(y);
        if(r1 == r2) return 0;
        ll res = 0;

        for(int u : g[r1]) {
            ll ans = dia_t(u, 2);
            for(int v : g[r2]){
                maxi(ans, dia_t(v, 2));
                maxi(ans, dia_t(u, 1) + dia_t(v, 1) + 1);
            }
            res+=ans;
        }
        return res;
    }
    void slv()
    {
        fr(i, 1, n) f[i] = -1, g[i].pb(i);
        fr(i, 1, m){
            ll x = Q[i].x;
            ll y = Q[i].y;
            path[x].pb(y);
            path[y].pb(x);
            ll r1 = goc(x);
            ll r2 = goc(y);
            if(r1 != r2) {
                hn(r1, r2);
            }
        }
        int special;
        ll res = 0;
        fr(i, 1, n) if(!path[i].size()) special = i;
        fr(i, 1, n){
            if(i != special) {
                res = cal(i, special);
                break;
            }
        }
        ll x, y;
        while(q--) {
            cin >> x >> y;
            if(special == x || special == y) cout << res << el;
            else cout << 0 << el;
        }
    }
}
main()
{
    #define TASK "DIAMETER"
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
        if(sub1::check()) return sub1::slv(), 0;
        if(sub3::check()) return sub3::slv(), 0;
        else return sub2::slv(), 0;
    //    sub2::slv();
    }
}


