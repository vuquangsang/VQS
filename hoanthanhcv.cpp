/* Vu Quang Sang from Le Khiet High School for Gifted */
#include <bits/stdc++.h>
using namespace std;

#define     lg(x) __lg(x)
#define     alla(a,n) a+1,a+n+1
#define     el "\n"
#define     all(x) x.begin(),x.end()
#define     pb push_back
#define     ll long long
#define     int long long
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

const int MAX = 6e5 + 12;
int n, k, t[MAX];
void input()
{
    cin >> n >> k; fr(i, 1, n) cin >> t[i];
}
namespace sub1
{
    struct eg
    {
        ll val, u;
        bool operator <(eg const&a) const
        {
            return val > a.val;
        }
    };
    priority_queue<eg> q;
    vector<ll> g[MAX];
    vector<int> v;
    void slv()
    {
        fr(i, 1, k) q.push({t[i], i});
        int j = k + 1, vir_node = n + 2;
        long long ans = 0;
        while(j <= n + 2 ){
            if(q.empty()) break;

            ll cur_sum = q.top().val;
            vector<int> tmp;
            ans = max(ans, cur_sum);

            while(!q.empty() && q.top().val == cur_sum) {
                tmp.pb(q.top().u);
                q.pop();
            }

            for(int v : tmp) {
                g[vir_node].pb(v);
            }

            for(int v = j; v <= j + tmp.size() - 1; v++) {
                g[v].pb(vir_node);
            }

            for(int v = j; v <= j + tmp.size() - 1; v++) {
                q.push({cur_sum + t[v], v});
            }
            vir_node++;
            j+=tmp.size();
        }

        vector<int> vis(4*n + 20, 0);
        queue<int> pq;
        pq.push(n + 1);
        while(!pq.empty()) {
            int u = pq.front(); pq.pop();
            if(vis[u]) continue;
            vis[u] = 1;
            for(int v : g[u]) {
                if(!vis[v]) pq.push(v);
            }
        }
        // sol Bui Quoc Cuong
        cout << ans << el;
        fr(i, 1, k) if(vis[i]) cout << i << " ";
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


