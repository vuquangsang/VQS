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

const int MAX = 1e5 + 2;
int n, q, v[MAX];
string a[MAX];
void input()
{
    cin >> n >> q;
    fr(i, 1, n) cin >> v[i];
    fr(i, 1, n) cin >> a[i];
}
namespace sub1
{
    bool check()
    {
        ll sz = 0;
        fr(i, 1, n) {
            ll ans = a[i].size();
            maxi(sz, ans);
        }
        return n*sz*q <= 1e4;
    }
    void slv()
    {
        ll k, pos, val;
        string s;
        while(q--) {
            cin >> k;
            if(k == 1) {
                cin >> pos >> val;
                v[pos] = val;
            }
            else {
                cin >> s;
                ll sz = s.size();
                ll res = 0;
                fr(i, 1, n) {
                    ll ans = 0;
                    if(s.size() <= a[i].size()) {
                        fr(j, 0, a[i].size() - s.size()) {
                            string tmp = a[i].substr(j, sz);
                            if(tmp == s) ans++;
                        }
                    }
                    res = res + ans*v[i];
                }
                cout << res << el;
            }
        }
    }
}
namespace sub2
{
    vector<int> build(string s)
    {
        int m = s.size();
        vector<int> pre(m);
        int j = 0;
        fr(i, 1, m - 1) {
            while(j > 0 && s[i] != s[j]) {
                j = pre[j - 1];
            }
            if(s[i] == s[j]) {
                j++;
            }
            pre[i] = j;
        }
        return pre;
    }
    int kmp(string t, string s)
    {
        int n = t.size();
        int m = s.size();
        vector<int> pre = build(s);
        int cnt = 0;
        int j = 0;

        fr(i, 0, n - 1) {
            while(j > 0 && t[i] != s[j]) {
                j = pre[j - 1];
            }
            if(t[i] == s[j]) {
                j++;
            }
            if(j == m) {
                cnt++;
                j = pre[j - 1];
            }
        }
        return cnt;
    }
    void slv()
    {
        string s;
        ll k, pos, val;
         while(q--) {
            cin >> k;
            if(k == 1) {
                cin >> pos >> val;
                v[pos] = val;
            }
            else {
                cin >> s;
                ll res = 0;
                fr(i, 1, n) res = res + v[i]*kmp(a[i], s);
                cout << res << el;
            }
        }
    }
}

main()
{
    #define TASK "function"
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
        if(sub1::check()) sub1::slv();
        else sub2::slv();
    //    sub2::slv();
    }
}


