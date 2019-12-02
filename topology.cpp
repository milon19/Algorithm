//UVa -> 11504 - Dominos

#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
bool vis[100005];
stack<int>stk;

void dfs(int x)
{
    vis[x] = 1;
    for(int i = 0; i < adj[x].size(); i++)
    {
        int y = adj[x][i];
        if(!vis[y])
            dfs(y);
    }
    stk.push(x);
    return;
}

void dfs1(int x)
{
    vis[x] = 1;
    for(int i = 0; i < adj[x].size(); i++)
    {
        int y = adj[x][i];
        if(!vis[y])
            dfs(y);
    }
    return;
}
int main()
{
    int tc;
    scanf("%d", &tc);
    while(tc--)
    {

        for(int i = 0; i < 100005; i++)
            vis[i] = false, adj[i].clear();
        int v, e;
        scanf("%d %d", &v, &e);
        for(int i = 1; i <= e; i++)
        {
            int p, q;
            scanf("%d %d", &p, &q);
            adj[p].push_back(q);
        }
        for(int i = 1; i <= v; i++)
        {
            if(!vis[i])
                dfs(i);
        }
        for(int i = 0; i < 100005; i++)
            vis[i] = false;
        int cnt = 0;
        while(!stk.empty())
        {
            int top = stk.top();
            if(!vis[top])
            {
                dfs1(top);
                cnt++;
            }
            stk.pop();
        }
        cout << cnt << endl;
    }
    return 0;
}
