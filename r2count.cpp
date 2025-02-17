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
#define     frd(i,a,b) for(ll i = (a), _b = (b); i >= _b; i--)
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
template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}

const int MAX = 1e6 + 2;
ll n, m, a[MAX];
void input()
{
    cin >> n  >> m;
    fr(i, 1, n) cin >> a[i];
}
namespace sub1
{

    const int MAXM = 3e3 + 2;
    int cnt[MAX];
    void slv()
    {
        fr(i, 1, n) fr(j, 1, n) {
            ll value = a[i]*a[j]%m;
            cnt[value]++;
        }
        ll ans = 0;
        fr(x, 0, m - 1) {
            fr(i, 1, n) {
                ll val = x*a[i]%m;
                if(!val) ans+=cnt[x];
            }
        }
        cout << ans;
    }
}
namespace sub2
{

    int cnt[MAX];
    void slv()
    {
        fr(i, 1, n) a[i]%=m;
        fr(i, 1, n) cnt[a[i]]++;

        ll res = 0;
        fr(x, 0, m - 1)  fr(y, 0, m - 1) fr(z, 0, m - 1) {
            ll value = 1LL*x*y*z%m;
            if(!value) res+=1LL*cnt[x]*cnt[y]*cnt[z];
        }
        cout << res;

    }
}

namespace sub3
{
    long long cnt1[MAX], cnt2[MAX], cnt[MAX];
    void slv()
    {
        fr(i, 1, n) cnt[a[i]%m]++;
        fr(x, 0, m - 1) fr(y, 0, m - 1) {
            int p = 1LL*x*y%m;
            cnt1[p]+=cnt[x]*cnt[y];
        }
        ll res = 0;
        fr(x, 0, m - 1) fr(y, 0, m - 1) {
            ll value = 1LL*x*y%m;
            if(!value) res+=cnt1[x]*cnt[y];
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
        sub3::slv(); return 0;
//        sub2::slv(); return 0;
        if(n <= 2000) sub1::slv();
        else sub2::slv();
    //    sub2::slv();
    }
}


