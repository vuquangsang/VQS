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

const int N = 2e5 + 2;
int n, q, a[N];
void input()
{
    cin >> n >> q; fr(i, 1, n) cin >> a[i];
}
namespace sub1
{

    struct Node
    {
        ll dp[2][2];
        int head, tail;
    } st[4 * N];

    ll diff[N];


    Node merge(Node a, Node b)
    {
        Node res;
        if(!a.head) return b;
        if(!b.head) return a;

        if(a.tail != b.head) {
            fr(add, 0, 1) fr(sub, 0, 1) {
                res.dp[add][sub] = max(a.dp[add][1] + b.dp[0][sub], a.dp[add][0] + b.dp[1][sub]);
            }
        }
        else {
            fr(add, 0, 1) fr(sub, 0, 1) {
                res.dp[add][sub] = a.dp[add][1] + b.dp[1][sub];
            }
        }
        res.head = a.head;
        res.tail = b.tail;
        return res;
    }

    void upd(int id, int l, int r, int i, int val)
    {
        if(i > r ||i < l) return;
        if(l == r) {
            diff[l] += val;
            st[id].dp[1][1] = abs(diff[l]);
            st[id].head = st[id].tail = (diff[l] >= 0 ? 1 : -1);
            return;
        }
        int mid = (r + l) >> 1;
        upd(id << 1, l, mid, i, val);
        upd(id << 1 | 1, mid + 1, r, i, val);
        st[id] = merge(st[id << 1], st[id << 1 | 1]);
    }

//    Node get(int id, int l, int r, int u, int v)
//    {
//        if(r < u || v < l) return {0, 0, 0, 0, 0, 0};
//        if(u <= l && r <= v) return st[id];
//        int mid = (r + l) >> 1;
//        return merge(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
//    }
    void slv()
    {
        fr(i, 1, n - 1) diff[i] = a[i] - a[i + 1];
        fr(i, 1, n) upd(1, 1, n - 1, i, 0);
        int x, y, val;
        while(q--) {
            cin >> x >> y >> val;
            upd(1, 1, n - 1, x - 1, - val);
            upd(1, 1, n - 1, y, val);
            cout << max({st[1].dp[0][0], st[1].dp[1][0], st[1].dp[0][1], st[1].dp[1][1]}) << el;
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


