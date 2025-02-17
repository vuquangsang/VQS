#include <bits/stdc++.h>
using namespace std;
#define     pb push_back
#define     ll long long)
#define     fr(i,a,b) for(int i = (a), _b = (b); i <= _b; i++)
#define     frd(i,a,b) for(int i = (a), _b = (b); i >= _b; i--)
const int MAX = 1e5 + 2;
int n, m;
vector<int> g[MAX];
void input()
{
    cin >> n >> m;
    fr(i, 1, m) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
}
int dd[MAX];
void BFS(int u)
{
    queue<int> q;
    q.push(u);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        dd[u] = 1;
        for(int v : g[u]) if(!dd[v]) {
            q.push(v);
        }
    }
}
void slv()
{
    int res = 0;
    fr(i, 1, n) {
        if(!dd[i]) {
            res++;
            BFS(i);
        }
    }
    cout << res;
}

main()
{
    input();
    slv();
}


