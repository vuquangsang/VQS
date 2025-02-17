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
node a[MAX];
ll n;
void input()
{
    cin >> n;
    fr(i, 1, n) cin >> a[i].x >> a[i].y;
}
namespace sub1
{

    vector<ll> V;
    map<ll,ll> mp;
    ll dsum[MAX], low[4*MAX], high[4*MAX], lim, t[4*MAX];
    void upd(ll id, ll l, ll r, ll i, ll val)
    {
        if(i > r || i < l) return;
        if(l == r) {
            t[id]+=val;
            return;
        }
        int m = (r + l) >> 1;
        upd(id << 1, l, m, i, val);
        upd(id << 1 | 1, m + 1, r, i, val);
        t[id] = t[id << 1] + t[id << 1 | 1];
    }
    ll get(ll id, ll l, ll r, ll u, ll v)
    {
        if(r < u || v < l) return 0;
        if(u <= l && r <= v) return t[id];
        int m = (r + l) >> 1;
        return get(id << 1, l, m, u, v) + get(id << 1| 1 , m + 1, r, u, v);
    }
    void upd1(ll id, ll l, ll r, ll i, ll val)
    {
        if(i > r || i < l) return;
        if(l == r) {
            low[id]+=val;
            return;
        }
        int m = (r + l) >> 1;
        upd1(id << 1, l, m, i, val);
        upd1(id << 1 | 1, m + 1, r, i, val);
        low[id] = low[id << 1] + low[id << 1 | 1];
    }
    void upd2(ll id, ll l, ll r, ll i, ll val)
    {
        if(i > r || i < l) return;
        if(l == r) {
            high[id]+=val;
            return;
        }
        int m = (r + l) >> 1;
        upd2(id << 1, l, m, i, val);
        upd2(id << 1 | 1, m + 1, r, i, val);
        high[id] = high[id << 1] + high[id << 1 | 1];
    }
    ll get1(ll id, ll l, ll r, ll u, ll v)
    {
        if(r < u || v < l) return 0;
        if(u <= l && r <= v) return low[id];
        int m = (r + l) >> 1;
        return get1(id << 1, l, m, u, v) + get1(id << 1 | 1, m + 1, r, u, v);
    }
    ll get2(ll id, ll l, ll r, ll u, ll v)
    {
        if(r < u || v < l) return 0;
        if(u <= l && r <= v) return high[id];
        int m = (r + l) >> 1;
        return get2(id << 1, l, m, u, v) + get2(id << 1 | 1, m + 1, r, u, v);
    }
    void slv()
    {
        sort(alla(a, n), [](node a, node b){return a.x < b.x;});
        fr(i, 1, n) V.pb(a[i].y);
        sort(all(V));
        V.resize(unique(all(V)) - V.begin());

        fr(i, 0, V.size() - 1) {
            mp[V[i]] = i + 1;
        }
        lim = V.size();
        memset(low, 0, sizeof low);
        memset(high, 0, sizeof high);

        fr(i, 1, n) {
            if(i != 1) {
                ll number = get(1, 1, lim, 1, mp[a[i].y] - 1);
//                cout << i << " " << number << " " << get1(1, 1, lim, 1, mp[a[i].y] - 1) << " " << get2(1, 1, lim, mp[a[i].y], lim) << el;
                dsum[i]+=(number)*(a[i].x + a[i].y) + get1(1, 1, lim, 1, mp[a[i].y] - 1);

                dsum[i]+=(i - 1 - number)*(a[i].x - a[i].y) + get2(1, 1, lim, mp[a[i].y], lim);
            }
            upd(1, 1, lim, mp[a[i].y], 1);
            upd1(1, 1, lim, mp[a[i].y], -a[i].x - a[i].y);
            upd2(1, 1, lim, mp[a[i].y], -a[i].x + a[i].y);
        }
        ll res = 0;
//        fr(i, 1, n) cout << dsum[i] << " "; cout << el;
        fr(i, 1, n) res+=dsum[i];
        cout << res;
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


