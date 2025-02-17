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
int n, a[N];
void input()
{
    cin >> n; fr(i, 1, n) cin >> a[i];
}
namespace sub1
{

    const int MAX = 4e5 + 2;
    int cnt[MAX], dp[N], s[N];
    vector<int> calc(int x)
    {
        vector<int> res;
        fr(i, 2, sqrt(x)) {
            if(x % i == 0) {
                res.pb(i);
                res.pb(x / i);
            }
        }
        return res;
    }
    void slv()
    {
        int sum = 0, res = 0;
        fr(i, 1, n) sum += a[i];
        fr(i, 1, n) s[i] = s[i - 1] + a[i];
        vector<int> v= calc(sum);
//        for(int x : v) cout << x << " "; cout << el;
        for(int x : v) {
            memset(cnt, 0, sizeof cnt);
            cnt[0]++;
            int ans = 1;
            fr(i, 1, n) {
                if(s[i] % x != 0) continue;
                ans *= cnt[s[i] - x];
                cnt[s[i]]++;
            }
            res += ans;
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


