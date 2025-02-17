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
template<class X, class Y>
    bool mini(X &x, const Y &y)  {
        if(x > y) {
            x = y;
            return 1;
        }
        else return 0;
    }
template<class X, class Y>
    bool maxi(X &x, const Y &y)
    {
        if(x < y) {
            x = y;
            return 1;
        }
        else return 0;
    }
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}

ll n, m;
vector<ll> g[MF];
void input()
{
    cin >> n ;
    ll x, y;
    fr(i, 1, n - 1) {
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
}
namespace sub1
{
    ll in[MF], out[MF], time = 0, a[MF], t[8*MF], lazy[8*MF];
    void DFS(ll u, ll p)
    {
        time++;
        in[u] = time;
        a[time] = u;
        for(int v : g[u]) if(v != p) {
            DFS(v, u);
        }
        out[u] = time;
    }
    void down(ll id, ll l, ll m, ll r)
    {
        if(lazy[id] != 0) {
            t[id << 1] = (m - l + 1)
            t[id << 1 | 1] = (r - m)
            lazy[id << 1] = 1;
            lazy[id << 1 | 1] = 1;
            lazy[id] = 0;
        }
    }
    void upd(ll id, ll l, ll r, ll u, ll v, ll val)
    {
        if(r < u || v < l) return ;
        if(u <= l && r <= v) {
            t[id] = (r - l + 1)*val;
            lazy[id] = val;
            return;
        }
        ll m = (r + l) >> 1;
        down(id, l, m, r);
        upd(id << 1, l, m, u, v, val);
        upd(id << 1 | 1, m + 1, r, u, v, val);
        t[id] = t[id << 1] + t[id << 1 | 1];
    }
    ll get(ll id, ll l, ll r, ll u, ll v)
    {
        if(r < u || v < l) return 0;
        if(u <= l && r <= v) return t[id];
        ll m = (r + l) >> 1;
        down(id, l, m, r);
        return get(id << 1, l, m, u, v) + get(id << 1 | 1, m + 1, r, u, v);
     }
    void slv()
    {
        DFS(1, 0);
        cin >> m;
        ll c,v ;
        while(m--) {
            cin >> c >> v;
            if(c == 1) {
                upd(1, 1, n, in[v], out[v], 1);
           //     cout << get(1, 1, n, 1, n); return;
            }
            else if(c == 2){
                upd(1, 1, n, in[v], in[v], 0);
            }
            else{
                ll value = get(1, 1, n, in[v], out[v]) ;
                if(value == out[v] - in[v] + 1) cout << 1;
                else cout << 0;
                cout << el;
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


