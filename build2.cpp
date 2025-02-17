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

struct vqs
{
    ll t, r;
    bool operator <(vqs const&a) const
    {
        return this-> t > a.t;
    }
};
ll n, T;
vqs a[MF];
void input()
{
    cin >> n >> T;
    fr(i, 1, n) cin >> a[i].t >> a[i].r;
}
namespace sub1
{

    ll f[MF], sumtr[MF], sumr[MF];
    void slv()
    {
        sort(a + 1, a + n + 1);
        fr(i, 1, n)  {
            sumtr[i] = sumtr[i - 1] + a[i].t*a[i].r;
            sumr[i] = sumr[i - 1] + a[i].r;
        }
        memset(f, 0x3f, sizeof(f));
        f[0] = 0;
        fr(i, 1, n) {
            fr(j, 0, i - 1) {
                mini(f[i], f[j] + T + sumtr[i] - sumtr[j] - (sumr[i] - sumr[j])*a[i].t);
            }
        }
        ll res = inf;
        fr(i, 0, n) mini(res, f[i] + sumtr[n] - sumtr[i]);
        cout << res;
    }
}
namespace sub2
{
    struct line
    {
        ll a, b;
        line()
        {
            a = 0, b = inf;
        }
        line(ll _a, ll _b)
        {
            a = _a;
            b = _b;
        }
        ll operator() (ll x)
        {
            return a*x + b;
        }
    };
    line t[4*MF];
    ll f[MF], sumtr[MF], sumr[MF];
    void upd(ll id, ll l, ll r, line L)
    {
        if(l == r) {
            if(t[id](l) > L(l)) swap(t[id], L);
            return;
        }
        int m = (r + l) >> 1;
        if(t[id].a > L.a) swap(t[id], L);
        if(t[id](m) > L(m)){
            swap(t[id], L);
            upd(id << 1 | 1, m + 1, r, L);
        }
        else upd(id << 1, l, m, L);
    }
    ll get(ll id, ll l, ll r, ll x)
    {
        if(l == r) return t[id](x);
        int m = (r + l) >> 1;
        if(x <= m) return min(t[id](x), get(id << 1, l, m, x));
        else return min(t[id](x), get(id << 1 | 1, m + 1, r, x));
    }
    void slv()
    {
        sort(a + 1, a + n + 1);
        fr(i, 1, n)  {
            sumtr[i] = sumtr[i - 1] + a[i].t*a[i].r;
            sumr[i] = sumr[i - 1] + a[i].r;
        }
        memset(f, 0x3f, sizeof(f));
        upd(1, 1, 1e6, line(0, 0));
        f[0] = 0;
        fr(i, 1, n) {
            f[i] = T + sumtr[i] - sumr[i]*a[i].t + get(1, 1, 1e6, a[i].t);
            upd(1, 1, 1e6, line(sumr[i], f[i] - sumtr[i]));
        }
        ll res = inf;
        fr(i, 0, n) mini(res, f[i] + sumtr[n] - sumtr[i]);
        cout << res;
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



