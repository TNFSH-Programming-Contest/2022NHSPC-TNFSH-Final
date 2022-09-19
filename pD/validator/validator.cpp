#include "testlib.h"
#include <bits/stdc++.h>
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define pb push_back
#define ff first
#define ss second
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define lyx ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 2e5, Q = 2e5;

int n, q;
vector<vector<int>> G;

struct DSU
{
    int p[N+1];
    void init()
    {
        rep(i,1,n) p[i] = i;
    }
    int find(int i)
    {
        return (p[i]==i? i:p[i]=find(p[i]));
    }
    void U(int u, int v)
    {
        p[find(u)] = find(v);
    }
} dsu;

int main() {
	registerValidation();

    n = inf.readInt(1,N);
    inf.readSpace();
    q = inf.readInt(1,Q);
    inf.readEoln();

    dsu.init();

    rep(i,2,n)
    {
        int u = inf.readInt(1,n);
        inf.readSpace();
        int v = inf.readInt(1,n);
        inf.readEoln();
        G[u].pb(v);
        G[v].pb(u);
        ensuref(u!=v, "u should no equal to v");

        ensuref(dsu.find(u) == dsu.find(v), "cycle shoudn't exist");
        dsu.U(u,v);
    }

    rep(i,1,q)
    {
        int x = inf.readInt(1,n);
        inf.readSpace();
        int y = inf.readInt(1,n);
        inf.readSpace();
        int z = inf.readInt(1,n);
        inf.readEoln();
    }
	return 0;
}
