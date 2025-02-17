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

struct eg
{
    ll x, y, w;
};
#define int long long
const int MAX = 1e6 + 2;
eg Q[MAX];
int n, m;
const int N = 1e6 + 2;
vector<int> g[N];
void input()
{
    cin >> n >> m;
    fr(i, 1, m){
        int x, y, w;
        cin >> x >> y >> w;
        Q[i] = {x, y, w};
    }
}
namespace sub1
{

    int f[MAX];
    int goc(int x)
    {
        while(f[x] > 0) x = f[x];
        return x;
    }
    void hn(int r1, int r2)
    {
        int tmp = f[r1] + f[r2];
        if(f[r1] > f[r2]) swap(r1, r2);
        f[r1] = tmp;
        f[r2] = r1;
    }
    void slv()
    {
        sort(Q + 1, Q + m + 1, [](eg a, eg b){return a.w < b.w;});
        fr(i, 1, n) f[i] = -1;
        int d = 0, res = 0;
        fr(i, 1, m) {
            int r1 = goc(Q[i].x);
            int r2 = goc(Q[i].y);
            if(r1 != r2) {
                hn(r1, r2);
                d++;
                res+=Q[i].w;
                if(d == n - 1) break;
            }
        }
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


