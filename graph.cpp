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
const long long inf = 1e16+7;
const ll N = 1005;
const ll base = 311;
const ll F = 1e5 + 2;
const ll BLOCK = 320;
const int dx[5] = {0, -1, 1, 0 , 0};
const int dy[5] = {0, 0, 0, -1, 1};
const short LO = 17;

struct node{ll x,y;};
struct pll{ll fi,se;};
ll mod(ll a, ll b) {return ((a%MN)*(b%MN))%MN;}
template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}
struct eg
 {
     ll x, y, w;
 };

const int MAX = 2e5 + 10;
ll n, m;
eg Q[MAX];
vector<pll> g[MAX];
void input()
{
    cin >> n >> m;
    ll x, y, w;
    fr(i, 1, n) g[i].clear();
    fr(i, 1, m) {
        cin >> x >> y >> w;
        Q[i] = {x, y, w};
        g[x].pb({y, w});
        g[y].pb({x, w});
    }
}
namespace sub1
{
    struct eg
    {
        ll u, w;
        bool operator <(eg const&a) const {
            return this-> w > a.w;
        }
    };
    ll f[2][MAX];
    bool dd[MAX];
    void DIJ(ll s, ll f[])
    {
        fr(i, 1, n) f[i] = inf, dd[i] = 0;
        priority_queue<eg> q;
        f[s] = 0;
        q.push({s, 0});
        while(!q.empty()) {
            ll u = q.top().u;
            q.pop();
            if(dd[u]) continue;
            dd[u] = 1;
            for(auto t : g[u]) {
                ll v = t.fi;
                ll w = t.se;
                if(f[v] > f[u] + w && !dd[v]) {
                    f[v] = f[u] + w;
                    q.push({v, f[v]});
                }
            }
        }
    }
    void slv()
    {
        DIJ(1, f[0]);
        DIJ(n, f[1]);
        ll res = inf;
        fr(i, 1, m) {
            ll u = Q[i].x; ll v = Q[i].y;
            mini(res, Q[i].w*(f[0][u] + Q[i].w + f[1][v]));
            mini(res, Q[i].w*(f[0][v] + Q[i].w + f[1][u]));
        }
        cout << res << " ";
    }
}
main()
{
    #define TASK "graph"
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    if( fopen( TASK".INP", "r") ){
        freopen( TASK".INP", "r", stdin);
        freopen( TASK".OUT", "w", stdout);
    }
    bool qs = 1;
    ll subtask;
    ll mtt = 1;
    if(qs) cin >> subtask >> mtt;
    fr(i, 1, mtt){
        input();
        sub1::slv();
    }
}



