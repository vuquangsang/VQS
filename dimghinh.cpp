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

ll n;
void input()
{
    cin >> n;
}
namespace sub1
{
    ll aMax = inf, aMin = -inf, bMax = inf, bMin = -inf, res = 0;
    ll x, y, u, v;
    void reset()
    {
        x = aMax;
        y = bMax;
        u = aMin;
        v = bMin;
    }
    void slv()
    {
        fr(t, 1, n) {
            ll maxa = -inf, mina = inf, maxb = -inf, minb = inf;
            fr(i, 0, 3) {
                cin >> x >> y;
                maxi(maxa, x + y);
                mini(mina, x + y);
                maxi(maxb, x - y);
                mini(minb, x - y);
            }
            maxi(aMin, mina);
            mini(aMax, maxa);
            maxi(bMin, minb);
            mini(bMax, maxb);
        }

        aMax--;
        bMax--;
        aMin++;
        bMin++;
        reset();
        if(x%2 == 0) x--;
        if(y%2 == 0) y--;
        if(u%2 == 0) u++;
        if(v%2 == 0) v++;
        res+=((y - v)/2 + 1)*((x - u)/2 + 1);
        reset();
        if(x%2) x--;
        if(y%2) y--;
        if(u%2) u++;
        if(v%2) v++;
        res+=((y - v)/2 + 1)*((x - u)/2 + 1);
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
    #define TASK "dimghinh"
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

