/*
    Problem : LightOJ-1083 - Histogram
    http://lightoj.com/volume_showproblem.php?problem=1083
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

#define pb      push_back
#define m_p     make_pair
#define ALL(x)  x.begin(), x.end()
#define unq(x)  (x).resize(unique(ALL(x)) - x.begin())
#define db(x)   printf("%d\n", x)


using namespace std;
typedef pair<int, int>  pii;
typedef long long       ll;


int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, 1, -1, -1, 1};
int mx = INT_MIN;
int mn = INT_MAX;

bool cmp(pii f, pii s){
    if(f.first > s.first) return 0;
    if(f.first == s.first){
        if(f.second > s.second) return 0;
        else return 1;
    }else return 1;
}

int calArea(int *hist, int n)
{
    int i = 0;
    int max_area = -1;
    int cur_area, tp;
    stack< int > s;
    while(i < n)
    {
        if(s.empty() || hist[s.top()] <= hist[i])
            s.push(i++);
        else
        {
            tp = s.top();
            s.pop();
            cur_area = hist[tp] * (s.empty() ? i : i-s.top()-1);
            max_area = max(max_area, cur_area);
        }
    }
    while(!s.empty())
    {
        tp = s.top();
        s.pop();
        cur_area = hist[tp] * (s.empty() ? i : i-s.top()-1);
        max_area = max(max_area, cur_area);
    }
    return max_area;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    #ifdef file_io
        freopen("in.txt", "rt", stdin);
        freopen("out.txt", "wt", stdout);
    #endif
    int tc, cs = 1;
    scanf("%d", &tc);
    while(tc--)
    {
        int n;
        scanf("%d", &n);
        int arr[n];
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        int max_area = calArea(arr, n);
        printf("Case %d: %d\n", cs++, max_area);
    }
    return 0;
}
