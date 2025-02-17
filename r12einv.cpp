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
#define ll int
const int MAX = 1e5 + 2;
int n, k;
int a[MAX];
void input()
{
    cin >> n >> k; fr(i, 1, n) cin >> a[i];
}
namespace sub1
{
    int lim;
    inline void compres()
    {
        vector<int> V;
        fr(i, 1, n) V.pb(a[i]);
        sort(all(V));
        V.resize(unique(all(V)) - V.begin());
        fr(i, 1, n) a[i] = lower_bound(all(V), a[i]) - V.begin() + 1;
        lim = V.size();
    }
    ll sa[MAX], sb[MAX];
    int bit[MAX];
//        void upd(ll id, ll l, ll r, ll i, ll val)
//        {
//            if(i > r || i < l ) return;
//            if(l == r) {
//                t[id]+=val;
//                return;
//            }
//            int m = (r + l) >> 1;
//            upd(id << 1, l, m, i, val);
//            upd(id << 1 | 1, m + 1, r, i, val);
//            t[id] = t[id << 1] + t[id << 1 | 1];
//        }
//        ll get(ll id, ll l, ll r, ll u, ll v)
//        {
//            if(r < u || v < l) return 0;
//            if(u <= l && r <= v) return t[id];
//            int m = (r + l) >> 1;
//            return get(id << 1, l, m, u, v) + get(id << 1 | 1, m + 1, r, u, v);
//        }
    inline void upd(ll x, ll v)
    {
        for(; x <= n; x+=x&(-x)) bit[x]+=v;
    }
    inline ll get(ll x)
    {
        ll res = 0;
        for(; x >= 1; x-=x&(-x)) res+=bit[x];
        return res;
    }
    void slv()
    {
        compres();
//        fr(i, 1, n) cout << a[i] << " "; cout << el;
        upd(a[1], 1);
        fr(i, 2, n) {
            sa[i] = get(lim) - get(a[i]);
            upd(a[i], 1);
        }
        memset(bit, 0, sizeof bit);
        upd(a[n], 1);
        frd(i, n - 1, 1) {
            sb[i] = get(a[i] - 1);
            upd(a[i], 1);
        }
//        fr(i, 1, n) cout << sa[i] << " "; cout << el;
//        fr(i, 1, n) cout << sb[i] << " "; cout << el;
        fr(i, 2, n) sa[i]+=sa[i - 1];
        frd(i, n - 1, 1) sb[i]+=sb[i + 1];
        ll res = 0 ;
        memset(bit, 0, sizeof bit);
        fr(i, 1, n - 1) {
            upd(a[i], 1);
            ll cnt = sa[i];
            if(cnt > k) break;


            frd(j, n, i + 1) {
                cnt+=get(lim) - get(a[j]);
                if(cnt + sb[j] <= k) res++;
                else break;
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


