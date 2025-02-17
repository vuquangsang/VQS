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

struct node{ll x,y,w;};
struct pll{ll fi,se;};
ll mod(ll a, ll b) {return ((a%MN)*(b%MN))%MN;}
template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}

const int MAX = 2e5 + 2;
int n, m, S, T, U, V;
vector<pll> g[MAX];
//node Q[MAX];
void input()
{
    cin >> n >> m;
    cin >> S >> T;
    cin >> U >> V;
    int x, y, w;
    fr(i, 1, m) {
        cin >> x >> y >> w;
        g[x].pb({y, w});
        g[y].pb({x, w});
//        Q[i] = {x, y, w};
    }
}
namespace sub1
{

    struct eg
    {
        ll u, w;
        bool operator <(eg const&a) const
        {
            return w > a.w;
        }
    };
    bool dd[MAX];
    ll dist[3][MAX];
    void dij(int s, ll dist[])
    {
        memset(dd, 0, sizeof dd);
        priority_queue<eg> pq;
        pq.push({s, 0});
        dist[s] = 0;
        while(!pq.empty()) {
            int u = pq.top().u; pq.pop();
            if(dd[u]) continue;
            dd[u] = 1;
            for(pll x : g[u]) {
                int v = x.fi, w = x.se;
                if(mini(dist[v], dist[u] + w)) {
                    pq.push({v, dist[v]});
                }
            }
        }
    }
    ll res = inf;
    ll lab[MAX][2];
    bool vis[MAX];
    void DFS(int u)
    {
        // dist[1] is U
        // dist[2] is V
        // dist[0] is S

        // lab[u][0] is distance U -> u
        // lab[u][1] is distance V -> u
        lab[u][0] = dist[1][u];
        lab[u][1] = dist[2][u];
        vis[u] = 1;

        for(pll x : g[u]) {
            int v = x.fi, w = x.se;
            if((dist[0][v] + w) != dist[0][u]) continue;
            // if distance S -> v + w == distance S - > u
            if(!vis[v]) DFS(v);

            mini(lab[u][0], lab[v][0]);
            mini(lab[u][1], lab[v][1]);
        }

        mini(res, lab[u][0] + dist[2][u]);
        mini(res, lab[u][1] + dist[1][u]);
    }
    void slv()
    {
        memset(dist, 0x3f3f3f, sizeof dist);
        dij(U, dist[1]);
        dij(V, dist[2]);
        dij(S, dist[0]);

        res = dist[1][V];
        DFS(T);

        cout << res;
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
        sub1::slv();
    //    sub2::slv();
    }
}


