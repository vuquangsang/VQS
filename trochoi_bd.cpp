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

const int N = 505;
int n, q, a[N][N];
int xx, yy;
void input()
{
    int ma = 0;
    cin >> n >> q;
    fr(i, 1, n) fr(j, 1, n) {
        cin >> a[i][j];
        if(maxi(ma, a[i][j])) {
            xx = i;
            yy = j;
        }
    }
}
namespace sub1
{
    bool dd[N][N];
    struct eg
    {
        int x, y, px, py, w;
        bool operator <(eg const&a) const
        {
            return w < a.w;
        }
    };

    struct edge
    {
        int x, y, w;
    };
    bool check(int x, int y)
    {
        return (!dd[x][y] && x >= 1 && x <= n && y >= 1 && y <= n);
    }

    vector<edge> adj[N][N];
    void kruskal(int xx, int yy)
    {
        fr(i, 1, n) fr(j, 1, n) dd[i][j] = 0;
        priority_queue<eg> pq;
        pq.push({xx, yy, xx, yy, a[xx][yy]});
        while(!pq.empty()) {
            int x = pq.top().x;
            int y = pq.top().y;
            int px = pq.top().px;
            int py = pq.top().py;
            int w = pq.top().w;
            pq.pop();
            if(dd[x][y]) continue;
            adj[px][py].pb({x, y, w});
            adj[x][y].pb({px, py, w});
            dd[x][y] = 1;

            fr(i, 1, 4) {
                int u = dx[i] + x;
                int v = dy[i] + y;
                int w = a[u][v];
                if(check(u, v)) {
                    pq.push({u, v, x, y, w});
                }
            }
        }
    }

    node up[N][N][21];
    int h[N][N];
    bool memo[N][N];

    void view(int x, int y, int j)
    {
        cout << up[x][y][j].x << " " << up[x][y][j].y << el;
    }
    void DFS(int x, int y, int px, int py)
    {
        cout << px << " " << py << " " << x << " "<< y <<  el;
        up[x][y][0] = {px, py};
        view(2, 4, 0); cout << el;
        fr(j, 1, 21) up[x][y][j] = up[up[x][y][j - 1].x][up[x][y][j - 1].y][j - 1];
        for(edge i : adj[x][y]) {
            int u = i.x;
            int v = i.y;
            if(u == px && v == py || memo[u][v]) continue;
            memo[u][v] = 1;
            h[u][v] = h[x][y] + 1;
            DFS(u, v, x, y);
        }
    }

    node lca(int x, int y, int u, int v)
    {
        if(h[x][y] < h[u][v]) {
            swap(x, u);
            swap(y, v);
        }
        frd(j, 21, 0) {
            if(h[up[x][y][j].x][up[x][y][j].y] >= h[u][v]) {
                x = up[x][y][j].x;
                y = up[x][y][j].y;
            }
        }

        if(x == u && y == v) return {x, y};
        frd(j, 21, 0) {
            if(up[x][y][j].x != up[u][v][j].x && up[x][y][j].y != up[u][v][j].y) {
                x = up[x][y][j].x;
                y = up[x][y][j].y;
                u = up[u][v][j].x;
                v = up[u][v][j].y;
            }
        }
        return {up[x][y][0].x, up[x][y][0].y};
    }

    void slv()
    {
        kruskal(xx, yy);
//        for(eg i : adj[4][2]) {
//            cout << i.x << " " << i.y << el;
//        } return;
        DFS(xx, yy, xx, yy);
//        fr(i, 1, n) fr(j, 1, n) {
//            fr(x, 1, n) fr(y, 1, n) {
//                node sang = lca(i, j, x, y);
//                cout << sang.x << " " << sang.y << el;
//            }
//        }

        view(2, 4, 0); return;
        node sang = lca(1, 4, 3, 2);
        cout << sang.x << " " << sang.y << el;

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


