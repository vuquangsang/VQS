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
const ll N = 1505;
const ll base = 311;
const ll F = 1e5 + 2;
const ll BLOCK = 320;
const int dx[5] = {0, -1, 1, 0 , 0};
const int dy[5] = {0, 0, 0, -1, 1};
const short LO = 17;

struct node{ll x,y;};
struct bg{ll id,ts;};
struct pll{ll fi,se;};
struct init{ll in,va;bool operator <(init const&a)const{return this->va>a.va;}};
ll mod(ll a, ll b) {return ((a%MN)*(b%MN))%MN;}
template<class X, class Y>
    bool mini(X &x, const Y &y)  {
        if(x > y) {
            x = y;
            return 1;
        }
        else return 0;
    }
template<class X, class Y>
    bool maxi(X &x, const Y &y)
    {
        if(x < y) {
            x = y;
            return 1;
        }
        else return 0;
    }
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}

int n, C, R, a[N][N];
void input()
{
    cin >> n >> R >> C;
    fr(i, 1, n) fr(j, 1, n) cin >> a[i][j];
}
namespace sub1
{
    int f[N][N], res = 1;
    bool dd[N][N];
    bool check(int u, int v, int x, int y)
    {
        if(u && v && a[u][v] > a[x][y] && abs(u - x) > 1) return 1;
        return 0;
    }
    bool check1(int u, int v, int x, int y)
    {
        if(u && v && a[u][v] > a[x][y] && abs(v - y) > 1) return 1;
        return 0;
    }
    void BFS(int r, int c)
    {
        queue<node> q;
        fr(i, 1, n) fr(j, 1, n) f[i][j] = 0, dd[i][j] = 0;
        f[r][c] = 1;
        q.push({r, c});
        while(!q.empty()) {
            int x = q.front().x;
            int y = q.front().y; q.pop();
//           if(dd[x][y]) continue ;
  //          dd[x][y] = 1;
            for(int u = 1; u <= n; u++) {
                int v = y - 1;
                if(check(u, v, x, y)) {
                    if(maxi(f[u][v], f[x][y] + 1)) q.push({u, v});
                }
                v = y + 1;
                if(check(u, v, x, y)) {
                    if(maxi(f[u][v], f[x][y] + 1)) q.push({u, v});
                }
            }
            for(int v = 1; v <= n; v++) {
                int u = x - 1;
                if(check1(u, v, x, y)) {
                    if(maxi(f[u][v], f[x][y] + 1)) q.push({u, v});
                }
                u = x + 1;
                if(check1(u, v, x, y)) {
                    if(maxi(f[u][v], f[x][y] + 1)) q.push({u, v});
                }
            }
        }
    }
    void cal(bool c)
    {
        fr(i, 1, n) {
            fr(j, 1, n) {
                maxi(res, f[i][j]);
                if(c) cout << f[i][j] << " ";
            } if(c) cout << el;
        }
    }
    void slv()
    {
        BFS(R, C);
        cal(0);
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



