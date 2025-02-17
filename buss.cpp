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

const ll MN = 1e9+7;
const long long inf = 1e18+7;
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

const int MAX = 3e4 + 2;
ll n, m;
vector<pll> g[MAX];
void input()
{
    cin >> n >> m;
    ll x, y, w;
    fr(i, 1, m) {
        cin >> x >> y >> w;
        g[x].pb({y, w});
        g[y].pb({x, w});
    }
}
namespace sub1
{

    struct eg
    {
        ll u, k, w;
        bool operator <(eg const&a) const
        {
            return this -> w > a.w;
        }
    };
    ll f[MAX][2], dd[MAX][2];
    void DIJ()
    {
        memset(f, 0x3f, sizeof f);
        f[1][1] = 0, f[1][0] = 0;
        priority_queue<eg> q;
        q.push({1, 1, 0});
        q.push({1, 0, 0});
        while(!q.empty()) {
            ll u = q.top().u;
            ll k = q.top().k;
            q.pop();
            if(dd[u][k]) continue;
            dd[u][k] = 1;
            for(pll t : g[u]) {
                ll v= t.fi;
                ll w = t.se;
                if(!k) {
                    if(mini(f[v][1], f[u][0])) {
                        q.push({v, 1, f[v][1]});
                    }
                    if(mini(f[v][0], f[u][0] + w)) {
                        q.push({v, 0, f[v][0]});
                    }
                }
                else if(mini(f[v][k], f[u][k] + w)) {
                    q.push({v, k, f[v][k]});
                }
            }
        }
    }
    void slv()
    {
        DIJ();
        cout << min(f[n][1], f[n][0]);
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


