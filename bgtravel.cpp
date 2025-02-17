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

const int N = 2e5 + 3;
int n, m, k;
vector<int> g[N];
void input()
{
    cin >> n >> m >> k;
    int x, y;
    fr(i, 1, m) {
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
}
namespace sub1
{

    int low[N], num[N], time = 0;
    stack<int> st;
    int cnt = 0;
    int tp[N], sl[N];
    vector<int> adj[N];


    void dfs(int u, int p) {
        low[u] = num[u] = ++time;
        st.push(u);

        int ok = 0;
        for(int v : g[u]) {
            if(v == p && !ok) {
                ok = 1;
                //
                continue;
            }
            if(num[v]) {
                low[u] = min(low[u], num[v]);
            }
            else {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
            }
        }

        if(low[u] == num[u]) {
            int nxt;
            cnt++;
            // cnt =  number of peaks after comp
            do {
                nxt = st.top();
                tp[nxt] = cnt;
                sl[cnt]++;
                st.pop();
            } while(nxt != u);
        }
    }

    int sz[N];
    bool dd[N];
    void pre_dfs(int u, int p)
    {
        sz[u] = 1;
        for(int v : adj[u]) if(v != p && !dd[v]) {
            pre_dfs(v, u);
            sz[u] += sz[v];
        }
    }

    int centroid(int u, int p, int n)
    {
        for(int v : adj[u]) if(v != p && !dd[v]) {
            if(sz[v] > n / 2) {
                return centroid(v, u, n);
            }
        }
        return u;
    }

    int bit[N], ma = 0;
    ll res = 0;
    void upd(int x, int v)
    {
        for(; x >= 1; x -= x & -x) bit[x] += v;
    }
    int get(int x)
    {
        int ans = 0;
        for(; x <= ma; x += x & -x) ans += bit[x];
        return ans;
    }

    void dfs_1(int u, int p, int h)
    {
        if(k - h <= ma) {
            res += 1ll*sl[u]*get(max(0, k - h) + 1);
        }
        for(int v : adj[u]) {
            if(v == p || dd[v]) continue;
            dfs_1(v, u, h + 1);
        }
    }

    void dfs_2(int u, int p, int h)
    {
        upd(h + 1, sl[u]);
        for(int v : adj[u]) {
            if(dd[v] || v == p) continue;
            dfs_2(v, u, h + 1);
        }
    }
    void calc(int u)
    {
        pre_dfs(u, 0);

        ma = sz[u] + 1;
        dd[u] = 1;
        upd(1, sl[u]);
        for(int v : adj[u]) {
            if(dd[v]) continue;
            dfs_1(v, u, 1);
            dfs_2(v, u, 1);
        }

        fr(i, 1, ma) bit[i] = 0;
        for(int v : adj[u]) {
            if(dd[v]) continue;
            calc(centroid(v, u, sz[v]));
        }
    }
    void slv()
    {
        dfs(1, 0);
        fr(u, 1, n) {
            for(int v : g[u]) {
                if(tp[u] < tp[v]) { // if 2 peaks are different
                    adj[tp[v]].pb(tp[u]);
                    adj[tp[u]].pb(tp[v]);
                }
            }
        }
        calc(centroid(tp[1], 0, sz[tp[1]]));
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


