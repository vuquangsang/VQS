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

ll n, a[MF];
void input()
{
    cin >> n; fr(i, 1, n) cin >> a[i];
}
namespace sub1
{

    const  int MAX = 2002;
    ll dp[MAX][2][2];
    void slv()
    {
        a[0] = 0;
        ll res = inf;
        REP(msk, 0, Mask(n)) {
            ll ans = 0;
            int d1 = 0, d2 = 0;
            fr(i, 1, n) {
                if(msk&(1 << (i - 1))) {
                    ans = ans + abs(a[i] - d1);
                    d1 = a[i];
                }
                else {
                    ans = ans + abs(a[i] - d2);
                    d2 = a[i];
                }
            }
            mini(res, ans);
        }
        cout << res;
    }
}
namespace sub2
{
    const  int MAX = 2002;
    ll dp[MAX][2][2], ans[MF];
    void slv()
    {
        memset(dp, 0x3f, sizeof dp);
        memset(ans, 0x3f, sizeof ans);
        ans[1] = abs(a[1]);
        dp[1][1][0] = dp[1][0][1] = abs(a[1]);
        dp[0][0][1] = dp[0][1][0] = 0;
        fr(i, 2, n) {
            ll value;
            fr(j, 0, i - 1) {
                value = dp[j][1][0] + abs(a[i] - a[j]) + dp[i - 1][0][1];
                if()

            }
        }
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



