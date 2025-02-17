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
node a[MF];
void input()
{
    cin >> n; fr(i, 1, n) cin >> a[i].x >> a[i].y;
}
namespace sub1
{

    bool check(ll i, ll j)
    {
        int l = a[i].x;
        int r = a[i].y;
        int u = a[j].x;
        int v = a[j].y;
        if(r <= u || v <= l) return 1;
        return 0;
    }
    void slv()
    {
        ll res = -inf;
        fr(i, 1, n) {
            fr(j, i + 1, n) {
                if(check(i, j)) {
                    ll value = a[i].y - a[i].x + a[j].y - a[j].x;
                    maxi(res, value);
                }
            }
        }
        if(res != -inf) cout << res << el;
        else cout << -1;
    }
}
namespace sub2
{
    vector<ll> v;
    node pos[MF];
    ll t[MF], st[MF], lim;
    void upd(ll id, ll l, ll r, ll i, ll val, ll t[])
    {
        if(i > r || i < l) return;
        if(l == r) {
            maxi(t[id], val);
            return;
        }
        int m = (r + l) >> 1;
        upd(id << 1, l, m, i, val, t);
        upd(id << 1 | 1, m + 1, r, i, val, t);
        t[id] = max(t[id << 1], t[id << 1 | 1]);
    }
    ll get(ll id, ll l, ll r, ll u, ll v, ll t[])
    {
        if(r < u || v < l) return 0;
        if(u <= l && r <= v) return t[id];
        int m = (r + l) >> 1;
        return max(get(id << 1, l, m, u, v, t), get(id << 1 | 1, m + 1, r, u, v, t));
    }
    void slv()
    {
        fr(i, 1, n) {
            v.pb(a[i].x);
            v.pb(a[i].y);
        }
        sort(all(v));
        v.resize(unique(all(v)) - v.begin());
        fr(i, 1, n) {
            pos[i].x = lower_bound(all(v), a[i].x) - v.begin() + 1;
            pos[i].y = lower_bound(all(v), a[i].y) - v.begin() + 1;
        }
        lim = 2*n;
        ll res = -inf;
        upd(1, 1, lim, pos[1].x, a[1].y - a[1].x, t);
        upd(1, 1, lim, pos[1].y, a[1].y - a[1].x, st);
        fr(i, 2, n) {
            ll m1 = get(1, 1, lim, 1, pos[i].x, st);
            ll m2 = get(1, 1, lim, pos[i].y, lim, t);
            if(m1) {
                maxi(res, m1 + a[i].y - a[i].x);
            }
            if(m2) {
                maxi(res, m2 + a[i].y - a[i].x);
            }
            ll value = a[i].y - a[i].x;
            upd(1, 1, lim, pos[i].x, value, t);
            upd(1, 1, lim, pos[i].y, value, st);
        }
        if(res != -inf) cout << res;
        else cout << -1;

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
        sub1::slv(); cout << el << el;
        sub2::slv();
    }
}



