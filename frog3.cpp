
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

ll n, c, h[MF];
void input()
{
    cin >> n >> c; fr(i, 1, n) cin >> h[i];
}
namespace sub1
{

    ll f[MF];
    void slv()
    {
        fr(i, 1, n) f[i] = inf;
        f[1] = 0;
        fr(i, 2, n) {
            fr(j, 1, i - 1) {
                mini(f[i], f[j] + (h[i] - h[j])*(h[i] - h[j]) + c);
            }
        }
        cout << f[n];
    }
}
namespace sub2
{
    struct line
    {
        ll a, b;
        line()
        {
            a = 0, b = inf;
        }
        line(ll _a, ll _b) {
            a = _a;
            b = _b;
        }
        ll operator()(ll x)
        {
            return a*x + b;
        }
    } t[4*MF];
    ll f[MF];
    void upd(ll id, ll l, ll r, line val)
    {
        if(l == r) {
            if(t[id](l) > val(l)) {
                t[id] = val;
            }
            return ;
        }
        int m = (r + l) >> 1;
        if(t[id].a < val.a) {
            swap(t[id], val);
        }
        if(t[id](m) > val(m)) {
            swap(t[id], val);
            upd(id << 1, l, m, val);
        }
        else upd(id << 1 | 1, m + 1, r, val);
    }
    ll get(ll id, ll l, ll r, ll x)
    {
        if(l == r) {
            return t[id](x);
        }
        ll m = (r + l) >> 1;
        if(x < m) {
            return min(t[id](x), get(id << 1, l, m, x));
        }
        else return min(t[id](x), get(id << 1 | 1, m + 1, r, x));
    }
    void slv()
    {
        f[1] = 0;
        upd(1, 1, 1e6, line(-2*h[1], f[1] + h[1]*h[1]));
        fr(i, 2, n) {
            f[i] = get(1, 1, 1e6, h[i]) + c + h[i]*h[i];
            upd(1, 1, 1e6, line(-2*h[i], f[i] + h[i]*h[i]));
        }
        cout << f[n];
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
        sub2::slv();
    //    sub2::slv();
    }
}


