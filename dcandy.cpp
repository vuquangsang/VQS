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

const int N = 5e4 + 2;
int n, m, a[N];
void input()
{
    cin >> n >> m; fr(i, 1, n) cin >> a[i];
}
namespace sub1
{
    int dp[N][55];
    int pos[N];

    int st[8 *N], lz[8 * N];


    void build(int id, int l, int r, int j)
    {
        lz[id] = 0;
        if(l == r) {
            st[id] = dp[l][j];
            return;
        }
        int mid = (r + l) >> 1;
        build(id << 1, l, mid, j);
        build(id << 1 | 1, mid + 1, r, j);
        st[id] = max(st[id << 1], st[id << 1 | 1]);
    }
    void down(int id, int l, int mid, int r)
    {
        if(lz[id]) {
            int val = lz[id];
            st[id << 1] += val;
            st[id << 1 | 1] += val;
            lz[id << 1] += val;
            lz[id << 1 | 1] += val;
            lz[id] = 0;
        }
    }
    void upd(int id, int l, int r, int u, int v, int val)
    {
        if(r < u || v < l) return;
        if(u <= l && r <= v) {
            st[id] += val;
            lz[id] += val;
            return;
        }
        int mid = (r + l) >> 1;
        down(id, l, mid, r);
        upd(id << 1, l, mid, u, v, val);
        upd(id << 1 | 1, mid + 1, r, u, v, val);
        st[id] = max(st[id << 1], st[id << 1 | 1]);
    }
    int get(int id, int l, int r, int u, int v)
    {
        if(r < u || v < l) return 0;
        if(u <= l && r <= v) return st[id];
        int mid = (r + l) >> 1;
        down(id, l, mid, r);
        return max(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
    }

    int cnt[N];
    void slv()
    {
        int d = 0;
        fr(i, 1, n) {
            if(!cnt[a[i]]) d++;
            dp[i][1] = d;
            cnt[a[i]] = 1;
        }
        fr(j, 2, m) {

            build(1, 1, n, j - 1);
            memset(pos, 0, sizeof pos);
            fr(i, j, n) {
                if(j > i) continue;
                if(!pos[a[i]]) upd(1, 1, n, 1, i - 1, 1);
                else upd(1, 1, n, pos[a[i]], i - 1, 1);
                dp[i][j] = get(1, 1, n, 1, i);
                pos[a[i]] = i;
            }
        }
//        cout << dp[4][2]; return;
        cout << dp[n][m];
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


