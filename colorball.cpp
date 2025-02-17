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
pll a[MF];
void input()
{
    cin >> n;
    fr(i, 1, n) {
        cin >> a[i].fi >> a[i].se;
        if(a[i].fi > a[i].se) swap(a[i].fi, a[i].se);
    }
}
namespace sub1
{


    void slv()
    {
        fr(i, 1, n) cout << a[i].fi << " " << a[i].se << el;
        ll res = inf, amax, amin, cmax, cmin;
        REP(msk, 0, Mask(n)) {
            ll rmax = -inf, rmin = inf;
            ll bmax = -inf, bmin = inf;
            fr(i, 1, n) {
                if(msk&(1 << (i - 1))) {
                    maxi(rmax, a[i].fi);
                    mini(rmin, a[i].fi);
                    maxi(bmax, a[i].se);
                    mini(bmin, a[i].se);
                }
                else {
                    maxi(rmax, a[i].se);
                    mini(rmin, a[i].se);
                    maxi(bmax, a[i].fi);
                    mini(bmin, a[i].fi);
                }
            }
            if(mini(res, (rmax - rmin)*(bmax - bmin))) {
                amax = rmax;
                amin = rmin;
                cmax = bmax;
                cmin = bmin;
            }
        }
        cout << amax << " " << amin << " " << cmax << " " << cmin << el;
        cout << res;
    }
}
namespace sub2
{
    void slv()
    {
        ll rmax = -inf, rmin = inf, bmax = -inf, bmin = inf;

        sort(alla(a, n),[](pll a, pll b){return a.fi < b.fi;});

        fr(i, 1, n) cout << a[i].fi << " " << a[i].se << el;

        rmin = a[1].fi;
        rmax = a[n].fi;
        fr(i, 1, n) maxi(bmax, a[i].se), mini(bmin, a[i].se);

        ll res = (rmax - rmin)*(bmax - bmin);
        cout << res;


    }
}

main()
{
    #define TASK "task"
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    if( fopen( TASK".INP", "r") ){
        freopen( TASK".INP", "r", stdin);
        freopen( TASK".OUT", "w", stdout);
    }
    bool qs = 0 , b  = 1;
    ll mtt = 1;
    if(qs) cin >> mtt;
    fr(i, 1, mtt){
        input();
        sub2::slv();
    }
}
