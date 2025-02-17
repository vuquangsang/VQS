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
#define     db double

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

struct node{double x,y;};
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

node a[MF];
ll n;
void input()
{
    cin >> n;
    fr(i, 1, n) cin >> a[i].x >> a[i].y;
}
namespace sub1
{
    node x;
    double sq(double x) {return x*x;}
    ll ccw(node a, node b, node c)
    {
        return (b.x - a.x)*(c.y - b.y) - (c.x - b.x)*(b.y - a.y);
    }
    db dist(node a, node b)
    {
         return (b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y);

    }
    bool cmp1(node a, node b)
    {
        if(ccw(x, a, b) == 0) return dist(x, a) < dist(x, b);
        return ccw(x, a, b) > 0;
    }
    bool cmp(node a, node b)
    {
        if(a.y == b.y) return a.x < b.x;
        return a.y < b.y;
    }
    void slv()
    {
        sort(alla(a, n), cmp);
        x = a[1];
        sort(a + 2, a + n + 1, cmp1);
        double res = 1e18;
        fr(i, 2, n) {
            mini(res, sqrt(sq(a[i].x - a[i - 1].x) + sq(a[i].y - a[i - 1].y)));
        }
        cout << fixed << setprecision(2) << res;
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



