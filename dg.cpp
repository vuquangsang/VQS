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

int n;
const int MAX = 31468140;
node a[2*MAX];
void input()
{
    cin >> n; fr(i, 1, 2*n) cin >> a[i].x >> a[i].y;
}
namespace sub1
{

    ll pos[MF];
    bool cmp(node a, node b) {return a.x - a.y > b.x - b.y;}
    bool cmp1(node a, node b) {return a.x > b.x;}
    bool cmp2(node a, node b) {return a.y > b.y;}
    bool cmp3(node a, node b) {return a.y - a.x > b.y - b.x;}
    ll cal()
    {
        ll res = 0;
        fr(i, 1, n) res+=a[i].x;
        fr(i, n + 1, 2*n) res+=a[i].y;
        return res;
    }
    ll add()
    {
        ll res = 0;
        fr(i, 1, n) res+=a[i].y;
        fr(i, n + 1, 2*n) res+=a[i].x;
        return res;
    }
    void slv()
    {
        ll res = 0;
        sort(a + 1, a + 2*n + 1, cmp);
        maxi(res, cal());
        sort(a + 1, a + 2*n + 1, cmp1);
        maxi(res, cal());
        sort(a + 1, a + 2*n + 1, cmp2);
        maxi(res, add());
        sort(a + 1, a + 2*n + 1, cmp3);
        maxi(res, add());
        cout << res;
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
    }
}



