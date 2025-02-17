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
int n, A, B;
vector<pll> g[N];
struct eg
{
    int x, y, w;
};
eg E[N];
void input()
{
    cin >> n >> A >> B;
    fr(i, 1, n - 1) {
        int x, y, w;
        cin >> x >> y >> w;
        g[x].pb({y, w});
        g[y].pb({x, w});
        E[i] = {x, y, w};
    }
}
namespace sub1
{
    bool check() {return n <= 16;}

    const int M = 16;
    const int MAX = 5e5 + 7;
    ll dp[MAX][M];

    int cost[M][M];
    void slv()
    {
        memset(cost, 0x3f3f, sizeof cost);
        fr(i, 1, n - 1) {
            int x = E[i].x, y = E[i].y, w = E[i].w;
            cost[x][y] = cost[y][x] = w;
        }

        memset(dp, 0x3f3f3f, sizeof dp);
        dp[1][1] = 0;
        REP(msk, 1, (1 << n)) {
            for(int u = 1; u <= n; u++) if(dp[msk][u] < inf) {
                for(int v = 1; v <= n; v++) if(!(msk&(1 << (v - 1)))) {
                    mini(dp[msk | (1 << (v - 1))][v], dp[msk][u] + min(1ll*cost[u][v]*A, 1ll*B));
                }
            }
        }

        ll res = inf;
        fr(v, 2, n) {
            mini(res, dp[(1 << n) - 1][v] + min(1ll*cost[v][1]*A, 1ll*B));
        }
        cout << res;
    }
}
namespace sub2
{
    bool check() {
        fr(i, 1, n - 1) {
            int x = E[i].x;
            int y = E[i].y;
            bool ok = 0;
            if(x == i && y == i + 1) ok = 1;
            if(x == i + 1 && y == i) ok = 1;
            if(!ok) return 0;
        }
        return 1;
    }
    void slv()
    {
        ll res = 0;
        fr(i, 1, n - 1) {
            int w = E[i].w;
            res += min(w*A, B);
        }
        res += B;
        cout << res;
    }
}

namespace sub3
{

    ll dp[N][3];
    void DFS(int u, int p) {
        int child = 0;
        ll total = 0;
        long long bestans[2] = {inf, inf};
        for(auto e : g[u]) {
            int v = e.fi, w = e.se;
            if(v == p) continue;
            child++;
            DFS(v, u);
            total += min(dp[v][1], dp[v][2]) + B;
            ll value = dp[v][1] + 1ll*w*A - min(dp[v][1], dp[v][2]) - B;
            if(value < bestans[0]) {
                bestans[1] = bestans[0];
                bestans[0] = value;
            }
            else mini(bestans[1], value);
        }
        dp[u][1] = min(total, total + bestans[0]);
        if(child > 1) {
            dp[u][2] = total + bestans[0] + bestans[1];
        }
    }
    void slv()
    {
        memset(dp, 0x3f3f3f, sizeof dp);
        DFS(1, 0);

        cout << min(dp[1][1], dp[1][2]) + B;
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
        if(n == 2) {
            cout << 2*min(E[1].w*A, B);
            return 0;
        }
        if(sub1::check()) sub1::slv();
        else if(sub2::check()) sub2::slv();
        else sub3::slv();
    }
}


