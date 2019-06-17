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

#define pb      push_back
#define m_p     make_pair
#define ALL(x)  x.begin(), x.end()
#define unq(x)  (x).resize(unique(ALL(x)) - x.begin())
#define db(x)   printf("%d\n", x)


using namespace std;
typedef pair<int, int>  pii;
typedef long long       ll;

int n; // Number of members in set
int p[100];
findPar(int u)
{
    if(p[u] == u)
        return u;
    p[u] = findPar(p[u]);
    return p[u];
}

void makeUnion(int u, int v)
{
    int pU = findPar(u);
    int pV = findPar(v);
    if(pU == pV)
        printf("They are already friends\n");
    else
        p[pU] = pV;
}

void isfriend(int u, int v)
{
    if(findPar(u) == findPar(v))
        printf("Friends\n");
    else
        printf("Not Friends\n");
}
int main()
{
    int tc;
    scanf("%d", &tc);
    while(tc--)
    {

        scanf("%d", &n);

        //Make Set, Initially Each set is representative of own.
        for(int i = 0; i < n; i++)
            p[i] = i;
        int q; //Number of query to make two member friend;
        scanf("%d", &q);
        for(int i = 1; i <= q; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            makeUnion(u, v); // making u, v friends
        }
        int a, b;
        scanf("%d %d", &a, &b);
        isfriend(a, b);
    }
    return 0;
}

