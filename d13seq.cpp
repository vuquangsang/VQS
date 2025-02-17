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


const int N = 2e6 + 5, base = 311, sm = 1e9 + 7;
const long long inf  = 1e18 + 2;
const int dx[5] = {0, -1, 1, 0 , 0};
const int dy[5] = {0, 0, 0, -1, 1};

struct node{ll x,y;};
template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}

int n, a[N];
void input()
{
    cin >> n;
    fr(i, 1, n) cin >> a[i];
}
namespace sub1
{

    ll pre[N], dp[N][2];
    void slv()
    {
        fr(i, 1, n) pre[i] = pre[i - 1] + a[i];
        memset(dp, -0x3f3f3f, sizeof dp);
        fr(i, 3, n) {
            dp[i][1] = max({pre[i] - pre[i - 3], dp[i - 3][1] + pre[i] - pre[i - 3], 1ll*-inf});

        }
        fr(i, 1, n) dp[i][1] = max(dp[i - 1][1], dp[i][1]);

        frd(i, n - 2, 1) {
            dp[i][2] = max({pre[i + 2] - pre[i - 1], dp[i + 3][2] + pre[i + 2] - pre[i - 1], 1ll*-inf});
        }
        frd(i, n, 1) dp[i][2] = max(dp[i + 1][2], dp[i][2]);


        ll res = -inf;
        fr(i, 1, n - 1) maxi(res, dp[i][1] + dp[i + 1][2]);
        cout << res;
    }
}
namespace sub2
{
    ll pre[N];
    void slv()
    {
        fr(i, 1, n) pre[i] = pre[i - 1] + a[i];
        ll res = -inf;
        fr(i, 1, n) {
            fr(j, i + 1, n) {
                fr(u, j + 1, n) {
                    fr(v, u + 1, n) {
                        if((j - i + 1)%3 == 0 && (v - u + 1)%3 == 0) {
                            maxi(res, pre[j] - pre[i - 1] + pre[v] - pre[u - 1]);
                        }
                    }
                }
            }
        }
        cout << res;
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




