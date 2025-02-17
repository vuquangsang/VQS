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

ll n, k, a[MF];
void input()
{
    cin >> n >> k; fr(i, 1, n) cin >> a[i];
}
namespace sub1
{
    ll p[MF], s[MF], rmax[MF][21], rmin[MF][21];
    void build()
    {
        fr(i, 0, n - 1) rmax[i][0] = rmin[i][0] = a[i + 1];
        for(int j = 1; (1 << j) < n; j++) {
            for(int i = 0; (i + (1 << j) - 1) < n; i++) {
                rmax[i][j] = max(rmax[i][j - 1], rmax[i + (1 << (j - 1))][j - 1]);
                rmin[i][j] = min(rmin[i][j - 1], rmin[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    ll getmax(ll l, ll r)
    {
        l--;
        r--;
        ll j = lg(r - l + 1);
        return max(rmax[l][j], rmax[r - (1 << j) + 1][j]);
    }
    ll getmin(ll l, ll r)
    {
        l--; r--;
        ll j = lg(r - l + 1) ;
        return min(rmin[l][j], rmin[r - (1 << j) + 1][j]);
    }


    void slv()
    {
        build();
     //   cout << getmax(1, 3); return;
        p[1] = 1;
        fr(i, 2, n) {
            fr(j, 1, i) {
                ll value = getmax(j, i) - getmin(j, i);
                if(value <= k) {
                    p[i] = i - j + 1;
                    break;
                }
            }
        }
        s[n] = 1;
        frd(i, n - 1, 1) {
            frd(j, n, i) {
                ll value = getmax(i, j) - getmin(i, j);
                if(value <= k) {
                    s[i] = j - i  + 1;
                    break;
                }
            }
        }
  //      fr(i, 1, n) cout << p[i] << " ";
  //      cout << el; fr(i, 1, n) cout << s[i] << " " ; return ;
        fr(i, 2, n) p[i] = max(p[i], p[i - 1]);
        frd(i, n - 1, 1) s[i] = max(s[i + 1], s[i]);
        ll res = 0;
        fr(i, 1, n - 1) maxi(res, p[i] + s[i + 1]);
        cout << res;
    }
}
namespace sub2
{
    deque<ll> ma, mi;
    ll f[MF];
    void add(ll x)
    {
        while(!ma.empty() && x > ma.back()) ma.pop_back();
        ma.pb(x);
        while(!mi.empty() && x < mi.back()) mi.pop_back();
        mi.pb(x);
    }
    void del(ll x)
    {
        if(x == ma.front()) ma.pop_front();
        if(x == mi.front()) mi.pop_front();
    }
    void slv()
    {
        ll j = 1;
        fr(i, 1, n) {
            add(a[i]);
            while(ma.front() - mi.front() > k) del(a[j++]);
            f[i] = i - j + 1;
        }
    //    fr(i, 1, n) cout << f[i] << " "; return ;
        ll res = 0;
        fr(i, 1, n) {
            maxi(res, f[i - f[i]] + f[i]);
            maxi(f[i], f[i - 1]);
        }
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


