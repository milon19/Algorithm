/*
//http://www.shafaetsplanet.com/planetcoding/?p=973
input:
    1
    7 8
    1 2
    2 3
    3 1
    3 4
    4 5
    5 6
    6 7
    7 5
output:
    3
    1 1 3 2
    2 4
    3 5 7 6
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<climits>
#include<queue>
#include<stack>

#define pb                  push_back
#define m_p                 make_pair
#define ALL(x)              x.begin(), x.end()
#define unq(x)              (x).resize(unique(ALL(x)) - x.begin())
#define db(x)               printf("%d\n", x)
#define newL                printf("\n")

using namespace std;

typedef pair<int, int>      pii;
typedef long long           ll;

vector<int> G[100005];
vector<int> R[100005];
vector<int> comp[100005];
bool vis[100005];
bool vis2[100005];
int cc[100005];
stack<int>stk;

void top_sort(int x)
{
    vis[x] = 1;
    for(int i = 0; i < G[x].size(); i++)
    {
        int y = G[x][i];
        if(!vis[y]) top_sort(y);
    }stk.push(x);
    return;
}

void strongly(int x, int mark)
{
    vis2[x] = 1;
    comp[mark].pb(x);
    cc[x] = mark;
    for(int i = 0; i < R[x].size(); i++)
    {
        int y = R[x][i];
        if(!vis2[y]) strongly(y, mark);
    }return;
}

int main()
{
    int tc;
    scanf("%d", &tc);
    while(tc--)
    {
        for(int i = 0; i < 100005; i++)
        {
            G[i].clear(), R[i].clear(), comp[i].clear();
            vis[i] = 0, vis2[i] = 0, cc[i] = -1;
        }
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= m; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            G[u].pb(v);
            R[v].pb(u);
        }
        for(int i = 1; i <= n; i++)
            if(!vis[i]) top_sort(i);

        int mark = 0;
        while(!stk.empty())
        {
            int u = stk.top();

            stk.pop();
            if(!vis2[u])
            {
                mark++;
                strongly(u, mark);
            }
        }
        cout << mark << endl;
        for(int i = 1; i <= mark; i++)
        {
            cout << i;
            for(int j = 0; j < comp[i].size(); j++)
            {
                cout << " " << comp[i][j];
            }
            newL;
        }
    }

    return 0;
}
