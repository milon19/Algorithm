#include<iostream>
#include<cstdio>
#define sz 10000
using namespace std;

int arr[sz+1], st[3*(sz+1)];

void build_st(int node, int b, int e)
{
    if(b == e)
    {
        st[node] = arr[b];
        return;
    }
    int mid = (b+e)/2;
    int l = 2*node;
    int r = l+1;
    build_st(l, b, mid);
    build_st(r, mid+1, e);
    st[node] = st[l]+st[r];
}
int query(int node, int b, int e, int x, int y)
{
    if(b > y || e < x)
        return 0;
    if(b >= x && e <= y)
        return st[node];
    int mid = (b+e)/2;
    int l = node*2;
    int r = l+1;
    int lans = query(l, b, mid, x, y);
    int rans = query(r, mid+1, e, x, y);
    return lans+rans;
}

void update(int node, int b, int e, int pos, int v)
{
    if(b > pos || e < pos)
        return;
    if(b >= pos && e <= pos)
    {
        st[node] = v;
        return;
    }
    int mid = (b+e)/2;
    int l = node*2;
    int r = l+1;
    update(l, b, mid, pos, v);
    update(r, mid+1, e, pos, v);
    st[node] = st[l] + st[r];
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    build_st(1, 1, n);
    int nq;
    scanf("%d", &nq);
    for(int i = 1; i <= nq; i++)
    {
        int ty;
        scanf("%d", &ty);
        if(ty == 1)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            int ans = query(1, 1, n, x, y);
            cout << ans << endl;
        }
        else
        {
            int pos, value;
            scanf("%d %d", &pos, &value);
            update(1, 1, n, pos, value);
        }
    }
    return 0;
}
