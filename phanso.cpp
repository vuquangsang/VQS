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

#define pii pair<ll,ll>
int h, k;
const int MAX = 5e5 + 2;
pii a[MAX];
void input()
{
    cin >> h >> k;
    fr(i, 1, k) cin >> a[i].fi >> a[i].se;
}
namespace sub1
{
    vector<ll> v;
    pii sum(pii a, pii b)
    {
        return {a.fi + b.fi, a.se + b.se};
    }
    void DFS(ll id, pii L, pii R, pii u, pii desti)
    {
        if(u == desti)
        {
            v.pb(id);
            return;
        }
        bool t = (desti.fi*u.se < u.fi*desti.se);
        if(t) {
            DFS(id << 1, L, u, sum(L, u), desti);
        }
        else {
            DFS(id << 1 | 1, u, R, sum(R, u), desti);
        }
    }
    void slv()
    {
        fr(i, 1, k) DFS(1, {0, 1}, {1, 0}, {1, 1}, {a[i].fi, a[i].se});
        ll res =0 ;
        sort(all(v));
    //    for(auto x : v) cout << x << " "; cout << el;
        queue<ll> q;
        while(!q.empty() || !v.empty()) {
            ll ans = 0;
            if(!v.empty()) {
                ll tmp = v[v.size() - 1];
                maxi(ans, tmp);
            }
            if(!q.empty()) {
                maxi(ans, q.front());
            }
            while(!q.empty() && q.front() == ans) q.pop();
            while(!v.empty() && v.back() == ans) v.pop_back();
            if(ans == 1)  break;
            q.push(ans/2);
            res++;
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


