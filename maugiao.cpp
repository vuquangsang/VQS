#include <bits/stdc++.h>
using namespace std;

//#define   ll int
#define     lg(x) __log(x)
#define     alla(a,n) a+1,a+n+1
#define     el "\n"
#define     all(x) x.begin(),x.end()
#define     pb push_back
#define     ll long long
#define     fi first
#define     se second
#define     MASK(i) (1ll<<(i))
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

ll n, a[N][N];
void input()
{
    cin >> n;
    fr(i, 1, n) fr(j, 1, n) cin  >> a[i][j];

}
namespace sub1
{

    void slv()
    {
        ll tt = MASK(n) - 1;
        ll f[tt + 2], dd[tt + 2];
        fr(msk, 0, tt) {
            f[msk] = -inf;
            dd[msk] = 0;
        }
        f[0] = 0;
        dd[0] = 1;
        fr(msk, 0, tt) {
            ll k = c_bit(msk) ;
            REP(i, 0, n) if((msk&MASK(i)) == 0){
                ll p = msk|MASK(i);
                if(f[msk] + a[k + 1][i + 1] > f[p]) {
                    f[p] = f[msk] + a[k + 1][i + 1];
                    dd[p] = dd[msk];
                }
                else if(f[msk] + a[k + 1][i + 1] == f[p]) dd[p]+=dd[msk];
            }
        }
        cout << f[tt] << " " << dd[tt];
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


