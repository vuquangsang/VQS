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

ll n, a[MF];
void input()
{
    cin >> n; fr(i, 1, n) cin >> a[i];
}
namespace sub1
{


    void slv()
    {
        ll res = 1;
        REP(msk, 0, Mask(n)) {
            ll ans = 0;
            ll k = c_bit(msk);
            if(k < res)  continue;
            fr(i, 1, n) if(msk&(1 << (i - 1))) {
                ans = gcd(ans, a[i]);
            }
            if(ans > 1) maxi(res, k);
        }
        cout << res;
    }
}
namespace sub2
{
    node f[MF];
    void slv()
    {
        sort(alla(a, n));
        if(a[1] > 1) f[1] = {1, a[1]};
        else f[1] = {0, 0};
        fr(i, 2, n){
            fr(j, 1, i - 1) {
                if(gcd(f[j].y, a[i]) > 1 && f[j].x + 1 > f[i].x) {
                    f[i] = {f[j].x + 1, gcd(f[j].y, a[i])};
                }
            }
        }
        ll res = 1;
        fr(i, 1, n) maxi(res, f[i].x); cout << res;
    }
}
namespace sub3
{
    ll cnt[MF], f[MF];
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
        sub1::slv(); cout << el << el; sub2::slv();
    }
}



