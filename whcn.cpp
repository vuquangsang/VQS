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

struct node{ll x,y;};
struct bg{ll id,ts;};
struct pll{ll fi,se;};
struct init{ll in,va;bool operator <(init const&a)const{return this->va>a.va;}};
ll mod(ll a, ll b) {return ((a%MN)*(b%MN))%MN;}
template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}

char a[N][N];
ll n, m;
void input()
{
    cin >> n >> m;
    fr(i, 1, n) fr(j, 1, m) cin >> a[i][j];

}
namespace sub1
{

    ll f[N][N], pre[N][N];
    void slv()
    {
        fr(i, 1, n) fr(j, 1, m) if(a[i][j] == '.') pre[i][j] = 1;
        fr(i, 1, n) fr(j, 2, m) pre[i][j] = pre[i][j - 1] + pre[i][j];
        fr(j, 1, m) fr(i, 2, n) pre[i][j] = pre[i - 1][j] + pre[i][j];

        fr(x, 1, n) fr(y, 1, m) {
            ll ans = 0;
            fr(i, x, n) fr(j, y, m) {
                ll value = pre[i][j] - pre[x - 1][j] - pre[i][y - 1] + pre[x-  1][y - 1];
                cout << x << " " << y << " " << i << " " << j << el;
                if(value == x*y) ans++;
            }
            f[x][y] = ans;
        }
        fr(i, 1, n) {
            fr(j, 1, m)  {s
                cout << f[i][j] << " ";
            } cout << el;
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

