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

const int MAX = 1e5 + 2;
ll m,T, d[MAX];
void input()
{
    cin >> m >> T;
    fr(i, 1, m) cin >> d[i];
    sort(d + 1, d + m + 1, [](ll a, ll b){return a > b;});
}
namespace sub1
{

    ll f[105][MAX], sum[MAX];
    void slv()
    {
        fr(i, 1, m) sum[i] = sum[i - 1] + d[i];
        int lim = 1e5;
        fr(i, 0, m) fr(x, 0, lim) f[i][x] = inf;
        f[0][0] = 0;
        fr(i, 1, m) fr(s, i, lim) {
            f[i][s] = f[i][s - i];
            fr(j, 0, i - 1) mini(f[i][s], f[j][s - i] + j*(sum[i] - sum[j]));
        }
        ll n;
        while(T--) {
            cin >> n;
            if(n%m == 0) cout << 0 << " ";
            else cout << f[m][n] << " ";
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

