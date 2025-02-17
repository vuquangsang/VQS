#include <bits/stdc++.h>
using namespace std;

const int N = 105;
string s;
int n;
int a[N][N];
int dx[5] = {0, 0, 0, 1, -1};
int dy[5] = {0, 1, -1, 0, 0};
void input()
{
    cin >> n;
    for(int i(1); i <= n; i++) for(int j(1); j<= n; j++) {
        char x;
        cin >> x;
        a[i][j] = x - '0';
    }
    cin >> s;

}

namespace sub_task
{

    const int MAX = 1e5 + 2;
    bitset<N> dp[MAX][N];
    bitset<N> mask[N][19];
    void slv()
    {
        for(int i(1); i <= n; i++) for(int j(1); j <= n; j++) {
            mask[i][a[i][j]][j] = 1;
        }

        int ans = 0, res = s.size();
        s = ' ' + s;
        for(int x(1); x <= n; x++ ) for(int y(1); y <= n; y++ ) {
            if(a[x][y] == s[1] - '0') dp[1][x][y] = 1;
        }

        for(int i(1); i <= res; i++) {
            bool ok = 0;
            for(int x = 1; x <= n; x++ ){
                dp[i][x]|=( (dp[i - 1][x - 1] | dp[i - 1][x + 1] | (dp[i - 1][x] >> 1) | (dp[i - 1][x] << 1))&mask[x][s[i] -'0']);

                if(dp[i][x].count()) ok = 1;
            }
            if(!ok) {
                cout << i - 1;
                return;
            }
        }
        cout << res;
    }
}
namespace sub_task1
{
    bool check_test() {return n <= 10;}
    bool check(int x, int y) {
        return (x >= 1 && x <= n && y >= 1 && y <= n);
    }
    int cal(int x, int y, int d)
    {
        if(d >= s.size()) return 0;
        if(a[x][y] != s[d] - '0') return 0;


        int ans = 0;

        for(int i = 1; i <= 4; i++) {
            int u = dx[i] + x;
            int v = dy[i] + y;
            if(check(u, v)) ans = max(ans, 1 + cal(u, v, d + 1));
        }
        return ans;
    }
    struct node {int x, y;};
    #define pb push_back
    void slv()
    {
        vector<node> id;
        for(int i = 1; i <= n; i++ ) for(int j = 1; j <= n; j++) if(a[i][j] == (s[0] - '0')) {
            id.push_back({i, j});
        }
        int res = 0;
        for(auto t : id) res = max(res, cal(t.x, t.y, 0));
        cout << res;
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    input();
    if(sub_task1::check_test()) return sub_task1::slv(), 0;
    sub_task::slv();
}
