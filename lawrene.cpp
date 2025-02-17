/* Try to do something */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ll,ll>  pll;
typedef vector<int> vi;
typedef vector<pii> vii;

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
#define     sz(a) (int)a.size()
#define     uni(V) sort(all(V)), V.resize(unique(all(V)) - V.begin())


const int N = 2e5 + 5, base = 311, sm = 1e9 + 7;
const long long inf  = 1e18 + 2;
const int dx[5] = {0, -1, 1, 0 , 0};
const int dy[5] = {0, 0, 0, -1, 1};

struct node{ll x,y;};
template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}

int n, m, a[N];
void input()
{
    cin >> n >> m;
    fr(i, 1, n) cin >> a[i];
}
namespace sub1
{
    const int MAX = 505;
    ll suf[N];
    ll dp[MAX][MAX], pre[MAX][MAX];
    void slv()
    {
        frd(i, n, 1) suf[i] = suf[i + 1] + a[i];
        fr(i, 1, n) {
            fr(j, i + 1, n) {
                fr(k, i, j - 1) {
                    pre[i][j]+=a[k]*(suf[k + 1] - suf[j + 1]);
                }
            }
        }
        memset(dp, 0x3f3f, sizeof dp);
        fr(i, 1, m) dp[n][0] = 0;
        fr(i, 1, n) dp[i][0] = pre[i][n];
        frd(i, n, 1) {
            fr(k, 0, m - 1) {
                if(k > n - i) break;
                fr(j, i, n - 1){
                    mini(dp[i][k + 1], dp[j + 1][k] + pre[i][j]);
                }
            }
        }
//        fr(i, 1, n) {
//            fr(j, 0, m) {
//                cout << dp[i][j] << " ";
//            } cout << el;
//        } cout << el;
        cout << dp[1][m];
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
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    #define TASK ""
    if(fopen(TASK".INP", "r")) {
        freopen(TASK".INP", "r", stdin);
        freopen(TASK".OUT", "w", stdout);
    }

    bool qs = 0;

    int tt = 1;
    if(qs) cin >> tt;
    while(tt--) {
        input();
        sub1::slv();
    }
    cerr << "\nTime" << 0.001 * clock() << "s "; return 0;


}



