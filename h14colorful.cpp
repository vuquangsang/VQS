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
int n, q, a[MAX];
void input()
{
    cin >> n >> q; fr(i, 1, n) cin >> a[i];
}
namespace sub1
{

    ll t[4*MAX];
    void upd(ll id, ll l, ll r, ll i, ll val)
    {
        if(i > r || i < l) return;
        if(l == r) {
            t[id] = (1ll << (val));
            return;
        }
        int m = (r + l) >> 1;
        upd(id << 1, l, m, i, val);
        upd(id << 1 | 1, m + 1, r, i, val);
        t[id] = t[id << 1]|t[id << 1 | 1];
    }
    ll get(ll id, ll l, ll r, ll u, ll v)
    {
        if(r < u || v < l) return 0;
        if(u <= l && r <= v) return t[id];
        int m = (r + l) >> 1;
        return get(id << 1, l, m, u, v)|(get(id << 1 | 1, m + 1, r, u, v));
    }
    void slv()
    {
        fr(i, 1, n) upd(1, 1, n, i, a[i]);
        int k, u, v;
        while(q--) {
            cin >> k >> u >> v;
            if(k == 1) {
                int val = a[u];
                upd(1, 1, n, u, a[v]);
                upd(1, 1, n, v, a[u]);
                a[u] = a[v];
                a[v] = val;
            }
            else {
                cout << c_bit(get(1, 1, n, u, v)) << el;
            }
        }
    }
}
namespace sub2
{

    void slv()
    {
        int k, u, v;
        while(q--) {
            cin >> k >> u >> v;
            if(k == 1) {
                swap(a[u], a[v]);
            }
            else {
                set<ll> st;
                fr(i, u, v) {
                    st.insert(a[i]);
                }
                cout << st.size() << el;
            }
        }
    }
}
namespace sub3
{
    map<ll, ll> mp;
    vector<pll> qr[MAX];
    ll res[MAX], t[4*MAX];
    void upd(ll id, ll l,ll r, ll i, ll val)
    {
        if(i > r || i < l) return ;
        if(l == r){
            t[id] = val;
            return ;
        }
        ll m = (r + l) >> 1;
        upd(id << 1, l, m, i, val);
        upd(id << 1 | 1, m  + 1, r, i, val);
        t[id] = t[id << 1] + t[id << 1 | 1];
    }
    ll get(ll id, ll l, ll r, ll u, ll v)
    {
        if (r < u || v < l) return 0;
        if(u <= l  && r <= v) return t[id];
        ll m = (r + l) >> 1;
        return get(id << 1, l, m, u, v) + get(id << 1 | 1, m + 1, r,  u, v);
    }
    void slv()
    {
        ll x, y, k;
        fr(i, 1, q) {
            cin >> k >> x >> y;
            qr[y].pb({i, x});
        }
        fr(i, 1, n){
            upd(1, 1, 1e5, mp[a[i]], 0);
            mp[a[i]] = i;
            upd(1, 1, 1e5, i, 1);
            for(auto x : qr[i]){
                res[x.fi] = get(1, 1, 1e5, x.se, i);
            }
        }
        fr(i, 1, q) cout << res[i] << el;
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
//        sub3::slv(); return 0;
        if(*max_element(alla(a, n)) <= 20) sub1::slv();
        else if(n <= 1000 && q <= 1000) sub2::slv();
        else sub3::slv();
    }

}


