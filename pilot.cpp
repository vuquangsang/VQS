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

int n, q;
int a[N];
void input()
{
    cin >> n >> q;
    fr(i, 1, n) cin >> a[i];
}
namespace sub1
{
    ll ans[N];
    int st[4*N], t[4*N], L[N], R[N];
    void upd(ll id, ll l, ll r, ll i, ll val)
    {
        if(i > r || i < l) return;
        if(l == r) {
            st[id] = val;
            return;
        }
        int mid = (r + l) >> 1;
        upd(id << 1, l, mid, i, val);
        upd(id << 1 | 1, mid + 1, r, i, val);
        st[id] = max(st[id << 1], st[id << 1 | 1]);
    }
    int walk1(int id, int l, int r, int u, int v, int val)
    {
        if(r < u || v < l || st[id] > val || st[id] == -1) return -1;
        if(l == r) return l;
        int mid = (r + l) >> 1;
        int res = walk1(id << 1 | 1, mid + 1, r, u, v, val);
        int tmp = walk1(id << 1, l, mid, u, v, val);
        if(tmp == -1) return res;
        else {
            res = tmp;
            if(res == 1) return res;
        }
    }
    int walk2(int id, int l, int r, int u, int v, int val)
    {
        if(r < u || v < l || st[id] > val || st[id] == -1) return -1;
        if(l == r) return l;
        int mid = (r + l) >> 1;
        int res = walk2(id << 1, l, mid, u, v, val);
        int tmp = walk2(id << 1 | 1, mid + 1, r, u, v, val);
        if(tmp == -1) return res;
        else {
            res = tmp;
            if(res == n) return res;
        }
    }
    void slv()
    {
        stack<ll> s;
        fr(i, 1, n) {
            while(!s.empty() && a[s.top()] < a[i]) s.pop();
            if(s.empty()) L[i] = 1;
            else L[i] = s.top() + 1;
            s.push(i);
        }
        while(!s.empty()) s.pop();
        frd(i, n, 1) {
            while(!s.empty() && a[s.top()] <= a[i]) s.pop();
            if(s.empty()) R[i] = n;
            else R[i] = s.top() - 1;
            s.push(i);
        }
        fr(i, 1, n) {
            cout << L[i] << " " << R[i] << el;
        } cout << el << el;

        memset(st, -1, sizeof st);
        fr(i, 1, n) {
            upd(1, 1, n, i, a[i]);
            int pos1 = walk1(1, 1, n, 1, i, a[i]);
            int pos2 = walk2(1, 1, n, i, n, a[i]);
//            maxi(pos2, i);
            cout << pos1 << " " << pos2 << el;
//            ans[a[i]]+=(i - L[i] + 1)*(R[i] - i + 1);
            ans[a[i]]+=(i - pos1 + 1)*(pos2 - i + 1);
        }
        fr(i, 1, 1e6) ans[i] = ans[i - 1] + ans[i];
        while(q--) {
            int h;
            cin >> h;
            cout << ans[h] << el;
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



