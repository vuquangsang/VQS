/* Vu Quang Sang from Le Khiet High School for Gifted */
#include <bits/stdc++.h>
using namespace std;

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

const ll MN = 1e9+7;
const long long inf = 1e18+7;
const ll base = 311;
const ll BLOCK = 320;
const int dx[5] = {0, -1, 1, 0 , 0};
const int dy[5] = {0, 0, 0, -1, 1};

struct node{ll x,y;};
struct pll{ll fi,se;};
ll mod(ll a, ll b) {return ((a%MN)*(b%MN))%MN;}
template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}

const int MAX = 305;
int n, k, a[MAX];
void input()
{
    cin >> n >> k;
    fr(i, 1, n) cin >> a[i];
}
namespace sub1
{
    ll dp[MAX][MAX][MAX];
    ll res = -inf;
    ll cal(ll l, ll r, ll k)
    {
        if(l > r) {
            if(!k) return 0;
            return -inf;
        }
        if(!k) return 0;

        if(dp[l][r][k] > 0) return dp[l][r][k];
        if(r - l + 1 >= 2) {
            maxi(dp[l][r][k], abs(a[l] - a[l + 1]) + cal(l + 2, r, k - 1));
            maxi(dp[l][r][k], abs(a[r] - a[r - 1]) + cal(l, r - 2, k - 1));
            maxi(dp[l][r][k], abs(a[l] - a[r]) + cal(l + 1, r - 1, k - 1));
        }
        maxi(dp[l][r][k], cal(l + 1, r, k));
        maxi(dp[l][r][k], cal(l, r - 1, k));
        maxi(res, dp[l][r][k]);
        return dp[l][r][k];
    }
    void slv()
    {
        memset(dp, -1, sizeof dp);
        cout << cal(1, n, k);
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


