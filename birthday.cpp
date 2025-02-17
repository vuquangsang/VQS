/* Vu Quang Sang from Le Khiet High School for Gifted */
#include <bits/stdc++.h>
using namespace std;

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
const ll BLOCK = 320;
const int dx[5] = {0, -1, 1, 0 , 0};
const int dy[5] = {0, 0, 0, -1, 1};

struct node{ll x,y;};
struct pll{ll fi,se;};
ll mod(ll a, ll b) {return ((a%MN)*(b%MN))%MN;}
template <class T> bool maxi(T &x, T y) { if(x <= y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}

const int MAX = 1e2 + 2;
int n;
pll a[MAX];
void input()
{
    cin >> n;
    fr(i, 1, n) cin >> a[i].fi;
    fr(i, 1, n) cin >> a[i].se;
}
namespace sub1
{
    int res = 0, value;
    bool check(int k)
    {
        int tmp = 0, ans = 0;
        fr(i, 1, k) tmp+=a[i].se - a[i].fi;
        fr(i, k + 1, n) ans+=a[i].fi;
        return (tmp >= ans);
    }
    int bs()
    {
        ll l = 1, r = n, m;
        while(r - l > 1) {
            m = (r + l) >> 1;
            if(check(m)) r = m;
            else  l = m;
        }
        if(check(l)) return l;
        return r;
    }
    void cal()
    {
        res = 0;
        fr(i, value + 1, n) res+=a[i].fi;
    }
    bool cmp(pll a, pll b)
    {
        if(a.se - a.fi != b.se - b.fi) return a.se - a.fi > b.se - b.fi;
        return a.fi > b.fi;
    }
    void slv()
    {
        sort(alla(a, n), cmp);
        value = bs();
        cal();
        cout << value << " " << res;
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
