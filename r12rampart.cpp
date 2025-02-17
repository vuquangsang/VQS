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

const int MAX = 1e4 + 5;
int n, a[MAX];
void input()
{
    cin >> n; fr(i, 1, n) cin >> a[i];
}
namespace sub1
{

    ll f[MAX][MAX/2 + 10];
    void slv()
    {
        if(a[1] > 0) {cout << 0; return;}
        if(a[n] > 0) {cout << 0; return;}
        f[1][0] = 1;
        int m = (n - 1)/2;
        fr(i, 2, n) {
            if(a[i] > m) {cout << 0; return;}
            if(a[i] == -1) {
                f[i][0] = f[i - 1][0] + f[i - 1][1];
                fr(j, 1, m) {
                    f[i][j] = ((f[i - 1][j] + f[i - 1][j - 1])%MN + f[i - 1][j + 1]%MN)%MN;
                    f[i][j]%=MN;
                }
            }
            if(a[i] >= 0) {
                fr(j, 0, m){
                    f[i][j] = 0;
                    f[i][a[i]] = ((f[i - 1][a[i] - 1] + f[i - 1][a[i]])%MN + f[i - 1][a[i] + 1]%MN);
                    f[i][a[i]]%=MN;
                }
            }
        }
        cout << f[n][0]%MN;
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


