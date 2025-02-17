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

const ll MN = 998244353;
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

ll n, a[MF];
void input()
{
    cin >> n; fr(i, 1, n) cin >> a[i];;
}
namespace sub1
{
    ll fac[MF], mod_fac[MF], f[MF];
    ll cal(ll a, ll n)
    {
        if(!n) return 1;
        ll res = cal(a, n/2);
        res = mod(res, res);
        if(n&1) res = mod(res, a);
        return res;
    }
    ll C(ll n, ll k)
    {
        return mod(mod(fac[n], mod_fac[n - k]), mod_fac[k]);
    }
    void slv()
    {
        fac[0] = 1;
        fr(i, 1, n) fac[i] = 1ll*fac[i - 1]*i%MN;
        mod_fac[n] = cal(fac[n], MN - 2);
        frd(i, n - 1, 1) mod_fac[i] = mod(mod_fac[i + 1], i + 1);
        f[n + 1] = 1;
        ll ans = 0;
        frd(i, n - 1, 1) {
            if(a[i] <= 0) continue ;
            for(int j = i + a[i]; j <= n; j++) {
                f[i] = f[i] + 1ll*(f[j + 1], C(j - i, a[i])%MN);
                f[i]%=MN;
            }
            ans+=f[i];
        } cout << ans;
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



