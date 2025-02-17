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

const int MAX = 3e5 + 2;
ll n;
vector<pll> g[MAX];
void input()
{
    cin >> n;
    ll x, y, w;
    fr(i, 2, n) {
        cin>> x >> y >> w;
        g[x].pb({y, w});
        g[y].pb({x, w});
    }
}
namespace sub2
{
    const int MAXN = 3e5 + 10;
    struct eg
    {
        ll x, y, z;
    };
    eg f[MAX];
    void DFS(ll u, ll p)
    {
        for(pll t : g[u]) {
            ll v = t.fi;
            ll w = t.se;
            if(v == p) continue;
            DFS(v, u);
            if(f[v].x + w > f[u].x) {
                f[u].z = f[u].y;
                f[u].y = f[u].x;
                f[u].x = f[v].x + w;
            }
            else if(f[v].x + w > f[u].y) {
                f[u].z = f[u].y;
                f[u].y = f[v].x + w;
            }
            else if(f[v].y + w > f[u].y) {
                f[u].z = f[u].y;
                f[u].y = f[v].y + w;
            }
            else if(maxi(f[u].z, f[v].x + w));
        }
    }
    void slv()
    {
        ll res = 0;
        DFS(1, 0);
        fr(i, 1, n) {
            if(g[i].size() >= 3) {
                ll value = max({f[i].x*(f[i].y + f[i].z), f[i].y*(f[i].x + f[i].z), f[i].z*(f[i].x + f[i].y)});
                maxi(res, value);
            }
        }
        cout << res;
    }
}

main()
{
    #define TASK "maze"
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


