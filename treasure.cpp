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

node Q[MF];
ll n, k , a[MF], qr[MF];
void input()
{
    cin >> n >> k; fr(i, 1, n) cin >> a[i];
    ll x, y;
    fr(i, 1, k) {
        cin >> x >> y;
        Q[i] = {x, y};
    }
    fr(i, 1, k) cin >> qr[i];
}
namespace sub1
{

    ll f[MF], ans[MF];
    bool dd[MF];
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
        fr(i, 1, n) f[i] = -1;
        ll res = 0;
        frd(i, k, 1) {
            int p = qr[i];
            ans[i] = res;
            int x = Q[p].x;
            int y = Q[p].y;
   //         cout << x << " " << y << el;
     //       ll r1 = goc(x);
     //       ll r2 = goc(y);
          //  if(r1 != r2) {
                if(a[x] < a[y]) swap(x, y);
                if(!dd[x]) res+=a[x], dd[x] = 1;
                else if(!dd[y]) res+=a[y], dd[y] = 1;
           // }
        }
        fr(i, 1, k) cout << ans[i] << el;
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



