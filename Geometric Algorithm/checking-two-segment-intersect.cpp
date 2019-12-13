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

struct Point
{
    int x, y;
};

bool onSegment(Point p, Point q, Point r)
{
    if(q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
       q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
    return false;
}

int orientation(Point p, Point q, Point r)
{
    int ans = (p.x*q.y + q.x*r.y + r.x*p.y)-
              (q.x*p.x + r.x*q.y + p.x*r.y);
    if(ans == 0) return 0; //co linear
    return (ans > 0) ? 1 : 2; // clockwise or counter clockwise
}

bool isIntersect(Point p1, Point q1, Point p2, Point q2)
{
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    //General Case
    if(o1 != o2 && o3 != o4) return true;
    //Special Cases
    if(o1 == 0 && onSegment(p1, p2, q1)) return true;
    if(o2 == 0 && onSegment(p1, q2, q1)) return true;
    if(o3 == 0 && onSegment(p2, p1, q2)) return true;
    if(o4 == 0 && onSegment(p2, q1, q2)) return true;
    return false;

}
int main()
{
    Point p1, q1, p2, q2;
    scanf("%d %d %d %d", &p1.x, &p1.y, &q1.x, &q1.y);
    scanf("%d %d %d %d", &p2.x, &p2.y, &q2.x, &q2.y);
    if(isIntersect(p1, q1, p2, q2))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
