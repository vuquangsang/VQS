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

const ll sm = 1e9+7;
const long long inf = 1e18+7;
const ll base = 311;
const ll BLOCK = 320;
const int dx[5] = {0, -1, 1, 0 , 0};
const int dy[5] = {0, 0, 0, -1, 1};

struct node{ll x,y;};
struct pll{ll fi,se;};
template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}

const int N = 3005;
int n;
ll a[N];
void input()
{
    cin >> n; fr(i, 1, n) cin >> a[i];
}
namespace sub1
{
    ll sq(ll x)
    {
        return 1ll * x * x;
    }
    ll dp[N][N], pre[N];
    int best[N][N];
    void slv()
    {
        fr(i, 1, n) pre[i] = pre[i - 1] + a[i];
        memset(dp, 0x3f3f3f, sizeof dp);
        fr(i, 1, n) dp[i][i] = 0;
        fr(i, 1, n) fr(j, i, n) best[i][j] = i;
        fr(len, 2, n){
            fr(i, 1, n - len + 1) {
                int j = i + len - 1;
                fr(x, best[i][j - 1], best[i + 1][j]) {
                    if(mini(dp[i][j], dp[i][x] + dp[x + 1][j] + sq(pre[j] - pre[i - 1]))) best[i][j] = x;
                }
            }
        }
//        cout << dp[1][2]; return;
        cout << dp[1][n];
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


