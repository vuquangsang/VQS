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

const ll MN = 1e9+7;
const long long inf = 1e18+7;
const ll base = 311;
const ll F = 1e5 + 2;
const ll BLOCK = 320;
const int dx[5] = {0, -1, 1, 0 , 0};
const int dy[5] = {0, 0, 0, -1, 1};
const short LO = 17;

struct node{ll x,y;};
struct pll{ll fi,se;};
ll mod(ll a, ll b) {return ((a%MN)*(b%MN))%MN;}
template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}

const int MF = 1e6 + 2;
ll n;
node a[MF];
void input()
{
    cin >> n; fr(i, 1, n) cin >> a[i].x >> a[i].y;
}
namespace sub1
{
    struct eg
    {
        ll x, y, w;
    };
    vector<eg> Q;
    bool cmp(eg a, eg b) {return a.w < b.w;}
    ll f[MF] ;
    ll goc(ll x) {
        while(f[x] > 0) {
            x = f[x];
        }
        return x;
    }
    void hn(ll r1, ll r2) {
        ll tmp = f[r1] + f[r2];
        if(f[r1] < f[r2]) {
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
        sort(a + 1, a + n + 1, [](node a, node b){return a.x < b.x;});
        fr(i, 2, n ){
            Q.pb({i, i - 1, a[i].x - a[i - 1].x});
        }
        sort(a + 1, a + n + 1, [](node a, node b){return a.y < b.y;});
        fr(i, 2, n ){
            Q.pb({i, i - 1, a[i].y - a[i - 1].y});
        }
        sort(all(Q), cmp);
        ll d = 0, res = 0;
        fr(i, 1, n) f[i] = -1;
        for(auto t : Q) {
            ll x = t.x;
            ll y = t.y;
            ll w = t.w;
            ll r1 = goc(x), r2 = goc(y);
            if(r1 != r2) {
                hn(r1, r2); d++; res+=w;
                if(d == n - 1) break;
            }
        } cout << res;

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
        sub2::slv();
    //    sub2::slv();
    }
}


