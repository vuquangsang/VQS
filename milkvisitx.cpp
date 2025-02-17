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
int n, color[MAX], q;
vector<int> g[MAX];
void input()
{
    cin >> n >> q;
    fr(i, 1, n) cin >> color[i];
    int x, y;
    fr(i, 1, n -1) {
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
}
namespace sub1
{

    int h[MAX], sz[MAX], chain[MAX], chainID[MAX], time = 0, mtc = 1, pos[MAX], euler[MAX];
    int up[MAX][18];
    int cnt[18][MAX];
    unordered_map<int, int> m[2002];
    void DFS(int u, int p)
    {
        up[u][0] = p;
        fr(j, 1, lg(n)) up[u][j] = up[up[u][j - 1]][j - 1];
        sz[u] = 1;
        for(int v : g[u]) if(v != p ) {
            h[v] = h[u] + 1;
            DFS(v, u);
            sz[u]+=sz[v];
        }
    }
    int lca(int u, int v)
    {
        if(h[u] < h[v]) swap(u, v);
        frd(j, lg(n), 0) if(h[up[u][j]] >= h[v]) u = up[u][j];
        if(u == v) return  u;
        frd(j, lg(n), 0) {
            if(up[u][j] != up[v][j]) u = up[u][j], v = up[v][j];
        }
        return up[u][0];
    }
    void HLD(int u, int p)
    {
        if(!chain[mtc]) {
            chain[mtc] = u;
        }
        m[u] = m[p];
        m[u][color[u]]++;
        cnt[mtc][color[u]]++;
        chainID[u] = mtc;
        euler[++time] = u;
        pos[u] = time;
        int ma = 0;
        for(int v : g[u]) if(v != p) {
            if(!ma || sz[v] > sz[ma]) ma = v;
        }
        if(ma) HLD(ma, u);
        for(int v : g[u]) if(v != p && v != ma) {
            mtc++;
            HLD(v, u);

        }
    }
    void slv()
    {
        DFS(1, 1);
        HLD(1, 1);
//        fr(i, 1, n) cout << chainID[i] << " " ; cout << el;
//        fr(i, 1, mtc) cout << chain[i] << " " ; cout << el;
        int x, y, c;
        while(q--) {
            cin >> x >> y >> c;
            int par = lca(x, y);
            bool check = 0;
            while(chainID[x] != chainID[par] ) {
                if(m[x][c] - m[up[chain[chainID[x]]][0]][c] > 0) check = 1;
                x = up[chain[chainID[x]]][0];
            }
            while(chainID[y] != chainID[par]) {
               if(m[y][c] - m[up[chain[chainID[y]]][0]][c] > 0) check = 1;
                y = up[chain[chainID[y]]][0];
            }
            if(color[x] == c) check = 1;
            if(color[y] == c) check = 1;
            if(h[x] < h[y]) swap(x, y);
            ll value = m[x][c] - m[y][c];
            if(value) check = 1;
            cout << x << " " << y << el;
            cout << check;
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
    #define TASK ""
 //   #define TASK "task"
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


