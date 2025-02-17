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
struct pll{ll fi,se;};
ll mod(ll a, ll b) {return ((a%MN)*(b%MN))%MN;}
template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}

ll n;
pll a[MF];
void input()
{
    cin >> n;
    fr(i, 1, n) cin >> a[i].fi;
    fr(i, 1, n) cin >> a[i].se;
}
namespace sub1
{
    bool cmp(pll a, pll b) {return a.fi < b.fi;}
    ll pos[MF], ma[MF];
    ll check(ll x)
    {
        fr(i, 1, n - 1) {
            ll value = x/a[i].fi;
            if(value*a[i].fi < x) value++;
            ll ind = lower_bound(alla(pos, n), value) - pos;
            if(ind == n + 1) continue;
            if(i >= ind) continue;
            if(a[i].se*ma[ind] >= x) return 1;
        }
        return 0;
    }
    ll cnp()
    {
        ll l = 0, r = inf, m;
        while(r - l > 1) {
            m = (r + l) >> 1;
            if(check(m)) l = m;
            else r = m;
        }
        if(check(r)) return r;
        return l;
    }
    void slv()
    {
        sort(a + 1, a + n + 1, cmp);

        ma[n] = a[n].se;
        frd(i, n - 1, 1) ma[i] = max(ma[i + 1], a[i].se);
        cout << cnp();
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



