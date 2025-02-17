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

ll n, a[MF], k;
void input()
{
    cin >> n >> k; fr(i, 1, n) cin >> a[i];
}
namespace sub1
{
    // goi f[i] la day co it nhat k phan tu và đạt được giá t4rij lớn nhất
    // f[i] = gcd(a[i] - a[i - k + 1])*(sum . )
    ll f[MF], pre[MF], rmq[MF][21], t[MF];
    void build()
    {
        REP(i, 0, n) rmq[i][0] = a[i + 1];
        for(int j = 1; (1 << j) < n; j++) {
            for(int i = 1; (i + (1 << j) - 1) < n; i++) {
                rmq[i][j] = gcd(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    ll get(ll l, ll r)
    {
        l--; r--;
        ll j = lg(r - l + 1);
        return gcd(rmq[l][j], rmq[r - (1 << j) + 1][j]);
    }
    void build1(ll id, ll l, ll r)
    {
        if(l == r) {
            t[id] = a[l]; return ;
        }
        ll m = (r + l) >> 1;
        build1(id << 1, l, m);
        build1(id << 1 | 1, m + 1, r) ;
        t[id] = gcd(t[id << 1], t[id << 1 | 1]);
    }
    ll get1(ll id, ll l, ll r, ll u, ll v)
    {
        if(r < u || v < l) return 0;
        if(u <= l && v <= r) return t[id];
        ll m = (r + l) >> 1;
        return gcd(get1(id << 1, l, m, u, v), get1(id << 1 | 1, m + 1, r, u, v));
    }
    void slv()
    {
        build1(1, 1, n);
        ll res = 0;
        fr(i, 1, n) pre[i] = pre[i - 1] + a[i];
        fr(i, k, n) {
            fr(j, 1, i - k + 1) {
                maxi(res, get1(1, 1, n, j, i)*(pre[i] - pre[j - 1]));
            }
        }
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



