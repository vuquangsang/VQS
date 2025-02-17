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


void input()
{

}
namespace sub1
{


    void slv()
    {

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


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N  1000000
ll h[N], a[N], f[N];
ll t[N];
void upd(ll id, ll l, ll r, ll i, ll val)
{
    if(i > r || i < l) return ;
    if(l == r) {
        t[id] = max(t[id], val);
        return;
    }
    int m = (r + l) >> 1;
    upd(id << 1, l, m, i, val);
    upd(id << 1 | 1, m + 1, r, i, val);
    t[id] = max(t[id << 1], t[id << 1 | 1]);

}
ll get(ll id, ll l, ll r, ll u, ll v)
{
    if(r < u || v < l) return 0;
    if(u <= l && r <= v) return t[id];
    int m = (r + l) >> 1;
    return max(get(id << 1, l, m, u, v) , get(id << 1 | 1, m + 1, r, u, v));
}
main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> h[i];
    for(int i = 1; i <= n; i++) cin >> a[i];
    f[1] = a[1];
    upd(1, 1, n, h[1], a[1]);
    for(int i = 2; i <= n; i++){
        f[i] = a[i];
        f[i] = max(f[i], get(1, 1, n, 1, h[i] - 1) + a[i]);
        upd(1, 1, n, h[i], f[i]);
    }
    cout << *max_element(f + 1, f + n + 1);
}
