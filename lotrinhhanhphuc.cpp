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
const long long inf = 1e15+7;
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

//#define TASK "lotrinhhanhphuc"
#define TASK ""
const int MAX = 1e5 + 2;
int n, K, D;
int h[MAX], t[MAX];
void input()
{
    cin >> n >> K >> D;
    fr(i, 1, n) cin >> h[i];
    fr(i, 1, n - 1) cin >> t[i];
}

namespace sub1
{
    long long dp[MAX];
    set<pair<int, int>> id, mp[MAX];
    long long st[4*MAX];
    int lim;
    void upd(ll id, ll l, ll r, ll i, ll val)
    {
        if(i > r || i < l) return;
        if(l == r) {
            if(val == -inf) t[id] = val;
            else maxi(st[id], val);
            return;
        }
        int m = (r + l) >> 1;
        upd(id << 1, l, m, i, val);
        upd(id << 1 | 1, m + 1, r, i, val);
        st[id] = max(st[id << 1], st[id << 1 | 1]);
    }
    ll get(ll id, ll l, ll r, ll u, ll v)
    {
        if(r < u || v < l) return -inf;
        if(u <= l && r <= v) return st[id];
        int m = (r + l) >> 1;
        return max(get(id << 1, l, m, u, v), get(id << 1 | 1, m + 1, r, u, v));
    }
    void slv()
    {
        memset(dp, -0x3f3f, sizeof dp);
        lim = K - 1;
        dp[1] = h[1];
        fr(i, 1, 4*lim) st[i] = -inf;
        upd(1, 0, lim, (1%K), dp[1] + (1/K)*D);

        id.insert({t[1] + 1, 1});
        mp[1%K].insert({dp[1] + (1/K)*D, 1 + t[1]});
        fr(i, 2, n) {

            int pos = i%K;
            while(id.size() && (*id.begin()).fi < i) {
                int tmp = (*id.begin()).se%K;
                id.erase(id.begin());
                while(mp[tmp].size() && (*mp[tmp].rbegin()).se < i) {
                    upd(1, 0, lim, tmp, -inf);
                    mp[tmp].erase({(*mp[tmp].rbegin()).fi, (*mp[tmp].rbegin()).se});
                }
                if(mp[tmp].size()) upd(1, 0, lim, tmp, (*mp[tmp].rbegin()).fi);
            }
            dp[i] = h[i] - (i/K)*D + max(get(1, 0, lim, 0, pos), get(1, 0, lim, pos + 1, lim) + D);
            upd(1, 0, lim, i%K, dp[i] + (i/K)*D);
//            cout << dp[i] << " ";
//            return;
            id.insert({i + t[i], i});
            mp[i%K].insert({dp[i] + (i/K)*D, i + t[i]});
        }
        cout << dp[n];
    }
}
main()
{

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


