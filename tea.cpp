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

const int MAX = 5e4 + 2;
int n, q, a[MAX];
node Q[MAX];
void input()
{
    cin >> n >> q;
    fr(i, 1, n) cin >> a[i];
    fr(i, 1, q) cin >> Q[i].x >> Q[i].y;
    sort(alla(Q, q), [](node a, node b){return a.x < b.x;});
    sort(alla(a, n));

}
namespace sub1
{

    int sa[MAX], sb[MAX];
    void slv()
    {
        int ans = 0, cur = 0;
        REP(msk, 0, Mask(n)) {
            memset(sa, 0, sizeof sa);
            memset(sb, 0, sizeof sb);
            fr(i, 1, n) {
                sa[i] = sa[i - 1];
                sb[i] = sb[i - 1];
                if(msk&(1 << (i - 1))) sa[i]++;
                else sb[i]++;
            }
//            fr(i, 1, n) cout << sa[i] << " " ; cout << el;
//            fr(i, 1, n) cout << sb[i] << " " ; cout << el;
            int res = 0;
            fr(i, 1, q) {
                int va = Q[i].x;
                int vb = Q[i].y;
                int l = lower_bound(alla(a, n), va) - a;
                int r = upper_bound(alla(a, n), vb) - a - 1;
                if(abs((sa[r] - sa[l - 1]) - (sb[r] - sb[l - 1])) <= 1) res++;
            }
            if(maxi(ans, res)) {
                cur = msk;
            }
        }
        cout << ans << el;
        fr(i, 1, n) {
            if(cur&(1 << (i - 1))) cout << "S";
            else cout << "C";
        }
    }
}
namespace sub2
{
    bool check()
    {
        bool ok =  1;
        fr(i, 2, q) if(Q[i - 1].y > Q[i].x) ok = 0;
        return ok;
    }
    ll pre[MAX];
    void slv()
    {
        cout << q << el;
        fr(i, 1, q) {
            int va = Q[i].x;
            int vb = Q[i].y;
            int l = lower_bound(alla(a, n), va) - a;
            int r = upper_bound(alla(a, n), vb) - a - 1;
            int m = (r + l) >> 1;
            pre[l]++;
            pre[m + 1]--;
        }
        fr(i, 1, n) pre[i]+=pre[i - 1];
        fr(i, 1, n) {
            if(pre[i] == 1) cout << "S";
            else cout << "C";
        }
    }
}

main()
{
    #define TASK "tea"
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
        if(n <= 20 && q <= 200) sub1::slv();
        else if(sub2::check()) sub2::slv();
    }
}


