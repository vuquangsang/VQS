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

const int N = 5e5 + 2;
int n, m;
char a[N];
vector<int> g[N];
void input()
{
    cin >> n >> m;
    int p;
    fr(i, 2, n) {
        cin >> p;
        g[p].pb(i);
    }
    fr(i, 1, n) cin >> a[i];
}
namespace sub1
{
    int in[N], out[N], time = 0, pos[N];
    vector<pair<int, int>> S[N];
    void DFS(int u, int depth)
    {
        in[u] = ++time;
        pos[time] = u;
        S[depth].pb(make_pair(time, S[depth].back().se ^ (1ll << (a[u] - 'a'))));
        for(int v : g[u]) {
            DFS(v, depth + 1);
        }
        out[u] = ++time;
    }
    bool calc(int v, int depth)
    {
        int l = lower_bound(S[depth].begin(), S[depth].end(), make_pair(in[v], 0)) - S[depth].begin() - 1;
        int r = upper_bound(S[depth].begin(), S[depth].end(), make_pair(out[v], 0)) - S[depth].begin() - 1;
//        mini(r, (int)S[depth].size() - 1);
//        cout << l << " " << r << el;
        int mer = S[depth][l].se ^ S[depth][r].se;

        int k = c_bit(mer);
        return k <= 1;
    }
    void slv()
    {
        fr(i, 1, n) S[i].resize(1);
        DFS(1, 1);
//        fr(i, 1, n) cout << pos[i] << " " ; cout << el;
//        fr(i, 1, n) cout << in[i] << " " << out[i] << el;
//        fr(i, 1, 3) {
//            cout << "depth" << " " << i << " : " << el;
//            for(auto x : S[i]) {
//                cout << x.fi << " " << x.se << el;
//            } cout << el << el;
//        }
        fr(i, 1, m){
            int v, depth;
            cin >> v >> depth;
            cout << (calc(v, depth) == 1? "Yes" : "No"); cout << el;
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


