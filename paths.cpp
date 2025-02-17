/* Vu Quang Sang from Le Khiet High School for Gifted */
#include <bits/stdc++.h>
using namespace std;

//#define   ll int
#define     lg(x) __lg(x)
#define     alla(a,n) a+1,a+n+1
#define     el "\n"
#define     all(x) x.begin(),x.end()
#define     pb push_back
#define     ll int
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
const long long inf = 1e9+7;
const ll N = 1005;
const ll base = 311;
const ll F = 1e5 + 2;
const ll BLOCK = 320;
const int dx[5] = {0, -1, 1, 0 , 0};
const int dy[5] = {0, 0, 0, -1, 1};
const short LO = 17;

struct node{ll x,y,w;};
struct bg{ll id,ts;};
struct pll{ll fi,se, id;};
struct init{ll in,va;bool operator <(init const&a)const{return this->va>a.va;}};
ll mod(ll a, ll b) {return ((a%MN)*(b%MN))%MN;}
template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}

ll n, m;
const int MAX = 505;
vector<pll> g[MAX];
ll dist[MAX][MAX];
node Q[MAX*MAX];
void input()
{
    cin >> n >> m;
    ll x, y, w;
    memset(dist, 0x3, sizeof dist);
    fr(i, 1, n) dist[i][i] = 0;
    fr(i, 1, m) {
        cin >> x >> y >> w;
        Q[i] = {x, y, w};
        mini(dist[x][y], w);
        mini(dist[y][x], w);
        g[x].pb({y, w, i});
        g[y].pb({x, w, i});
    }

}
namespace sub1
{
    struct eg
    {
        ll u, w;
        bool operator<(eg const&a) const
        {
            return w > a.w;
        }
    };
    bool dd[MAX];
    ll f[MAX][MAX], edge[MAX][MAX], way[MAX][MAX];

    ll par[MAX][MAX];

    bool check(ll u, ll v, ll x, ll y, ll w)
    {
        if(dist[u][v] == dist[u][x] + w + dist[y][v] ) return 1;
        swap(x , y);
        if(dist[u][v] == dist[u][x] + w + dist[y][v] ) return 1;
        return 0;
//         or 1 edge true or 2 edge false
//         a + b > c
//         with any 3 node , dist[s][t] <=  dist[s][v] + dist[v][t]
//         with 1 edge(u, v, w) d[s][v] <= d[s][u] + w
//         -> dist[s][v] <= dist[s][u] + w + dist[v][t]
//        '=' happen when { dist[s][t] = dist[s][v] + dist[v][t];
//                        { dist[s][v] = dist[s][u] + w;
    }
    ll cnt[MAX][MAX]; // number edge(u, v, w) satisfied dist[s][u] = dist[s][u] + w
    ll res[MAX][MAX]; // res[s][t]  = sigma(cnt[s][v] , dist[s][t] = dist[s][u] + dist[v][t]
    ll p[MAX][MAX];
    void dij(ll s, ll f[])
    {
        fr(i, 1, n) f[i] = inf, dd[i] = 0;
        f[s] = 0;
        edge[s][s] = 0;
        way[s][s] = 1;
        priority_queue<eg> q;
        q.push({s, 0});
        while(!q.empty()) {
            ll u = q.top().u; q.pop();
            if(dd[u]) continue;
            dd[u] = 1;
            for(auto t : g[u]) {
                ll v = t.fi;
                ll w = t.se;
                ll id = t.id;
                if(mini(f[v], f[u] + w)) {
                    way[s][v] = way[s][u];
                    par[s][v] = id;
                    p[s][v] = u;
                    q.push({v, f[v]});
                }
                else if(f[v] == f[u] + w) {
                    way[s][v]+=way[s][u];
                }
            }
        }
    }
    void countPath(ll x, ll y)
    {
        ll cur = y;
        while(cur != x) {
            ll id = par[x][cur];
            ll u = Q[id].x;
            ll v = Q[id].y;
            ll w = Q[id].w;
            if(check(x, y, u, v, w)) res[x][y]++;
            cur = p[x][cur];
        }
    }
    void slv()
    {
        fr(i, 1, n) dij(i, dist[i]);
        fr(x, 1, n) {
            fr(y, x + 1, n) {
                fr(i, 1, m) {
                    ll u = Q[i].x;
                    ll v = Q[i].y;
                    ll w = Q[i].w;
                    bool ok = 0;
                    if(check(x, y, u, v, w)) ok = 1;
                    res[x][y]+=ok;
                }
            }
        }

       // fr(i, 1, n) fr(j, i + 1, n) countPath(i, j);
        fr(i, 1, n) {
            fr(j, i + 1, n) {
                cout << res[i][j] << " ";
            } cout << el;
        }
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
    #define TASK "paths"
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    if( fopen( TASK".INP", "r") ){
        freopen( TASK".INP", "r", stdin);
        freopen( TASK".OUT", "w", stdout);
    }
    bool qs = 0;
    ll mtt = 1;
    ll subtask;
    cin >> subtask;
    if(qs) cin >> mtt;
    fr(i, 1, mtt){
        input();
        sub1::slv();
    //    sub2::slv();
    }
}

