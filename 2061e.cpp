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

const int N = 1e5 + 10;
int n, m, k;
ll a[N], b[N];
void input()
{
    cin >> n >> m >> k;
    fr(i, 1, n) cin >> a[i];
    fr(i, 1, m) cin >> b[i];
}
namespace sub1
{


    void slv()
    {
        sort(b + 1, b + m + 1);

        priority_queue<ll> pq;
        fr(i, 1, n) pq.push(a[i]);
        while(1) {

            ll val = pq.top();
            bool ok = 0;
            fr(i, 1, m) {
                ll tmp = val & b[i];
                if(tmp != val && tmp < val) {
                    k--;
                    ok = 1;
                    pq.pop();
                    pq.push(tmp);
                    break;
                }
            }

            if(!ok) break;
            if(!k) break;
        }

        ll res = 0;
        while(!pq.empty()) {
            res += pq.top();
            pq.pop();
        }
        cout << res << el;
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
    bool qs = 1;
    ll mtt = 1;
    if(qs) cin >> mtt;
    fr(i, 1, mtt){
        input();
        sub1::slv();
    //    sub2::slv();
    }
}


