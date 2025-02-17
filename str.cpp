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
const int MF = 1e5 + 5;
const ll base = 311;
const ll F = 1e5 + 2;
const ll BLOCK = 320;
const int dx[5] = {0, -1, 1, 0 , 0};
const int dy[5] = {0, 0, 0, -1, 1};
const short LO = 17;

struct node{ll x,y,w;};
struct pll{ll fi,se;};
ll mod(ll a, ll b) {return ((a%MN)*(b%MN))%MN;}
template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}


ll n;
node a[F];
void input()
{
    cin >> n; fr(i, 1, n) cin >> a[i].x >> a[i].y;
}
namespace sub1
{

    const int MAX = 1e5 + 2;
    ll f[MAX];
    node Q[MF];
    ll goc(ll x)
    {
        while(f[x] > 0) x = f[x];
        return x;
    }
    void hn(ll r1, ll r2)
    {
        ll tmp = f[r1] + f[r2];
        if(f[r2] < f[r1]) swap(r1, r2);
        f[r1] = tmp;
        f[r2] = r1;
    }
    void slv()
    {
        sort(a + 1, a + n + 1, [](node a, node b){return a.x < b.x;});
        // f[i] is min value when consider i
        // binary search to find distance min
        ll ans = 0;
        fr(i, 1, n) f[i] = -1;
        ll d = 0;
        fr(i, 1, n) {
            fr(j, i + 1, n) {
                ll value = min(abs(a[i].x - a[j].x), abs(a[i].y - a[j].y));
                Q[++d] = {i, j, value};
            }
        }
        sort(Q + 1, Q + d + 1, [](node a, node b){return a.w < b.w;});
        ll t = 0, res = 0;
        fr(i, 1, d){
            ll x = Q[i].x;
            ll y = Q[i].y;
            ll r1 = goc(x);
            ll r2 = goc(y);
            ll w = Q[i].w;
            if(r1 != r2) {
                hn(x, y);
                res+=w;
                t++;
                if(t == n - 1) break;
            }
        }
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
    //    sub2::slv();
    }
}


