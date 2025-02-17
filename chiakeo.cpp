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

ll n, k, m;
void input()
{
    cin >> n >> k >> m;
}
namespace sub1
{

    ll dp[46][502][502];
    void slv()
    {
        fr(s, 1, n) dp[1][s][s] = 1;
        int lim = sqrt(n) + 1;
        fr(i, 1, lim) fr(s, 1, n) {
            fr(c, 1, n) {
                fr(tmp, 1, n) {
                    int tmp_c = c + k + tmp;
                    if(s + tmp_c <= n) (dp[i + 1][s + tmp_c][tmp_c]+=dp[i][s][c])%=m;
                }
            }
        }
        ll res = 0;
        fr(i, 2, lim) fr(c, 1, n) {
            res = res + dp[i][n][c];
            res%=m;
        }
        cout << res;
    }
}
namespace sub2
{
    const int MAX = 1e5 + 2;
    const int lim = 320;
    ll dp[lim + 3][MAX];
    void slv()
    {

        fr(x, 1, n) dp[1][x] = 1;
        fr(i, 2, lim) fr(x, i, n) {
            (dp[i][x]+=dp[i][x - i])%=m;

            int tmp = x - 1 - (k + 1)*(i - 1);
            if(tmp > 0) (dp[i][x]+=dp[i - 1][tmp])%=m;
        }
        ll res = 0;
        fr(i, 2, lim) (res+=dp[i][n])%=m;
        cout << res;
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


