#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

const int maxn = 200;
const long long maxc = 1000000000;
int n, P;
long long c[maxn + 1];
long long d[maxn + 1][maxn + 1];
bool a[maxn + 1][maxn + 1];
int trace[maxn + 1][maxn + 1];
#define fi cin
#define fo cout
void visit(int u) {
    d[u][1] = c[u];
    for (int v = 1; v <= n; v++) {
        if (a[u][v]) {
            a[v][u] = false;
            visit(v);
            for (int i = P; i >= 1; i--) {
                for (int j = 1; j < i; j++) {
                    if (d[u][i] < d[u][j] + d[v][i - j]) {
                        d[u][i] = d[u][j] + d[v][i - j];
                        trace[v][i] = i - j;
                    }
                }
            }
        }
    }
}

void truy_vet(int u, int P) {
    for (int v = n; v >= 1; v--) {
        if (a[u][v] && (trace[v][P] > 0)) {
            truy_vet(v, trace[v][P]);
            P -= trace[v][P];
        }
    }
    cout << u << ' ';
}

void process() {
    visit(1);
    int vt = 1;
    for (int u = 2; u <= n; u++) {
        if (d[u][P] > d[vt][P]) {
            vt = u;
        }
    }
    truy_vet(vt, P);
}

void init() {
    for (int u = 1; u <= n; u++) {
        fill(d[u], d[u] + maxn + 1, -maxc);
    }
}

void nhapdl() {
    fi >> n >> P;
    for (int i = 1; i <= n; i++) {
        fi >> c[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        fi >> u >> v;
        a[u][v] = true;
        a[v][u] = true;
    }
}

int main() {
    nhapdl();
    init();
    process();
    return 0;
}
