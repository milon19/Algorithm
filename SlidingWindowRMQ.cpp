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

vector<int> slidingWindow(int arr[], int n, int k)
{
    deque<int> Q;
    int i;
    vector<int> vt;
    for(i = 0; i < k; i++)
    {
        while(!Q.empty() && arr[i] >= arr[Q.back()])
            Q.pop_back();
        Q.pb(i);
    }
    for( ; i < n; i++)
    {
        vt.pb(arr[Q.front()]);
        while(!Q.empty() && Q.front() <= i-k)
            Q.pop_front();
        while(!Q.empty() && arr[i] >= arr[Q.back()])
            Q.pop_back();
        Q.push_back(i);
    }
    vt.pb(arr[Q.front()]);
    return vt;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    #ifdef file_io
        freopen("in.txt", "rt", stdin);
        freopen("out.txt", "wt", stdout);
    #endif

    int tc, cs = 1;
    cin >> tc;
    while(tc--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        vector <int> vt = slidingWindow(arr, n, k);
        printf("Case %d:", cs++);
        for(int i = 0; i < vt.size(); i++)
            cout << " " <<  vt[i];
        cout << endl;
    }
    return 0;
}
