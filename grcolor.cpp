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

    const int N = 1e5 + 2;
    int n, m;
    vector<int> g[N];
    void input()
    {
        cin >> n >> m;
        fr(i, 1, m) {
            int u, v;
            cin >> u >> v;
            g[u].pb(v);
            g[v].pb(u);
        }
    }
    namespace sub1
    {
        struct eg
        {
            int u, w;
            bool operator <(eg const&a) const
            {
                return w > a.w;
            }
        };
        int color[N];
        bool dd[N];
        void calc(int u, int d, int c)
        {
            memset(dd, 0, sizeof dd);
            queue<eg> q;
            q.push({u, 0});
            while(!q.empty()) {
                int u = q.front().u;
                int w = q.front().w;
                if(w <= d) color[u] = c;
                q.pop();
                if(dd[u]) continue;
                dd[u] = 1;
                for(int v : g[u]) {
                    if(!dd[v]) {
                        q.push({v, w + 1});
                    }
                }
            }
        }

        void slv()
        {
            int q;
            cin >> q;
            while(q--) {
                int u, d, c;
                cin >> u >> d >> c;
                calc(u, d, c);
            }
            fr(i, 1, n) cout << color[i] << el;
        }
    }
    namespace sub2
    {
        int V[N], D[N], C[N];
        bool memo[N][15];
        int color[N];
        void DFS(int u, int d, int c)
        {
            if(d < 0 || memo[u][d]) return;
            memo[u][d] = 1;
            if(!color[u]) {
                color[u] = c;
            }
            for(int v : g[u]) {
                DFS(v, d - 1, c);
            }
        }
        void slv()
        {
            int q;
            cin >> q;
            fr(i, 1, q) cin >> V[i] >> D[i] >> C[i];

            frd(i, q, 1) {
                DFS(V[i], D[i], C[i]);
            }

            fr(i, 1, n) cout << color[i] << el;
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
            sub2::slv();
        //    sub2::slv();
        }
    }


