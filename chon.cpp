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

const int MAX = 1e3 + 2;
ll n, s;
node a[MAX];
void input()
{
    cin >> n >> s;
    fr(i, 1, n) cin >> a[i].x >> a[i].y;
}
namespace sub1
{
    const int N = 3e4 + 2;
    long long dp[MAX][N];
    bool cmp(node a, node b)
    {
        if(a.y > 0 && b.y > 0) return a.x > b.x;
        if(a.y < 0 && b.y < 0) return a.x + a.y >= b.x + b.y;
        return a.y > b.y;
    }
    void slv()
    {
        sort(alla(a, n), cmp);
        // dp[i][x] is s min when i(1->n) and x(0 -> lim)
        dp[0][s] = 1;
        ll res = s;
        REP(i, 0, n) fr(x, 0, 3e4) {
            if(dp[i][x]) {
                dp[i + 1][x] = 1;
                if(x >= a[i + 1].x) {
                    mini(res, x + a[i + 1].y);
                    if(x + a[i + 1].y <= 3e4) dp[i + 1][x + a[i + 1].y] = 1;
                }
            }
        }
        cout << res;
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


