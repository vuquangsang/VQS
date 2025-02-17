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

#define TASK ""
#define TASK "task"

const int MAX = 1e6 + 2;
int n, k, a[MAX];
int cnt[MAX];
void input()
{
    cin >> n >> k;
    fr(i, 1, n) cin >> a[i];
    fr(i, 1, n) cnt[a[i]]++;
}
//namespace sub1
//{
//
//    vector<int> pos[MAX];
//    vector<int> V;
//    void cal()
//    {
//
//    }
//    void slv()
//    {
//        fr(i, 1, n) {
//            V.pb(a[i]);
//        }
//        sort(all(V));
//        V.resize(unique(all(V)) - V.begin());
//        fr(i, 1, n) pos[a[i]].pb(i);
//        vector<int> ans;
//        for(int x : V) {
//            for(int u = 0; u < pos[x].size(); u++) {
//                for(int v = u + 1; v < pos[x].size(); v++) {
//                    int L = pos[x][u] ;
//                    int R = pos[x][v];
//                    if(R - L + 1 < k && v - u + 1 > k/2) ans.pb(x);
//                    else if(R - L + 1 >= k && v - u + 1 > (R - L + 1)/2) ans.pb(x);
//                }
//            }
//        }
//        sort(all(ans));
//        ans.resize(unique(all(ans)) - ans.begin());
//        for(int x : ans) cout << x << " ";
//    }
//}
namespace sub2
{
    const int SQRT = sqrt(1e7) + 5;
    vector<int> tmp;
    int pre[MAX], mi[MAX];
    vector<int> pos[MAX];
    vector<int> V;
    int cnt[MAX];
    bool check(int x)
    {
        pre[0] = 0;
        fr(i, 1, n) pre[i] = pre[i - 1] + (a[i] == x);
        mi[0] = 0;
        fr(i, 1, k - 1) mi[i] = min(mi[i - 1], 2*pre[i] - i);

        fr(i, k, n) {
            mi[i] = min(mi[i - 1], 2*pre[i] - i);
            if(2*pre[i] - i > mi[i - k]) return 1;
        }
        return 0;
    }
    bool check2(int x)
    {
        for(int u = 0; u < pos[x].size(); u++) {
            for(int v = u + 1; v < pos[x].size(); v++) {
                int L = pos[x][u] ;
                int R = pos[x][v];
                if(R - L + 1 < k && v - u + 1 > k/2) return 1;
                else if(R - L + 1 >= k && v - u + 1 > (R - L + 1)/2) return 1;
            }
        }
        return 0;
    }
    void slv()
    {
        vector<int> ans;
        fr(i, 1, n) cnt[a[i]]++;
        fr(i, 1, n) if(cnt[a[i]] > SQRT) {
            V.pb(a[i]);
        }
        sort(all(V));
        V.resize(unique(all(V)) - V.begin());

        for(int x : V) {
            if(check(x)) ans.pb(x);
        }

        V.clear();
        fr(i, 1, n) if(cnt[a[i]] <= SQRT) V.pb(a[i]);
        sort(all(V));
        V.resize(unique(all(V)) - V.begin());
        fr(i, 1, n) pos[a[i]].pb(i);

        for(int x : V) if(check2(x)) ans.pb(x);
        sort(all(ans));
        ans.resize(unique(all(ans)) - ans.begin());
        if(ans.size() > 0) for(int x: ans) cout << x << " ";
        else cout << -1;
    }
}

main()
{

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
        sub2::slv();
    //    sub2::slv();
    }
    cerr << el << clock() << "ms";
}
