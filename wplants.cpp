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

const int MAX = 5e4 + 2;
int n, k, a[MAX];
void input()
{
    cin >> n >> k; fr(i, 1, n) cin >> a[i];
}
namespace sub1
{

    int dp[MAX], lab[MAX];
    bool check(ll x)
    {
        dp[0] = 0;
        dp[1] = 1;
        fr(i, 2, n) {
            dp[i] = dp[i - 1] + 1;
            ll value = a[i] - a[i]/2 - x;
            ll l = 1, r = i - 1, m, pos;
            while(l <= r) {
                m = (r + l) >> 1;
                if(value <= lab[m]) pos = m, r = m - 1;
                else l = m + 1;
            }
            mini(dp[i], dp[pos - 1] + 1);
//            frd(j, i - 1, 1) {
//                int m = (a[i] + a[j])/2;
//                if(a[i] - m <= x) mini(dp[i], dp[j - 1] + 1);
//                else break;
//            }
            // tim a[j] voi j tu 1 -> i -  1 sao cho a[i] - (a[i] + a[j])/2 <= x => a[i] - a[i]/2 - a[j]/2 <= x - > a[i] - a[i]/2 - x <= a[j]/x
        }
        return (dp[n] <= k);
    }
    void slv()
    {
        sort(alla(a, n));
        fr(i, 1, n) lab[i] = a[i]/2;
      //  fr(i, 1, n) cout << a[i] << " "; cout << el;
        ll l = 0, r = MN, m, pos;
        while(l <= r) {
            m = (r + l) >> 1;
            if(check(m)) pos = m, r = m - 1;
            else l = m + 1;
        }
        cout << pos;
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


