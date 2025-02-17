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

const int MAX = 2200;
struct qr
{
    int p,d, s;
};
qr Q[MAX];
int MOD;
int n, q, a[MAX];
void input()
{
    cin >> n >> q >> MOD; fr(i, 1, n) cin >> a[i];
    fr(i, 1, q) cin >> Q[i].p >> Q[i].d >> Q[i].s;
}
namespace sub1
{

    int dp[MAX];
    ll pre[MAX];
    void slv()
    {
        fr(t, 1, q) {
            int s = Q[t].s;
            int p = Q[t].p;
            int d = Q[t].d;
            memset(dp, 0, sizeof dp);
            a[p]-=d;
            dp[0] = 1;
            fr(i, 1, n) {
                fr(j, 1, a[i]) {
                    frd(x, s, i){
                        dp[x]+=(dp[x - i]);
                        dp[x]%=MOD;
                    }
                }
            }
            cout << dp[s] << el;
            a[p]+=d;
        }
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
    #define TASK "orangejuice"
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    if( fopen( TASK".INP", "r") ){
        freopen( TASK".INP", "r", stdin);
        freopen( TASK".OUT", "w", stdout);
    }
    int sub;
    cin >> sub;
    bool qs = 0;
    ll mtt = 1;
    if(qs) cin >> mtt;
    fr(i, 1, mtt){
        input();
        sub1::slv();
    //    sub2::slv();
    }
}



