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
struct line{ll s,e,p;};
ll n;
line a[MF];
void input()
{
    cin >> n;
    fr(i, 1, n) cin >> a[i].s >> a[i].e >> a[i].p;
}
namespace sub1
{

    ll f[3003][3];
    vector<ll> v;
    line pos[MF];
    bool cmp(line a, line b) {return a.s < b.s;}
    void Comp()
    {
        fr(i, 1, n) {
            v.pb(a[i].s);
            v.pb(a[i].e);
            v.pb(a[i].p);
        }
        sort(all(v));
        v.resize(unique(all(v)) - v.begin());
        sort(alla(a, n), cmp);
        fr(i, 1, n) {
            pos[i].s = lower_bound(all(v), a[i].s) - v.begin() + 1;
            pos[i].e = lower_bound(all(v), a[i].e) - v.begin() + 1;
            pos[i].p = lower_bound(all(v), a[i].p) - v.begin() + 1;
        }
    }
    void slv()
    {
        sort(alla(a, n), cmp);
        f[1][1] = a[1].p;
        f[1][2] = a[1].p;
        fr(i, 2, n) {
            fr(j, 1, i - 1) {
                if(a[i].s >= a[j].e) {
                    maxi(f[i][1], max(f[j][1], f[j][2]) + a[i].p);
                    maxi(f[i][2], max(f[j][1], f[j][2]) + a[i].p);
                }
            }
        }
        ll res = 0;
        res = max(f[n][1], f[n][2]);
        cout << res << el;
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
    bool qs = 1;
    ll mtt = 1;
    if(qs) cin >> mtt;
    fr(i, 1, mtt){
        input();
        cout << "#" << i << " ";
        sub1::slv();
    //    sub2::slv();
    }
}



