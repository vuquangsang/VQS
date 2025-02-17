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
const long long inf = 1e18+7;
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

struct edge
{
    int x, y, w;
};
ll subtask;
const int MAX = 505;
const int MAXE = 125005;

edge Q[MAXE];
int n, m, a[MAX], pos[MAX];
bool check = 1;
vector<pll> g[MAXE];
void input()
{
    cin >> n >> m;
    fr(i, 1, n) cin >> a[i];
    fr(i, 1, m) cin >> Q[i].x >> Q[i].y >> Q[i].w;
}
namespace sub1
{
    set<ll> st;
    ll dist[MAX][MAX], maxu[MAX];
    vector<pll> g[MAX];
    ll f[MAX];
    ll goc(ll x)
    {
        while(f[x] > 0) {
            x = f[x];
        }
        return x;
    }
    void hn(ll r1, ll r2)
    {
        ll tmp = f[r1] + f[r2];
        if(f[r1] < f[r2]) {
            f[r1] = tmp;
            f[r2] = r1;
        }
        else{
            f[r2] = tmp;
            f[r1] = r2;
        }

    }
    void DFS(ll u, ll p)
    {
        for(auto t : g[u]) {
            ll v = t.fi;
            ll w = t.se;
            if(v == p) continue;
            maxu[v] = max(maxu[u], w);
            DFS(v, u);
        }
    }
    void cal(ll lim)
    {
        fr(i, 1, n) g[i].clear();
        fr(i, 1, n) f[i] =  -1;
        ll d = 0;
        fr(i, 1, m) {
            ll x = Q[i].x;
            ll y = Q[i].y;
            ll w = Q[i].w;
            if(a[x] <= lim && a[y] <= lim) {
                ll r1 = goc(x), r2 = goc(y);
                if(r1 != r2) {
                    hn(r1, r2);
                    d++;
                    g[x].pb({y, w});
                    g[y].pb({x, w});
                    if(d == n - 1) break;
                }
            }
        }
        fr(u, 1, n) {
            memset(maxu, -1, sizeof maxu);
            maxu[u] = 0;
            DFS(u, 0);
            fr(v, 1, n) {
                if(maxu[v] >= 0) mini(dist[u][v], maxu[v]*lim);
            }
        }
    }
    void slv()
    {
        fr(i, 1,  n) st.insert(a[i]);
        sort(Q + 1, Q + m + 1, [](edge a, edge b){return a.w < b.w;});
        memset(dist, 0x3f, sizeof dist);
        for(auto x : st) cal(x);
        fr(i, 1, n) {
            ll res = 0;
            fr(j, 1, n) res+=dist[i][j];
            cout << res << " ";
        }
    }
}
main()
{
    #define TASK "mmgraph"
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    if( fopen( TASK".INP", "r") ){
        freopen( TASK".INP", "r", stdin);
        freopen( TASK".OUT", "w", stdout);
    }
    bool qs = 0;
    ll mtt = 1;
    cin >> subtask;
    if(qs) cin >> mtt;
    fr(i, 1, mtt){
        input();
        sub1::slv();
    }
}



