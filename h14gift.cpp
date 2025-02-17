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
template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}

const int MAX = 1e5 + 2;
int n, m, a[MAX];
void input()
{
    cin >> n >> m; fr(i, 1, n) cin >> a[i];
}
namespace sub1
{

    map<ll,ll> mp;
    int val[MAX];
    int cnt[MAX];
    void slv()
    {
        fr(i, 1, n) mp[a[i]]++;
        ll res = 0;
        int d = 0;
        for(auto x : mp) {
            val[++d] = x.fi;
            cnt[d] = x.se;
        }
//        fr(i, 1, n) cout << val[i] << " "; cout << el;
//        fr(i, 1, n) cout << cnt[i] << " "; cout << el;
        fr(i, 2, d) cnt[i]+=cnt[i - 1];
        fr(i, 1, d) {
            int id = 0;
            if(m >= val[i]) id = lower_bound(val + 1, val + i, m - val[i]) - val - 1;
            if(id <= n && val[id] <= m - val[i]) res+=cnt[id];
        }

        res*=2;
        fr(i, 1, d) {
            ll val = cnt[i] - cnt[i - 1];
            if(val >= 2 && val*2 <= m) {
                res+=(val)*(val + 1)/2;
            }
        }
        cout << res;
    }
}
namespace sub2
{
    void slv()
    {
        ll res = 0;
        fr(i, 1, n) fr(j, i + 1, n) {
            if(a[i] + a[j] <= m) res++;
        }
        cout << res*2;
    }
}

main()
{
    #define TASK "task"
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


