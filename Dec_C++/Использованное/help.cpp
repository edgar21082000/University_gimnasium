#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
 
using namespace std;
 
#define p_b push_back
 
void dfs(int, int);
int bp(int *, int, int);
 
const int NMAX1 = 300100;
 
vector <pair<int, int> > a[NMAX1];
bool used[NMAX1];
int dlt[NMAX1], dl;
 
int main()
{
    int n, m, i, j, x, y, q, c, cnt;
 
    cin >> n >> m;
 
    for (i = 0; i < m; i++)
    {
        cin >> x >> y;
 
        x--;
        y--;
 
        a[x].p_b(make_pair(y, i));
        a[y].p_b(make_pair(x, i));
    }
 
    cin >> q;
 
    for (i = 0; i < q; i++)
    {
        cin >> c;
 
        dlt[dl] = c - 1;
        dl++;
        sort(dlt, dlt + dl);
 
        for(j = 0; j < n; j++)
            used[j] = false;
 
        cnt = 0;
 
        for(j = 0; j < n; j++)
            if (!used[j])
            {
                cnt++;
                dfs(j, -1);
            }
        cout << cnt << ' ';
 
    }
 
    return 0;
}
 
 
void dfs(int v, int pred)
{
    used[v] = true;
 
    for (int i = 0; i < (int) a[v].size(); i++)
    {
        int u = a[v][i].first;
 
        if (!used[u] && !(dlt[bp(dlt, dl, a[v][i].second)] == a[v][i].second))
            dfs(u, a[v][i].second);
    }
}
 
 
int bp(int *ms, int n, int x)
{
    int lft = 0, rht = n, mid;
 
    while (lft + 1 < rht)
    {
        mid = (lft + rht) / 2;
 
        if (ms[mid] > x)
            rht = mid;
        else
            lft = mid;
    }
 
    return lft;
}
