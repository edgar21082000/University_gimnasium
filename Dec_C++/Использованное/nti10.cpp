#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
 
using namespace std;
 
#define p_b push_back
 
void dfs(int, int);
 
const int NMAX1 = 300100;
 
vector <pair<int, int> > a[NMAX1];
vector <int> brg;
int t_in[NMAX1], up[NMAX1], timer;
bool used[NMAX1];
pair<int, int> g[NMAX1];
vector <pair<int, int> > dlt;
 
 
int main()
{
    int n, m, i, j, x, y, cnt = 0, q, c, lb;
 
    cin >> n >> m;
 
    for (i = 0; i < m; i++)
    {
        cin >> x >> y;
 
        x--;
        y--;
        g[i].first = x;
        g[i].second = y;
 
        a[x].p_b(make_pair(y, i));
        a[y].p_b(make_pair(x, i));
    }
 
    cin >> q;
 
    for(i = 0; i < n; i++)
        if (!used[i])
            dfs(i, -1);
 
 
    for (i = 0; i < m; i++)
        if (t_in[g[i].first] < up[g[i].second] || t_in[g[i].second] < up[g[i].first])
            brg.p_b(i + 1);
 
    sort(brg.begin(), brg.end());
 
    for (i = 0; i < q; i++)
    {
        cin >> c;
 
        lb = lower_bound(brg.begin(), brg.end(), c);
 
        if (brg[lb] == c)
        {
            cout << cnt++ << ' ';
            continue;
        }
        else
            cout << cnt << ' ';
 
        dlt.p_b(make_pair(g[c].first, g[c].second));
        sort(dlt.begin(), dlt.end());
 
        for(j = 0; j < n; j++)
            used[j] = false;
 
        for(j = 0; j < n; j++)
            if (!used[j])
                dfs(j, -1);
 
 
        for (j = 0; j < m; j++)
            if (t_in[g[j].first] < up[g[j].second] || t_in[g[j].second] < up[g[j].first])
                brg.p_b(j + 1);
 
        sort(brg.begin(), brg.end());
    }
 
    return 0;
}
 
 
void dfs(int v, int pred)
{
    used[v] = true;
    t_in[v] = timer++;
    up[v] = t_in[v];
 
    for (int i = 0; i < (int) a[v].size(); i++)
    {
        int u = a[v][i].first;
 
        if (!used[u] && (dlt[lower_bound(dlt.begin(), dlt.end(), (v, u))] || dlt[lower_bound(dlt.begin(), dlt.end(), (u, v))])
        {
            dfs(u, a[v][i].second);
            up[v] =  min(up[v], up[u]);
        }
        else if (pred != a[v][i].second)
            up[v] = min(up[v], t_in[u]);
    }
}
