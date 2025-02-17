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

const int M = 1e6 + 2;
const int MAX = 5e5 + 2;
int n, t, m;
node a[MAX];
vector<int> g[M];
void input()
{
    cin >> n >> m >> t;
    int x, y;
    fr(i, 1, m) {
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    fr(i, 1, t) cin >> a[i].x >> a[i].y;
}
namespace sub1
{
    bool check() {return n <= 1e4 && t <= 1e4;}
    // dpt n*t
    int dp[MAX];
    void slv()
    {
        memset(dp, 0, sizeof dp);
        fr(i, 1, t) {
            int u = a[i].x;
            int v = a[i].y;
            int mx = dp[u];
            for(int v : g[u]) maxi(mx, dp[v]);
            maxi(dp[v], mx + 1);
        }
        cout << *max_element(alla(dp, n));
    }
}
namespace sub2
{
    bool check() {return 1;}
    int dp[MAX], dp2[MAX];
    vector<int> big[MAX];
    void slv()
    {
        int lim = 1000;
        fr(u, 1, n){
            if(g[u].size() > lim) continue;
            for(int v : g[u]) {
                if(g[v].size() > lim) big[u].pb(v);
            }
        }
        fr(i, 1, t) {
            int u = a[i].x;
            int v = a[i].y;
            int mx = max(dp[u], dp2[u]);
            if(g[u].size() < lim) {
                for(int x : g[u]) maxi(mx, dp[x]);
            }
            maxi(dp[v], mx + 1);
            for(int e : big[v]) maxi(dp2[e], dp[v]);
        }
        cout << *max_element(alla(dp, n));
    }
}

main()
{
    #define TASK "boat"
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
//        sub2::slv(); return 0;
        if(sub1::check()) return sub1::slv(), 0;
        if(sub2::check()) return sub2::slv(), 0;
    //    sub2::slv();
    }
}


