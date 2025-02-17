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
#define     sq(x) 1LL*(x)*(x)

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

ll n, c, a[MF];
void input()
{
    cin >> n >> c; fr(i, 1, n) cin  >> a[i];
}
namespace sub1
{

    const int MAXN = 1e4 + 3;
    ll dp[MAXN][N], t[MF], miL[MF], miR[MF];
    void build(int id)
    {
        miL[0] = inf;
        fr(i, 1, 1000)  miL[i] = min(miL[i - 1], dp[id][i] - i*c);
        miR[1001] = inf;
        frd(i, 1000, 1) miR[i] = min(miR[i + 1], dp[id][i] + i*c);
    }
    void slv()
    {
        memset(dp, 0x3f, sizeof dp);
        fr(x, a[1], 1e3) dp[1][x] = (x - a[1])*(x - a[1]);
        fr(i, 2, n) {
            build(i - 1);
            fr(x, a[i], 1e3) {
              /*  fr(y, a[i - 1], 1e3) {
                    ll value = x - a[i];
                    mini(dp[i][x], dp[i - 1][y] + value*value + c*abs(x - y));
                } */
                dp[i][x] = min(miL[x] + x*c + sq(x - a[i]), miR[x] - x*c + sq(x - a[i]));
            }
         //   fr(x, a[i], 1e3) upd(1, 1, 1e3, x, dp[i][x]);
        }
        ll res = inf;
        fr(x, 1, 1e3) mini(res, dp[n][x]);
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



