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

ll n, k, L, R, a[MF];
void input()
{
    cin >> n >> k >> L >> R;
    fr(i, 1, n) cin >> a[i];
}
namespace sub1
{

    ll f[256][256][256];
    ll res = 0;
    void  trau(ll i, ll len, ll value) {
        if(i > n) {
            if(len == k && L <= value && value <= R && value%3 == 0) {
                res++;
            }
            return ;
        }
        trau(i + 1, len + 1, value|a[i]);
        trau(i + 1, len, value);
    }
    void slv()
    {
        trau(1, 0, 0);
        cout << res;
    }
}
namespace sub2
{
    ll f[256][256][256];
    void slv()
    {
        f[0][0][0] = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= k; j++) {
                for(int x = 0; x <= 255; x++) {
                    (f[i + 1][j][x]+=f[i][j][x])%=MN;
                    if(j + 1 <= k) (f[i + 1][j + 1][x|a[i + 1]]+=f[i][j][x])%=MN;

                }
            }
        }
        ll res = 0;
        fr(x, 0, min(R, (ll)255)) {
            (res+=f[n][k][x])%=MN;
        }
        cout << res;
    }
}
namespace sub3
{
    ll f[Mask(20) + 7], fac[MF], mod_fac[MF];
    ll cal(ll a, ll n)
    {
        if(!n) return 1;
        ll res = cal(a, n/2);
        res = mod(res, res);
        if(n&1) res = mod(res, a);
        return res;
    }
    ll C(ll k, ll n)
    {
        if(k > n) return 0;
        return mod(mod(fac[n], mod_fac[n - k]), mod_fac[k]);
    }
    void slv()
    {
        fac[0] = 1;
        fr(i, 1, n) fac[i] = mod(fac[i - 1], i);
        mod_fac[n] = cal(fac[n], MN - 2);
        frd(i, n - 1, 0) mod_fac[i] = mod(mod_fac[i + 1], i + 1);
        fr(i, 1, n) f[a[i]]++;
        REP(i, 0, 20) {
            REP(msk, 0, Mask(20)) if(msk&(1 << i)) {
                (f[msk]+=f[msk^Mask(i)])%=MN;
            }
        }
        REP(msk, 0, Mask(20)) {
            f[msk] = C(k, f[msk]);
            if(c_bit(msk)&1) f[msk] = (- f[msk] + MN)%MN;
        }
        REP(i, 0, 20) {
            REP(msk, 0, Mask(20)) if(BIT(msk, i)) {
                (f[msk]+=f[msk^Mask(i)])%=MN;
            }
        }
        ll res = 0;
        fr(msk, L, R) if(msk%3 == 0) {
            if(c_bit(msk)&1) (res+=(-f[msk] + MN)%MN)%=MN;
            else (res+=f[msk])%=MN;
        }
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
    if(qs) cin >> mtt;
    fr(i, 1, mtt){
        input();
        sub3::slv();
    //    sub2::slv();
    }
}



