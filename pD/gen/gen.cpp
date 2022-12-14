#include <bits/stdc++.h>
#include "testlib.h"
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define pb push_back
#define ff first
#define ss second
#define de(x) cerr << #x << '=' << x << ", "
#define dd cout << '\n';
#define lyx ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 5e5+10, LG = __lg(N)+5;

int maxN;
int maxQ;
int isChain;
int isStar;

int n, q;
vector<pair<pii,int>> queries;
vector<vector<int>> G(N);
vector<pii> edgs;

struct GenTree
{
    void genStar()
    {
        int rt = rnd.next(1LL, n);
        rep(i,1,n)
            if (i != rt)
                G[i].pb(rt), G[rt].pb(i), edgs.pb({i,rt});
    }
    void genChain()
    {
        vector<int> v;
        rep(i,1,n) v.pb(i);
        shuffle(v.begin(), v.end());
        for (int i=1; i<v.size(); i++)
            G[v[i]].pb(v[i-1]), G[v[i-1]].pb(v[i]), edgs.pb({v[i], v[i-1]});
    }
    void genTree()
    {
        vector<int> v;
        rep(i,1,n) v.pb(i);
        shuffle(v.begin(), v.end());
        for (int i=1; i<v.size(); i++)
        {
            int x = v[i], y = v[rnd.next(0LL,i-1)];
            G[x].pb(y);
            G[y].pb(x);
            edgs.pb({x,y});
        }
    }
} gt;

struct LCA
{
    int p[LG][N], dep[N];

    void build(int u)
    {
        for (int i=1; i<LG; i++)
            p[i][u] = p[i-1][p[i-1][u]];
        for (auto v: G[u])
            if (v != p[0][u])
                p[0][v] = u, dep[v] = dep[u]+1, build(v);
    }
    int lca (int x, int y)
    {
        if (dep[x] < dep[y]) swap(x,y); // x deeper
        for (int t=dep[x]-dep[y],j=0; t; t>>=1,j++)
            if (t&1) x = p[j][x];

        if (x == y) return x;

        for (int s=LG-1; s>=0; s--)
        {
            if (p[s][x] == p[s][y]);
            else x = p[s][x], y = p[s][y];
        }
        return p[0][x];
    }
} lca;

void gen_anc_pair(int &fa, int &u)
{
    u = fa = rnd.next(1LL, n);
    int gap = rnd.next(0LL,lca.dep[u]);
    for (int t=gap,j=0; t; t>>=1,j++)
        if (t&1)
            fa = lca.p[j][fa];
}

int rnd_choose_from_path(int fa, int u) // x
{
    int gap = rnd.next(0LL, lca.dep[u]-lca.dep[fa]);
    for (int t=gap,j=0; t; t>>=1,j++)
        if (t&1)
            u = lca.p[j][u];
    return u;
}


signed main(signed argc, char* argv[]) {
	registerGen(argc, argv, 1);

    maxN = atoll(argv[1]);
    maxQ = atoll(argv[2]);
    isChain = atoll(argv[3]);
    isStar = atoll(argv[4]);

    n = rnd.wnext(1LL, maxN, 5);
    q = rnd.wnext(1LL, maxQ, 5);

    if (isChain)
    {
        gt.genChain();
    }
    else if (isStar)
    {
        gt.genStar();
    }
    else
    {
        gt.genTree();
    }

    lca.build(1);

    rep(i,1,q)
    {
        int x, y, z;

        int anc_ratio = 30;
        if (rnd.next(1,100) <= anc_ratio)
            gen_anc_pair(x,y);
        else
            x = rnd.next(1LL, n), y = rnd.next(1LL, n);

        int z_is_l_ratio = 40;
        int z_on_path_ratio = 40;
        int mode = rnd.next(1,100);
        int l = lca.lca(x,y);

        if (mode <= z_is_l_ratio)
            z = l;
        else if (mode <= z_is_l_ratio + z_on_path_ratio)
            z = rnd_choose_from_path(l, x);
        else
            z = rnd.next(1LL, n);
        queries.pb({{x,y},z});
    }

    cout << n << ' ' << q << '\n';
    shuffle(edgs.begin(), edgs.end());
    for (auto &e: edgs) if (rnd.next(0,1)) swap(e.ff, e.ss);
    for (auto e: edgs) cout << e.ff << ' ' << e.ss << '\n';
    for (auto y: queries) cout << y.ff.ff << ' ' << y.ff.ss << ' ' << y.ss << '\n';
}
