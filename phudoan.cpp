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

struct node{int x,y;};
struct pll{ll fi,se;};
ll mod(ll a, ll b) {return ((a%MN)*(b%MN))%MN;}
template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}

#define TASK ""
#define TASK ""

const int MAX = 2e5 + 2;
int l, n, r;
node a[MAX];
void input()
{
    cin >> l >> r >> n;
}
namespace sub1
{
    map<int, pair<int, int>> cnt, mp;
    unordered_map<int, int> L, R;
    pair<int,int> u, v;
    int x, y, id;
    char k;

    void slv()
    {

        fr(i, 1, n) {
            cin >> k >> id;
            if(k == '+') {
                cin >> x >> y;
                if(l <= y && y <= r && x <= l) {
                    L[id] = y;
                }
                if(l <= x && x <= r && y >= r) {
                    R[id] = x;
                }
                if(x <= l && r <= y) {
                    mp[id] = {x, y};
                }
                if(mp.size() > 0) {
                    cout << 1 << el;
                }
                else if(L.size() && R.size()) {
                    u = *max_element(all(L), [](const pair<int, int>& a, const pair<int, int>& b){return a.se < b.se;});
                    v = *max_element(all(R), [](pair<int, int> a, pair<int, int> b){return a.se > b.se;});
                    if(u.se >= v.se) cout << 2 << el;
                    else cout << -1 << el;
                }
                else {
                    cout << -1 << el;
                }
            }
            else {
                if(mp.size() > 0) mp.erase(id);
                if(L.size() > 0) L.erase(id);
                if(R.size() > 0) R.erase(id);
                if(mp.size() > 0) {
                    cout << 1 << el;
                }
                else if(L.size() && R.size()) {
                    pair<int,int> u = *max_element(all(L), [](const pair<int, int>& a, const pair<int, int>& b){return a.se < b.se;});
                    pair<int, int> v = *max_element(all(R), [](pair<int, int> a, pair<int, int> b){return a.se > b.se;});
                    if(u.se >= v.se) cout << 2 << el;
                    else cout << -1 << el;
                }
                else {
                    cout << -1 << el;
                }
            }
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
    cerr << clock() << "ms";
}


