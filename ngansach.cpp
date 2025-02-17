/* Vu Quang Sang from Le Khiet High School for Gifted */
#include <bits/stdc++.h>
using namespace std;

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

const int N = 22;
ll n, m, a[N], b[N];
void input()
{
    cin >> n >> m;
    fr(i, 1, n) cin >> a[i];

    fr(i, 1, m) cin >> b[i];
}
namespace sub1
{
    const int NN = (1 << 20) + 2;
    const int MAX = 1e2 + 12;
    int dp[MAX][21][21][1000];
    ll f[NN][21];
    ll cal(int msk, int j, int g, int s)
    {
        if(g > n) return 1;
        if(s == a[g]) return cal(msk, 1, g + 1, 0);
        if(j > m) return 0;
        if(f[msk][j] != -1) return  f[msk][j];
        ll cnt= 0 ;
        fr(x, j, m) {
            if(s + b[x] <= a[g] && ((1 << (x - 1)&msk) == 0)) cnt+=cal(msk|(1 << (x - 1)), x +  1, g, s + b[x]), cnt%=MN;
        }
        f[msk][j] = cnt%MN;
        return cnt;
    }
    void slv()
    {
        memset(f, -1, sizeof f);
        cout << cal(0, 1, 1, 0) << el;
    }
}
namespace sub2
{

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
    bool qs = 1;
    ll mtt = 1;
    if(qs) cin >> mtt;
    fr(i, 1, mtt){
        input();
        sub1::slv();
    }
}


