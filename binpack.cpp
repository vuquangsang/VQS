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
const ll MF = 1e6+2;
const long long inf = 1e9+7;
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
const int MAXN = 1e4 + 2;

ll n, L, a[MF];
void input()
{
    cin >> L >> n; fr(i, 1, n) cin >> a[i];
}
namespace sub1
{


    void slv()
    {
        ll res = inf;
        fr(msk, 0, (1 << n) - 1) {
            ll value = 2;
            ll s1 = 0, s2 = 0;
            fr(i, 1, n) {
                if(msk&(1 << (i - 1))) {
                    if(s1 + a[i] > L) {
                        value++;
                        s1 = a[i];
                    }
                    else{
                        s1+=a[i];
                    }
                }
                else{
                    if(s2 + a[i] > L) {
                        value++;
                        s2 = a[i];
                    }
                    else{
                        s2+=a[i];
                    }
                }
            }
            mini(res, value);
        }
        cout << res;
    }
}
namespace sub2
{
    void slv()
    {
        pair<int, int> dp[n + 10][L + 10];
        for(int i =1; i <= n; i++ ){
            fr(x, 0, L){
                dp[i][x] = {inf, inf};
            }
        }
        dp[0][0] = {0, 0};
        fr(i, 0, n) {
            fr(x, 0, L) {
                if(dp[i][x].fi&& dp[i][x].se == inf) continue ;
                if(x + a[i + 1] <= L) {
                    mini(dp[i + 1][x + a[i + 1]], dp[i][x]);
                }
                mini(dp[i + 1][a[i + 1]], make_pair(dp[i][x].fi + 1, dp[i][x].se));
                if(dp[i][x].se + a[i + 1] <= L) {
                    mini(dp[i + 1][x], {dp[i][x].fi, dp[i][x].se + a[i + 1]});
                }
                mini(dp[i + 1][x], {dp[i][x].fi + 1, a[i + 1]});
            }
        }
        ll res = inf;
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



