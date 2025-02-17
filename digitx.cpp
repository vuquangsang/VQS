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

ll f[MF], g[MF], q;
void input()
{
    cin >> q;
}
namespace sub1
{

    ll cnt[MF][11];
    ll cal(ll i)
    {
        ll res = 1;
        while(i > 0){
            ll tmp = i%10;
            if(tmp) res*=tmp;
            i/=10;
        }
        return res;
    }
    void slv()
    {
        ll l, r, k;
        fr(i, 1, 1e6) {
            f[i] = cal(i);
        }
        fr(i, 1, 1e6) {
            if(i < 10) g[i] = i;
            else {
                g[i] = g[f[i]];
            }
        }
        fr(i, 1, 1e6) {
            fr(j, 1, 9) {
                cnt[i][j] = cnt[i - 1][j];
                if(j == g[i]) cnt[i][j]++;
            }
        }
        while(q--) {
            cin >> l >> r >> k;
            cout << cnt[r][k] - cnt[l - 1][k] << el;
        }
    }
}
namespace sub2
{
    ll g[MF];
    ll cal(ll i)
    {
        ll res = 1;
        while(i > 0) {
            ll tmp = i%10;
            if(tmp) res*=tmp;
            i/=10;
        }
        return res;
    }
    void slv()
    {
        fr(i, 1, 9) g[i] = i;
        fr(i, 10, 1e6) g[i] = g[cal(i)];
        ll l, r, k;
        while(q--) {
            ll ans = 0;
            cin >> l >> r >> k;
            fr(i, l, r) {
                if(g[i] == k) {
                    ans++;
                }
            }
            cout << ans << el;
        }
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


