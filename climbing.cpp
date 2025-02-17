#include <bits/stdc++.h>
using namespace std;

//#define   ll int
#define     lg(x) log2(x)
#define     alla(a,n) a+1,a+n+1
#define     el "\n"
#define     all(x) x.begin(),x.end()
#define     pb push_back
#define     ll long long
#define     fi first
#define     se second
#define     MASK(i) (1ll<<(i))
#define     c_bit(i) __builtin_popcountll(i)
#define     fr(i,a,b) for(ll i=a;i<=b;i++)
#define     frd(i,a,b) for(ll i=a;i>=b;i--)

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
ll lcm(ll a, ll b) {return a/__gcd(a, b)*b;}

ll n, m, c, a[MF];
void input()
{
    cin >> n >> m >> c;
    fr(i, 1, n) cin >> a[i];
}
namespace sub1
{
    ll pos[MF], t[MF], v[MF];
    void upd(ll id, ll l, ll r , ll i, ll val)
    {
        if(i > r | i < l) return ;
        if(l == r) {
            t[id] = val;
            v[id] = val;
            return ;
        }
        ll m = (r + l) >> 1;
        upd(id << 1, l, m, i, val);
        upd(id << 1 | 1, m + 1, r, i,  val);
        t[id] = max(t[id << 1] , t[id << 1 | 1]);
        v[id] = min(v[id << 1], v[id << 1 | 1]);
    }
    ll get(ll id, ll l, ll r, ll u, ll v)
    {
        if(r < u || v < l) return  0;
        if(u <= l && r <= v) return  t[id];
        ll m = (r + l) >> 1;
        return max(get(id << 1, l, m, u, v) , get(id << 1 | 1, m + 1, r, u, v));
    }
    ll get1(ll id, ll l, ll r, ll u, ll f)
    {
        if(r < u || f < l) return  0;
        if(u <= l && r <= f) return v[id];
        ll m = (r + l) >> 1;
        return  min(get1(id << 1, l, m, u, f) , get1(id << 1 | 1, m + 1, r, u, f));
    }
    void slv()
    {
        fr(i, 1, n - 1) pos[i] = abs(a[i] - a[i + 1]);
        fr(i, 1, n - 1) upd(1, 1, n - 1, i, pos[i]);
        if(m == 1){
            fr(i, 1, n) cout << i << el;
            return ;
        }
        bool vis = 0;
        fr(i, 1, n - m + 1) {
            ll value = get(1, 1, n - 1, i, i + m - 2) - get1(1, 1, n - 1, i, i + m - 2);

            if(value <= c) {
                cout << i << el;
                vis = 1;
            }
        }
        if(!vis) cout << "NONE";
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


