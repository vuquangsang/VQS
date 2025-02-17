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

ll n, a[MF], W;
void input()
{
    cin >> n >> W;
    fr(i, 1, n) cin >> a[i];
}
namespace sub1
{
    ll t[MF], f[MF];
    vector<ll> v;
    void upd(ll id, ll l, ll r, ll i, ll val)
    {
        if(i > r || i < l) return;
        if(l == r) {
            maxi(t[id], val);
            return;
        }
        int m = (r + l) >> 1;
        upd(id << 1, l, m, i, val);
        upd(id << 1 | 1, m + 1, r, i, val);
        t[id] = max(t[id << 1], t[id << 1 | 1]);
    }
    ll get(ll id, ll l, ll r, ll u, ll v)
    {
        if(r < u || v < l) return 0;
        if(u <= l && r <= v) return t[id];
        int m= (r + l) >> 1;
        return max(get(id << 1, l, m, u, v), get(id << 1 | 1, m + 1, r, u , v));
    }
    void slv()
    {
        fr(i, 1, n) v.pb(a[i]);
        sort(all(v));
        v.resize(unique(all(v)) - v.begin());
        fr(i, 1, n) a[i] = lower_bound(all(v), a[i]) - v.begin() + 1;
        f[1] = 1;
        upd(1, 1, n, a[1], f[1]);
        fr(i, 2, n) {
            f[i] = get(1, 1, n, 1, a[i] - 1) + 1;
            upd(1, 1, n, a[i], f[i]);
        }
        cout << *max_element(alla(f, n));
    }
}
namespace sub2
{
    void slv()
    {
        ll f[n + 2][W + 2];
        fr(i, 1, n) fr(x, 0, W) f[i][x] = 0;
        f[1][a[1]] = 1;
        fr(i, 2, n) {
            f[i][a[i]] = 1;
            frd(x, W, a[i]){
                fr(j, 1, i - 1) {
                    if(a[i] > a[j]) maxi(f[i][x], f[j][x - a[i]] + 1);
                }
            }
        }
     //   cout << f[2][2]; return;
        ll res = 0;
        fr(i, 1, n) fr(x, 0, W) maxi(res, f[i][x]);
        cout << res;
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
    ll ans = 0;
    input();
    fr(i, 1, n) ans+=a[i];
    if(ans == W) sub1::slv();
    else sub2::slv();
}



