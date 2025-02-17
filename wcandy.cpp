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

int n, m;
void input()
{
    cin >> n >> m;
}
namespace sub1
{
    const int MAX = 1e6 + 2;
    map<ll,ll> mp;
    pll pre[MAX];
    void slv()
    {
        ll l, r;
        fr(i, 1, m) {
            cin >> l >> r;
            if(l <= r)
            {
                mp[l]++;
                mp[r + 1]--;
            }
            else {
                swap(l, r);
                mp[1]++;
                mp[l + 1]--;
                mp[r]++;
                mp[n + 1]--;
            }
        }
        ll d = 0;
        for(auto x : mp) {
            pre[++d] = {x.fi, x.se};
        }
        fr(i, 2, d) pre[i].se = pre[i - 1].se + pre[i].se;

        ll maxl = 0, maxr = 0, ans = 0, res = 0;
        fr(i, 1, d - 1) {
            if(pre[i].se > ans) {
                ans = pre[i].se;
                if(pre[i + 1].se <= ans) res = pre[i + 1].fi - pre[i].fi;
            }
            else if(pre[i].se == ans) {
                res = res + pre[i + 1].fi - pre[i].fi;
            }
        }
//        fr(i, 1, d) cout << pre[i].fi << " " << pre[i].se << el;
        cout << ans << " " << res;
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


