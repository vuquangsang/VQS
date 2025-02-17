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

const ll sm = 1e9+7;
const long long inf = 1e18+7;
const ll base = 311;
const ll BLOCK = 320;
const int dx[5] = {0, -1, 1, 0 , 0};
const int dy[5] = {0, 0, 0, -1, 1};

struct node{ll x,y;};
struct pll{ll fi,se;};
template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}

const int N = 2e5 + 2;
ll n, a[N], k;
void input()
{
    cin >> n >> k; fr(i, 1, n) cin >> a[i];

}
namespace sub1
{

    ll f[N];
    map<ll,ll> mp;
    void slv()
    {
        if(k == 0) {
            cout << 0;
            return;
        }
        mp[a[1]]++;
        fr(i, 2, n) {
            if(a[i]%k == 0 && k) f[i]+=mp[a[i]/k];
            mp[a[i]]++;
        }
        mp.clear();
        mp[a[2]]+=f[2];
        ll res = 0;
        fr(i, 3, n) {
            if(a[i]%k == 0 && k) res = res + mp[a[i]/k];
            mp[a[i]]+=f[i];
        }
        cout << res;
    }
}
namespace sub2
{
    void slv()
    {
        ll res = 0;
        fr(i, 1, n) {
            fr(j, i + 1, n) {
                fr(t, j + 1, n) {
                    if(a[j] == a[i]*k && a[t] == a[j]*k) res++;
                }
            }
        }
        cout << res;
    }
}

main()
{
    #define TASK "BL4"
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
