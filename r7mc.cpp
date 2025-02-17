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

const int MAX = 6e4 + 2;
int n, a[MAX];
void input()
{
    cin >> n; fr(i, 1, n) cin >> a[i];
}
namespace sub1
{

    ll dp[5][MAX];
    vector<int> V;
    struct IT
    {
        ll t[8*MAX];
        void upd(ll id, ll l, ll r, ll i, ll val)
        {
            if(i > r || i < l) return;
            if(l == r) {
                maxi(t[id], val);
                return;
            }
            int m = (r + l) >> 1;
            upd(id << 1, l, m, i, val);
            upd(id << 1 | 1, m + 1, r, i, val);
            t[id] = max(t[id << 1], t[id << 1 | 1]);
        }
        ll get(ll id, ll l, ll r, ll u, ll v)
        {
            if(r < u || v < l) return -inf;
            if(u <= l && r <= v) return t[id];
            int m = (r + l) >> 1;
            return max(get(id << 1, l, m, u, v), get(id << 1 | 1, m + 1, r, u, v));
        }
    } st[5];

    void slv()
    {
        fr(i, 1, n) V.pb(a[i]);
        sort(all(V));
        V.resize(unique(all(V)) - V.begin());
        fr(i, 1, n) a[i] = lower_bound(all(V), a[i]) - V.begin() + 1;
        int lim = V.size();
//        fr(i, 1, n) cout << a[i] << " "; cout << el;
        memset(dp, -0x3f3f, sizeof dp);
        fr(i, 1, 4) memset(st[i].t, -0x3f3f, sizeof st[i].t);
        bool ok = 0;
        fr(i, 1, n) {
            dp[1][i] = 1;
            maxi(dp[1][i], st[1].get(1, 1, lim, 1, a[i] - 1) + 1);
            if(st[1]. get ( 1 , 1 , lim , a[i]+1 , lim) >= 2) maxi(dp[2][i], st[1].get(1, 1, lim, a[i] + 1, lim) + 1);

            maxi(dp[2][i] ,st[2].get(1, 1, lim, a[i] + 1, lim) + 1);

            if(st[2]. get ( 1 , 1 , lim , 1 , a[i]-1 ) >= 1) dp[3][i] = st[2].get(1, 1, lim, 1, a[i] - 1) + 1;
            maxi(dp[3][i], st[3].get(1, 1, lim, 1, a[i] - 1) + 1);
            if(st[3]. get ( 1 , 1 , lim , a[i]+1 , lim ) >= 1) dp[4][i] = st[3].get(1, 1, lim, a[i] + 1, lim) + 1;
            maxi(dp[4][i], st[4].get(1, 1, lim, a[i] + 1, lim) + 1);

            fr(k, 1, 4) st[k].upd(1, 1, lim, a[i], dp[k][i]);
        }
//        cout << dp[2][2]; return;
        cout << *max_element(alla(dp[4], n));
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
