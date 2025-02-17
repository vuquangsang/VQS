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
const int sm = 998244353;

struct node{ll x,y;};
struct bg{ll id,ts;};
struct pll{ll fi,se;};
struct init{ll in,va;bool operator <(init const&a)const{return this->va>a.va;}};
ll mod(ll a, ll b) {return ((a%sm)*(b%sm))%sm;}
template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}
const int MAXN = 2209;
int n, m;
int a[MAXN][MAXN];
void input()
{
    cin >> n >> m;
    char c;
    fr(i, 1, n) fr(j, 1, m) {
        cin >> c;
        a[i][j] = c - '0';
    }
}
namespace sub1
{

    int f[MAXN][MAXN], g[MAXN][MAXN];
    void slv()
    {
        f[1][1] = 1;
        fr(i, 1, n)  fr(j, 1, m) {
            f[i][j]+=f[i - 1][j];
            f[i][j]%=sm;

            f[i][j]+=f[i][j - 1];
            f[i][j]%=sm;

            f[i][j]+=f[i - 1][j - 1];
            f[i][j]%=sm;
        }
        g[n][m] = 1;
        frd(i, n, 1) frd(j, m, 1) {
            g[i][j]+=g[i + 1][j];
            g[i][j]%=sm;

            g[i][j]+=g[i][j + 1];
            g[i][j]%=sm;

            g[i][j]+=g[i + 1][j + 1];
            g[i][j]%=sm;
        }
        ll value = 0;
        fr(i, 1, n){
            fr(j, 1, m) {
                value = value + mod(a[i][j], mod(f[i][j], g[i][j]));
                value%=sm;
            }
        }
        cout << value;
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
    #define TASK "sumpath"
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



