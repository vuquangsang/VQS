/* Vu Quang Sang from Le Khiet High School for Gifted */
#include <bits/stdc++.h>
using namespace std;

//#define   ll int
#define     lg(x) __lg(x)
#define     alla(a,n) a+1,a+n+1
#define     el "\n"
#define     all(x) x.begin(),x.end()
#define     pb push_back
#define     ll int
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

ll L, n, a[MF];
void input()
{
    cin >> L >> n; fr(i, 1, n) cin >> a[i];
}
namespace sub1
{


    void slv()
    {
        ll ans = MN;
        REP(msk, 0, Mask(n)) {
            ll m1 = 0, m2 = 0, res = 0;
            fr(i, 1, n) {
                if(msk&(1 << (i - 1))) {
                    if(m1 + a[i] > L){
                        res++;
                        m1 = a[i];
                    }
                    else m1+=a[i];
                }
                else{
                    if(m2 + a[i] > L) {
                        res++;
                        m2 = a[i];
                    }
                    else m2+=a[i];
                }
            }
            mini(ans, res);
        }
        cout << ans + 2;
    }
}
namespace sub2
{
    const int MAX = 1e4 + 2;
 //   pair<ll,ll> dp[MAX][5002];
    void slv()
    {
        pair<ll,ll> dp[n + 2][L  + 2];
        fr(i, 0, n) fr(x, 0, L) dp[i][x] = {MN, MN};
        dp[0][0] = {0, 0};
        REP(i, 0, n) {
            fr(x, 0, L) {
                if(dp[i][x].fi && dp[i][x].se == MN) continue;
                if(x + a[i + 1] <= L) {
                    mini(dp[i + 1][x + a[i + 1]], dp[i][x]);
                }
                mini(dp[i + 1][a[i + 1]], {dp[i][x].fi + 1, dp[i][x].se});
                if(dp[i][x].se + a[i + 1] <= L) {
                    mini(dp[i + 1][x], {dp[i][x].fi, dp[i][x].se + a[i + 1]});
                }
                mini(dp[i + 1][x], {dp[i][x].fi + 1, a[i + 1]});
            }
        }
        ll res = MN;
        fr(x, 0, L) mini(res, dp[n][x].fi);
        cout << res + 2;
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
        if(n <= 20) sub1::slv();
        else sub2::slv();
    }
}




