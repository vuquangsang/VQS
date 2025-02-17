#include <bits/stdc++.h>
using namespace std;

//#define   ll int
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
#define     BIT(msk, i) (msk&(1 << i))
#define     pk pop_back

const ll MN = 1e9+7;
const ll MF = 4*1e6+7;
const long long inf = 1e18+7;
const ll N = 1005;
const ll base = 311;
const ll F = 1e5 + 2;
const ll BLOCK = 320;
const int dx[5] = {0, -1, 1, 0 , 0};
const int dy[5] = {0, 0, 0, -1, 1};
const short LO = 17;

struct node{ll x,y;};
struct bg{ll id,ts;};
struct pll{ll fi,se;};
struct init{ll in,va;bool operator <(init const&a)const{return this->va>a.va;}};
ll mod(ll a, ll b) {return ((a%MN)*(b%MN))%MN;}
template<class X, class Y>
    bool mini(X &x, const Y &y)  {
        if(x > y) {
            x = y;
            return 1;
        }
        else return 0;
    }
template<class X, class Y>
    bool maxi(X &x, const Y &y)
    {
        if(x < y) {
            x = y;
            return 1;
        }
        else return 0;
    }
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}

ll n, h[MF];
deque<ll> dq;
void input()
{
    cin >> n; fr(i, 1, n) cin >> h[i];
}
namespace sub1
{
    ll L[MF], R[MF];
    ll f[MF], dp[MF];
    stack<ll> s;
    void slv()
    {
        fr(i, 1, n) f[i] = i, dp[i] = -i;
        fr(i, 1, n) {
            L[i] = i;
            while(!s.empty() && s.top() > i - h[i]) mini(L[i], L[s.top()]), s.pop();
            s.push(i);
        }
        while(!s.empty()) s.pop();
        frd(i, n, 1) {
            R[i] = i;
            while(!s.empty() && s.top() < i + h[i]) maxi(R[i], R[s.top()]), s.pop();
            s.push(i);
        }
        while(!s.empty()) s.pop();
 //       fr(i, 1, n) cout << L[i] << " " ; cout << el;
 //       fr(i, 1, n) cout << R[i] << " " ; cout << el;
        fr(i, 1, n) {
            if(f[i] > f[L[i] - 1] + 1) f[i] = f[L[i] - 1] + 1, dp[i] = -(L[i]);
            while(!s.empty() && R[s.top()] < i) s.pop();
            if(!s.empty() && f[i] > f[s.top() - 1] + 1){
                f[i] = f[s.top() - 1] + 1;
                dp[i] = s.top();
            }
            if(s.empty()) s.push(i);
            else if(!s.empty() && f[s.top() - 1] > f[i - 1]) s.push(i);
        }
        cout << f[n] << el;
        for(int i = n; i ; i = abs(dp[i]) - 1) {
            cout << (dp[i] < 0 ? -i : dp[i]) << " ";
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


