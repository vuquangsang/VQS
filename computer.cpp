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

ll x, a, y, b, n;
void input()
{
    cin >> x >> a >> y >> b >> n;
}
namespace sub1
{
    pair<ll,ll> f[N][N];
    pair<ll,ll> cal(pair<ll,ll> s, ll a, ll v)
    {
        s.se+=a;
        if(s.se >= v){
            ++s.fi;
            s.se = 0;
        }
        return s;
    }
    bool check(ll value)
    {
        fr(i, 0, x) fr(j, 0, y) f[i][j] = {0, 0};
        fr(i, 0, x) {
            fr(j, 0, y) {
                if(f[i][j].fi == n) return 1;
                if(i < x){
                    maxi(f[i + 1][j], cal(f[i][j], a, value));
                }
                if(j < y) {
                    maxi(f[i][j + 1], cal(f[i][j], b, value));
                }
            }
        }
        return 0;
    }
    ll cnp()
    {
        ll l = 0, r = (x*a + b*y)/n, m;
        while(r - l > 1) {
            m = (r + l) >> 1;
            if(check(m)) l = m;
            else r = m;
        }
        if(check(r)) return r;
        return l;
    }
    void slv()
    {

       cout << cnp() << el;
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
    ll mtt = 2;
    if(qs) cin >> mtt;
    fr(i, 1, mtt){
        input();
        sub1::slv();
    //    sub2::slv();
    }
}


