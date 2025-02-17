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

struct node{ll c,x,y,w;};
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

ll n, m, s, t;
node a[MF];
void input()
{
    cin >> n >> m >> s >> t;
    fr(i, 1, m) cin >> a[i].c >> a[i].x >> a[i].y >> a[i].w;
}
namespace sub1
{

    bool cmp(node a, node b) {return a.w < b.w;}
    ll f[MF];
    ll goc(ll x)
    {
        while(f[x] > 0) {
            x = f[x];
        }
        return x;
    }
    void hn(ll r1, ll r2)
    {
        ll tmp = f[r1] + f[r2];
        if(abs(f[r1]) >= abs(f[r2])) {
            f[r1] = tmp;
            f[r2] = r1;
        }
        else{
            f[r2] = tmp;
            f[r1] = r2;
        }
    }
    void slv()
    {
        sort(alla(a, m), cmp);
        fr(i, 1, n) f[i] = -1;
        fr(i, 1, m) {
            ll r1 = goc(a[i].x);
            ll r2 = goc(a[i].y);
            ll w = a[i].w;
            if(r1 != r2) {
                hn(r1, r2);
            }
            ll u = goc(s);
            ll v = goc(t);
            if(u == v) {
                cout << w; return ;
            }
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

