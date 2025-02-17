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

const int MAX = 6005;
ll n, a[MAX], b[MAX], S;
void input()
{
    cin >> n >> S;
    fr(i, 1, n) cin >> a[i] >> b[i];
}
namespace sub1
{
    ll f[MAX*MAX];
    void slv()
    {
        f[0] = 1;
        fr(i, 1, n) {
            frd(x, S, b[i]) {
                fr(t, 1, a[i]) {
                    if(x < t*b[i]) continue;
                    (f[x] = f[x] + f[x - t*b[i]])%=MN;
                }
            }
        }
        cout << f[S];
    }
}
namespace sub2
{
    ll dp[MAX], f[MAX];
    void slv()
    {
        dp[0] = 1;
        fr(i, 1, n) {
            fr(x, 0, S){
                f[x] = dp[x];
                if(x >= b[i]) (f[x]+=f[x - b[i]])%=MN;
                if(x >= (a[i] + 1)*b[i]) {
                    f[x] = (f[x] - dp[x - (1 + a[i])*b[i]] + MN)%MN;
                }
            }
            swap(dp, f);
        }
        cout << dp[S];
    }
}
namespace sub3
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
    bool qs = 0;
    ll mtt = 1;
    if(qs) cin >> mtt;
    fr(i, 1, mtt){
        input();
        sub2::slv();
    //    sub2::slv();
    }
}

