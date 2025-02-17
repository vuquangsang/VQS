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

struct query
{
    ll l, r, x, y;
};
struct line
{
    ll p, u, v;
};
ll n, m, a[MF], q;
query Q[MF];
line qr[MF];
bool check = 1;
void input()
{
    cin >> n >> m; fr(i, 1, n) cin >> a[i];
    fr(i, 1, m) {
        cin >> Q[i].l >> Q[i].r >> Q[i].x >> Q[i].y;
        if(Q[i].l != 1 || Q[i].r != n) check = 0;
    }
    cin >> q;
    fr(i, 1, q) cin >> qr[i].p >> qr[i].u >> qr[i].v;
    fr(i, 1, q) {
        if(qr[i].u != 1 || qr[i].v != m) check = 0;
    }
}
namespace sub1
{

    ll pos[MF];
    void slv()
    {
        ll p, u, v;
        fr(i, 1, q) {
      //      cin >> p >> u >> v;
            p = qr[i].p;
            u = qr[i].u;
            v = qr[i].v;
            fr(i, 1, n) pos[i] = a[i];
            fr(i, u, v) {
                ll l = Q[i].l;
                ll r = Q[i].r;
                ll x = Q[i].x;
                ll y = Q[i].y;
                if(p > r || p < l) continue;
                fr(j, l, r) {
                    if(pos[j] == x) pos[j] = x + y;
                }
            }
            cout << pos[p] << el;
        }
    }
}
namespace sub2
{
    ll pos[MF];
    void slv()
    {
        ll p,u , v;
        fr(i, 1, q) {
            p = qr[i].p;
            u = qr[i].u;
            v = qr[i].v;
            fr(i, 1, n) pos[i] = a[i];
            fr(i, u, v) {
                ll l = Q[i].l;
                ll r = Q[i].r;
                ll x = Q[i].x;
                ll y = Q[i].y;
                if(l <= p && p <= r && pos[p] == x) pos[p] = x + y;
            }
            cout << pos[p] << el;
        }
    }
}
namespace sub3
{

}
main()
{
    #define TASK "cquery"
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
    }
}



