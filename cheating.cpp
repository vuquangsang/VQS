/* Vu Quang Sang from Le Khiet High School for Gifted */
#include <bits/stdc++.h>
using namespace std;

//#define   ll int
#define     lg(x) __lg(x)
#define     alla(a,n) a+1,a+n+1
#define     el "\n"
#define     all(x) x.begin(),x.end()
#define     pb push_back
#define     ll int
#define     fi first
#define     se second
#define     Mask(i) (1ll<<(i))
#define     c_bit(i) __builtin_popcountll(i)
#define     fr(i,a,b) for(int i = (a), _b = (b); i <= _b; i++)
#define     frd(i,a,b) for(int i = (a), _b = (b); i >= _b; i--)
#define     REP(i, a, b) for(int i = (a), _b = (b); i < _b; i++)


struct job
{
    ll  dif, id;
    bool operator <(job const&a) const
    {
        return (dif >  a.dif);
    }
};
struct stu
{
    ll abi, cost, id;
    bool operator <(stu const&a) const
    {
        return (abi > a.abi);
    }
};
#define MAX 300300
job a[MAX];
stu b[MAX];
int n, m, fix[MAX], s;
void input()
{
    cin >> n >> m >> s;
    fr(i, 1, m) cin >> a[i].dif, a[i].id = i;
    fr(i, 1, n) cin >> b[i].abi;
    fr(i, 1, n) cin >> b[i].cost, b[i].id = i;
    sort(a + 1, a + m + 1);
    sort(b + 1, b + n + 1);
}

    struct comp
    {
        bool operator()(const stu&a, const stu&b) const
        {
            return (a.cost > b.cost);
        }
    };
    priority_queue<stu, vector<stu>, comp> q;
    bool check(int x)
    {
        while(!q.empty()) q.pop();
        long long all = 0;
        ll time = 1;
        memset(fix, -1, sizeof fix);
        fr(i, 1, m) if(fix[a[i].id] < 0) { //not yet choose
            while(time <= n && b[time].abi >= a[i].dif) {
                q.push(b[time]);
                time++;
            }
            if(q.empty()) return 0;
            stu tmp = q.top(); q.pop();
            all+=tmp.cost;
            if(all > s) return 0;
            REP(j, 0, x) if(i + j <= m) fix[a[i + j].id] = tmp.id; // trace people do homework
        }
        return all <= s;
    }

    void slv()
    {
        int l = 1, r = n, mid, pos;
        if(!check(r)) {
            cout << "NO" << el << el;
            return;
        }
        while(l <= r) {
            mid = (r + l) >> 1;
            if(check(mid)) pos = mid, r = mid - 1;
            else l = mid + 1;
        }
        check(pos);
        cout << "YES" << el;
        fr(i, 1, m) {
            cout << fix[i] << " ";
        } cout << el;
    }

main()
{
    #define TASK "cheating"
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    if( fopen( TASK".INP", "r") ){
        freopen( TASK".INP", "r", stdin);
        freopen( TASK".OUT", "w", stdout);
    }
    bool qs = 1;
    short subtask; cin >> subtask;
    ll mtt = 1;
    if(qs) cin >> mtt;
    fr(i, 1, mtt){
        input();
        slv();
    //    sub2::slv();
    }
    cerr << clock() << "ms" << el;
}


