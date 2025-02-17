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

node a[MF], b[MF];
ll n, m;
void input()
{
    cin >> n; fr(i, 1, n) cin >> a[i].x >> a[i].y;
    cin >> m; fr(i, 1, m) cin >> b[i].x >> b[i].y;
}
namespace sub1
{

    double cost[N][N];
    double dist(node a, node b)
    {
        return (double)sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
    }
    ll ccw(node A, node B, node C)
    {
        ll res = (B.x - A.x)*(C.y - B.y) - (B.y - A.y)*(C.x - B.x);
        if(res < 0) return -1;
        return res >= 1;
        // = = thang hang
        // < 0 re trai
        // > 0 re phai
    }
    double f[N][N];
    void slv()
    {
        fr(i, 1, m) cost[i][i] = inf;
        fr(i, 1, m) fr(j, 1, m) if(i != j) {
            bool ok = 1;
            fr(k, 1, n) {
                if(ccw(b[i], b[j], a[k]) <= 0) ok = 0;
                if(ok) cost[i][j] = dist(b[i], b[j]);
                else cost[i][j] = inf;
            }
        }
        fr(i, 1, m) fr(j, 1, m) f[i][j] = cost[i][j];
        fr(k, 1, m) {
            fr(i, 1, m) fr(j, 1, m) {
                mini(f[i][j], f[i][k] + f[k][j]);
            }
        }
        double res = inf;
        fr(i, 1, m) fr(j, 1, m){
            mini(res, (double)cost[i][j] + f[j][i]);
        }
        cout << fixed << setprecision(2) << (double)res;
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

