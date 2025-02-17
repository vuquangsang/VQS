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

ll n, k, a[MF];
void input()
{
    cin >> n >>k; fr(i, 1, n) cin >> a[i];
}
namespace sub1
{
    pair<ll,ll> dp[MF];
    bool check(ll x)
    {
        ll ans = 0;
        fr(i, 1, n) {
            ans+=x;
            dp[i] = {ans - a[i], a[i] + ans};
        }
        sort(alla(dp, n));
   //     fr(i, 1, n) cout << dp[i].fi << " " << dp[i].se << el;
        vector<ll> v;
        v.pb(dp[1].se);
        fr(i, 2, n) {
            if(v.back() <= dp[i].se) v.pb(dp[i].se);
            else *upper_bound(all(v), dp[i].se) = dp[i].se;
        }
        // do dai day con khong lien tiep co khoang cach <= x
        return n - v.size() <= k;
    }
    ll cnp()
    {
        ll l = 0, r = *max_element(alla(a, n)) - *min_element(alla(a, n)), m;
        while(r - l > 1) {
            m = (r + l) >> 1;
            if(check(m)) r = m;
            else l = m;
        }
        if(check(l)) return l;
        return r;
    }
    void slv()
    {
        cout << cnp() << el;
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
    bool qs = 1;
    ll mtt = 1;
    if(qs) cin >> mtt;
    fr(i, 1, mtt){
        input();
        sub1::slv();
    }
}
