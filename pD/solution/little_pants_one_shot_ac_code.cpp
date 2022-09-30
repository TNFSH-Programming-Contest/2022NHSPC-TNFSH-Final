#include<bits/stdc++.h>
#define loli
using namespace std;
typedef long long ll;
#define int ll
#define pii pair<int, int>
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define push emplace
#define lb(x, v) lower_bound(ALL(x), v)
#define ub(x, v) upper_bound(ALL(x), v)
#define re(x) reverse(ALL(x))
#define uni(x) x.resize(unique(ALL(x)) - x.begin())
#define inf 1000000000
#define INF 1000000000000000000
#define mod 1000000007
#define get_bit(x, y) ((x>>y)&1)
#define mkp make_pair
#define IO ios_base::sync_with_stdio(0); cin.tie(0);
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cout << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    for (; l != r; ++l) cout << *l << " \n"[l + 1 == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    if (a.empty()) return o << "{}";
    for (T i : a) {o << (is ? ' ' : '{'), is = true, o << i;}
    return o << '}';
}
#ifdef loli
#define test(args...) abc("[" + string(#args) + "]", args)
#else
#define test(args...) void(0)
#endif
const int mxN = 2e6 + 5;

int n, q;
// LCA binary jump
int up[mxN][25], dep[mxN], sz[mxN];
const int mxL = 20;
vector<int> g[mxN];

void dfs(int u, int p = -1) {
    if (p != -1) up[u][0] = p;
    sz[u] = 1;

    for (int i = 1; (1<<i) <= dep[u]; i++) {
        up[u][i] = up[up[u][i-1]][i-1];
    }

    for (int v : g[u]) {
        if (v == p) continue;
        dep[v] = dep[u] + 1;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

inline int lca(int u, int v) {
    if (u == v) return u;
    if (dep[u] < dep[v]) swap(u, v);

    for (int i = mxL; i >= 0; i--) {
        if (up[u][i] and dep[up[u][i]] >= dep[v]) {
            u = up[u][i];
        }
    }

    if (u == v) return u;

    for (int i = mxL; i >= 0; i--) {
        if (up[u][i] and up[v][i] and up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }

    return up[u][0];
}

int jump(int u, int k) {
    if (k == 0) return u;
    for (int i = mxL; i >= 0; i--) if (get_bit(k, i)) u = up[u][i];
    return u;
}

inline void solve() {
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].eb(b);
        g[b].eb(a);
    }
    int rt = 1;
    for (int i = 2; i <= n; i++) if (SZ(g[rt]) < SZ(g[i])) rt = i;
    dfs(rt);

    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        int ans = 0, l = lca(x, y);
        if (l == z) {
            ans = sz[rt];
            if (x != z) ans -= sz[jump(x, dep[x] - dep[z] - 1)];
            if (y != z) ans -= sz[jump(y, dep[y] - dep[z] - 1)];
        }
        else if (dep[z] >= dep[l] and lca(x, z) == z) {
            ans = sz[z] - sz[jump(x, dep[x] - dep[z] - 1)];
        }
        else if (dep[z] >= dep[l] and lca(y, z) == z) {
            ans = sz[z] - sz[jump(y, dep[y] - dep[z] - 1)];
        }
        else ans = 0;
        cout << ans << '\n';
    }
}

signed main() {
    IO;
    solve();
}
