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

const int N = 1e5+5;

struct tree
{
    int sum;
    int prop;
    tree(){}
    tree(int a, int b)
    {
        sum = a;
        prop = b;
    }

};
int arr[N];
tree st[3*N];


void build_st(int node, int b, int e)
{
    if(b == e)
    {
        st[node] = tree(arr[b], 0);
        return;
    }
    int mid = b + (e-b)/2;
    int l = 2*node;
    int r = l+1;
    build_st(l, b, mid);
    build_st(r, mid+1, e);
    st[node] = tree(st[l].sum + st[r].sum, 0);
}

void update(int node, int b, int e, int x, int y, int v)
{
    if(e < x || y < b)
        return;
    if(x <= b && e <= y)
    {
        st[node].sum += ((e - b + 1) * v);
        st[node].prop += v;
        return;
    }
    int mid = b + (e-b)/2;
    int l = node * 2;
    int r = l + 1;
    update(l, b, mid, x, y, v);
    update(r, mid+1, e, x, y, v);
    st[node].sum = st[l].sum + st[r].sum + (e - b + 1)*st[node].prop;
}

int query(int node, int b, int e, int x, int y, int carry = 0)
{
    if(e < x || y < b)
        return 0;
    if(x <= b && e <= y)
        return st[node].sum + carry * (e-b+1);
    int mid = b + (e-b)/2;
    int l = node*2;
    int r = l+1;
    int p1 = query(l, b, mid, x, y, carry + st[node].prop);
    int p2 = query(r, mid+1, e, x, y, carry + st[node].prop);
    return p1+p2;

}
int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n, q;
        cin >> n >> q;
        for(int i = 1; i <= n; i++)
            cin >> arr[i];
        build_st(1, 1, n);
        for(int i = 1; i <= q; i++)
        {
            int tm;
            cin >> tm;
            if(tm == 1)
            {
                int x, y, v;
                cin >> x >> y >> v;
                update(1, 1, n, x, y, v);
            }
            else
            {
                int x, y;
                cin >> x >> y;
                cout << query(1, 1, n, x, y, 0) << endl;
            }
        }
    }

    return 0;
}

