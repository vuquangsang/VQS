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

string s, t;
int n;
void input()
{
    cin >> s;
    t = s;
    s = ' ' + s;
    t = ' ' + t;
    n = t.size() - 1;
}
namespace sub1
{

    const int MAX = 1e6 + 2;

    int pw[MAX], hasA[MAX], hasB[MAX], dp[MAX];
    void build_has(string s, int has[]) {
        fr(i, 1, n) has[i] = mod(has[i - 1], base) + s[i] - 'a' + 1;
    }
    int get(int l, int r, int has[])
    {
        return (has[r] - mod(has[l - 1], pw[r - l + 1]) + MN)%MN;
    }
    int cal(int l, int r, int has[])
    {
        int m1 = get(l, r, hasA);
        int m2 = get(l, r, hasB);
        return m1*1e9 + m2;
    }
    bool palin(int l, int r)
    {
        if(cal(l, r, hasA) == cal(n - r + 1, n - l + 1, hasB)) return 1;
        return 0;
    }
    void slv()
    {
        pw[0] = 1;
        fr(i, 1, n) pw[i] = mod(pw[i - 1], base);

        build_has(s, hasA);
        build_has(t, hasB);

        int res = 0, ans = 0;
        fr(i, 1, n) fr(j, i + 1, n) {
            int res = 0, l = 1, r = min(i, n - i + 1);
            while(l <= r) {
                int m = (r + l) >> 1;
                if(palin(i - m + 1, i + m - 1)) res = m, l = m + 1;
                else r = m - 1;

            }
            dp[i] = res;
        }
        fr(i, 1, n) cout << dp[i] << " "; return;
        cout << res << " " << ans;
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

