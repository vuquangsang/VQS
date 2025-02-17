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
struct bg{ll id,ts;};
struct pll{ll fi,se;};
struct init{ll in,va;bool operator <(init const&a)const{return this->va>a.va;}};
ll mod(ll a, ll b) {return ((a%MN)*(b%MN))%MN;}
template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}

int n, a[MF];
vector<int> g[MF];
void input()
{
    cin >> n; fr(i, 1, n) cin >> a[i];
    int x, y;
    fr(i,2 , n) {
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
}
namespace sub1
{

    ll dp[MF][2][2], prev[2][2];
    void DFS(int u, int p)
    {
        for(int v : g[u]) if(v != p) {
            DFS(v, u);
        }
        dp[u][0][0] = 0;
        dp[u][1][0] = a[u];
        dp[u][0][1] = -a[u];
        dp[u][1][1] = -inf;
        for(int v : g[u]) if(v != p) {
            fr(add, 0, 1) fr(sub, 0, 1) {
                prev[add][sub] = dp[u][add][sub];
                dp[u][add][sub] = -inf;
            }
            fr(ua, 0, 1) fr(us, 0, 1) fr(va, 0, 1) fr(vs, 0, 1) {
                if(ua && va) continue;
                if(us && vs) continue;
                maxi(dp[u][ua || va][us || vs], prev[ua][us] + dp[v][va][vs]);
                //hiểu nôm na là thằng cha của nó xor 2 thằng con
            }
            // đã chia đoạn
            fr(ua, 0, 1) fr(us, 0, 1) maxi(dp[u][ua][us], prev[ua][us] + dp[v][1][1]);
        }

    }
    void slv()
    {
        DFS(1, -1);
        cout << max(1LL*0, dp[1][1][1]);
    }
}
namespace sub2
{
    const int MAX = 2e5 + 2;
    ll dp[MAX][5], tmp[MAX];
    void dfs(int u, int par)
    {
        // dp[u][0] chua chon dau nao
        // dp[u][1]  da chon dau +
        // dp[u][2]  da chon dau -
        // dp[u][3]  da chon + && -
        dp[u][0] = 0;
        dp[u][1] = a[u];
        dp[u][2] = -a[u];
        for(int v : g[u]) if(v != par) {
            dfs(v, u);

            tmp[0] = dp[u][0] + dp[v][3];
            tmp[1] = max(dp[v][1] + dp[u][0], dp[v][3] + dp[u][1]);
            tmp[2] = max(dp[v][2] + dp[u][0], dp[v][3] + dp[u][2]);
            tmp[3] = max({dp[v][3] + dp[u][0], dp[v][1]+ dp[u][2], dp[v][2] + dp[u][1], dp[v][3] + dp[u][3]});
            // dp[u][3] + dp[v][3] do co nhieu goc
            dp[u][0] = tmp[0];
            dp[u][1] = tmp[1];
            dp[u][2] = tmp[2];
            dp[u][3] = tmp[3];
        }
    }
    void slv()
    {
        dfs(1, 0);
        fr(i, 1, n) {
            fr(j, 0, 3) {
                cout << dp[i][j] << ""
            }
        }
        cout << dp[1][3];
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
        sub2::slv();
    //    sub2::slv();
    }
}



