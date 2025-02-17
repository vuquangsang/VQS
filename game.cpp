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

vector<vector<char>> a;
vector<vector<int>> L, R, T, B, dist;
vector<vector<bool>> block;
int n, m, k;
node S, G;
const int N = 1e6 + 2;
set<int> rows[N], cols[N];
bool ac = 0;
void input()
{
    cin >> n >> m >> k;
    a.resize(n + 5, vector<char>(m + 5));
    L.resize(n + 5, vector<int>(m + 5));
    R.resize(n + 5, vector<int>(m + 5));
    T.resize(n + 5, vector<int>(m + 5));
    B.resize(n + 5, vector<int>(m + 5));
    dist.resize(n + 2, vector<int>(m + 5, 0));
    block.resize(n + 2, vector<bool>(m + 2, 0));

    fr(i, 1, n) fr(j, 1, m) {
        cin >> a[i][j];
        if(a[i][j] == 'S') S = {i, j};
        if(a[i][j] == 'G') G = {i, j};
        block[i][j] = (a[i][j] == '#' ? 1 : 0);
        if(a[i][j] == '#') ac = 1;
    }

}
namespace sub1
{
    void mark(int x, int y)
    {
        rows[x].erase(y);
        cols[y].erase(x);
    }
    void slv()
    {
        fr(i, 1, n) fr(j, 1, m) {
            T[i][j] = (i == 1 || block[i - 1][j]) ? i : T[i - 1][j];
            L[i][j] = (j == 1 || block[i][j - 1]) ? j : L[i][j - 1];
        }
        frd(i, n, 1) frd(j, m, 1) {
            B[i][j] = (i == n || block[i + 1][j]) ? i : B[i + 1][j];
            R[i][j] = (j == m || block[i][j + 1]) ? j : R[i][j + 1];
        }

		fr(i, 1, n) cols[1].insert(i) ;
		fr(i, 1, m) rows[1].insert(i) ;

		fr(i, 2, m) cols[i] = cols[1] ;
		fr(i, 2, n) rows[i] = rows[1] ;




        mark(S.x, S.y);
        dist[S.x][S.y] = 0;
        queue<node> q;
        q.push({S.x, S.y});
        while(!q.empty()) {
            int x = q.front().x;
            int y = q.front().y;
            q.pop();

            int limL = max(L[x][y], y - k), limR = min(R[x][y], y + k);
            while(true) {
                auto it = rows[x].lower_bound(limL);
                if(it == rows[x].end() || *it > limR) break;
                dist[x][*it] = dist[x][y] + 1;
                limL = *it;
                q.push({x, *it});
                mark(x, *it);

            }
            limL = max(T[x][y], x - k);
            limR = min(B[x][y], x + k);
            while(true) {
                auto it = cols[y].lower_bound(limL);
                if(it == cols[y].end() || *it > limR) break;
                dist[*it][y] = dist[x][y] + 1;
                limL = *it;
                q.push({*it, y});
                mark(*it, y);
            }
        }
        cout << dist[G.x][G.y];
    }
}
namespace sub2
{
    bool check()
    {
        return !ac;
    }
    void slv()
    {
        cout << abs(G.x - S.x)/k + (abs(G.x - S.x)%k != 0) + (abs(G.y - S.y)/k) + (abs(G.y - S.y)%k != 0);
    }
}

main()
{
    #define TASK "task"
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    if( fopen( TASK".INP", "r") ){
        freopen( TASK".INP", "r", stdin);
        freopen( TASK".ANS", "w", stdout);
    }
    bool qs = 0;
    ll mtt = 1;
    if(qs) cin >> mtt;
    fr(i, 1, mtt){
        input();
        if(sub2::check()) return sub2::slv(), 0;
        sub1::slv();
    //    sub2::slv();
    }
}


