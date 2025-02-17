/* Vu Quang Sang from Le Khiet High School for Gifted */
#include <bits/stdc++.h>
using namespace std;

//#define   ll int
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
#define     BIT(msk, i) (msk&(1 << i))

const ll MN = 1e9+7;
const ll MF = 1e6+7;
const long long inf = 1e18+7;
const ll N = 1005;
const ll base = 311;
const ll F = 1e5 + 2;
const ll BLOCK = 320;
const int dx[5] = {0, -1, 1, 0 , 0};
const int dy[5] = {0, 0, 0, -1, 1};
const short LO = 17;

struct node{ll x,y;};
struct bg{ll id,ts;};
struct pll{ll fi,se;};
struct init{ll in,va;bool operator <(init const&a)const{return this->va>a.va;}};
ll mod(ll a, ll b) {return ((a%MN)*(b%MN))%MN;}
template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}

ll n;
vector<ll> g[MF];
void input()
{
    cin >> n;
    ll x, y;
    fr(i, 2, n) {
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
}
namespace sub1
{
    ll in[MF], out[MF], time = 0, euler[MF];

    void DFS(ll u, ll p)
    {
        in[u] = ++time;
        euler[time] = u;
        for(int v : g[u]) if(v != p) {
            DFS(v, u);
        }
        out[u] = time;
    }
    void down(ll id, ll l, ll m, ll r)
    {
        if(lazy[id] != -1) {
            ll x = lazy[id];
            t[id << 1] = x;
            t[id << 1 | 1] = x;
            lazy[id << 1] = x;
            lazy[id << 1 | 1] = x;
            lazy[id]  = -1;
        }
    }
    void upd(ll id, ll l, ll r, ll u, ll v, bool val)
    {
        if(r < u || v < l) return;
        if(u <= l && r <= v) {
            t[id] = val;
            lazy[id] = val;
            return;
        }
        int m = (r + l) >> 1;
        down(id, l, m, r);
        upd(id << 1, l, m, u, v);
        upd(id << 1 | 1, m + 1, r, u, v);
        t[id] = max(t[id << 1], t[id << 1 | 1]);
    }
    ll get(ll id, ll l, ll r, ll i)
    {
        if(i > r || i < l) return -inf;
        if(l == r) return t[id];
        int m = (r + l) >> 1;
        down(id, l, m, r);
        return max(get(id << 1, l, m, u, v), get(id << 1 | 1, m + 1, r, u, v));
    }
    void slv()
    {

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



