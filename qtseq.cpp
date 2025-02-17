/* Vu Quang Sang from Le Khiet High School for Gifted */
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

const ll MN = 1e9+7;
const ll MF = 1e6+2;
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
template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}

ll n, a[MF];
void input()
{
    cin >> n; fr(i, 1, n) cin >> a[i];
}
namespace sub1
{

    unordered_map<ll,ll> mp;
    ll pre[MF], ma[MF], mi[MF], suf[MF];
    void slv()
    {
        fr(i, 1, n) pre[i] = pre[i - 1] + a[i];
        frd(i, n, 1) suf[i] = suf[i + 1] + a[i];
        ma[1] = pre[1];
        mi[n] = suf[n];
        fr(i, 2, n) ma[i] = max(ma[i - 1], pre[i]);
        frd(i, n - 1, 1) mi[i] = min(mi[i + 1], suf[i]);
        ll res = -inf;
        fr(i, 1, n - 1) maxi(res, abs(ma[i] - mi[i + 1]));
        ll ans = 0;
        mi[1] = a[1];
        ma[n] = a[n];
        ll tmp = -inf;
        fr(i, 2, n) mi[i] = min(mi[i - 1], pre[i]);
        frd(i, n - 1, 1) ma[i] = max(ma[i + 1], suf[i]);
        fr(i, 1, n - 1) maxi(tmp, abs(mi[i] - ma[i + 1]));
        maxi(res, tmp);
        frd(i, n, 1) mp[suf[i]]++;
        fr(i, 1, n) {
            mp[suf[i]]--;
            ans+=mp[pre[i] - res];
            ans+=mp[pre[i] + res];
        }
  //      cout << ans << " " << s << el;
  //      cout << res << " " << ans << " " << tmp << " " << s << el;
        if(!res) ans/=2;
        cout << res << " " << ans;
    }
}
namespace sub2
{
    ll pre[MF], suf[MF];
    void slv()
    {
        fr(i, 1, n) pre[i] = pre[i - 1] + a[i];
        frd(i, n, 1) suf[i] = suf[i + 1] + a[i];

        ll res = -MN;
        ll ans = 0;
        fr(i, 1, n - 1) {
            fr(j, i + 1, n) {
                ll value = abs(pre[i] - suf[j]);
                if(maxi(res, value)) ans = 1;
                else if(res == value) ans++;
            }
        }
        cout << res << " " << ans;
    }
}

main()
{
    #define TASK "task"
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 //   freopen( TASK".inp", "r", stdin);
 //   freopen( TASK".ans", "w", stdout);
    bool qs = 0;
    ll mtt = 1;
    if(qs) cin >> mtt;
    fr(i, 1, mtt){
        input();
        sub1::slv();
    //    cout << el << el; sub2::slv();
    }
}



