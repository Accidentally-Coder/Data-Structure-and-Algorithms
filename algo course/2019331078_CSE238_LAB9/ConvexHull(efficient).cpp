#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x,y;
};

Point p0;

int orientation(Point p, Point q, Point r) {
    // 0-> collinear, 1-> clockwise, -1-> anti-clockwise
    int slope = (q.y - p.y)*(r.x - q.x) - (q.x - p.x)*(r.y - q.y);
    if(slope == 0)return 0;
    else if(slope > 0) return 1;
    else return -1;
}

int dis(Point a, Point b) {
    return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

int cmp(const void *p1, const void *p2) {
    Point *x = (Point*)p1;
    Point *y = (Point*)p2;

    int s = orientation(p0,*x,*y);
    if(s == 0) {
        //when same angle, the one farthest from p0 to be taken
        if (dis(p0,*y) >= dis(p0,*x))
            return -1;
        else return 1;
    }
    if(s == -1) return -1;
    else return 1;
}

Point nextTop(stack<Point> &s) {
    Point p = s.top();
    s.pop();
    Point ans = s.top();
    s.push(p);
    return ans;
}

void convexHull(Point pnt[], int n) {
    int min_y = pnt[0].y, mn = 0;

    for(int i = 1; i < n; i++) {
        int y = pnt[i].y;

        if(y < min_y) min_y = y, mn = i;
        else if(y==min_y && pnt[i].x<pnt[mn].x)
            min_y = pnt[i].y, mn = i;
    }

    swap(pnt[0],pnt[mn]);

    p0 = pnt[0];
    qsort(&pnt[1],n-1,sizeof(Point),cmp);

    int m = 1;
    for(int i = 1; i < n; i++) {
        while(i < n-1 && orientation(p0,pnt[i],pnt[i+1]) == 0)
            i++;
        pnt[m++] = pnt[i];
    }
    if(m < 3) return;

    stack<Point> s;
    s.push(pnt[0]);
    s.push(pnt[1]);
    s.push(pnt[2]);

    for(int i = 3; i < m; i++) {
        while(s.size()>1 && orientation(nextTop(s),s.top(),pnt[i]) != -1)
            s.pop();
        s.push(pnt[i]);
    }
    while(!s.empty()) {
        Point p = s.top();
        cout << "(" << p.x << ", " << p.y << ") ";
        s.pop();
    }

}

int main() {
    int n;
    while(cin >> n) {
        Point pnt[n+5];
        for(int i = 0; i < n; i++) {
            int a,b; cin >> a >> b;
            pnt[i] = {a,b};
        }
        convexHull(pnt,n);
    }
}


/**
Test Case :

8
7 7
7 -7
-7 -7
-7 7
9 0
-9 0
0 9
0 -9

16
7 7
7 -7
-7 -7
-7 7
9 0
-9 0
0 9
0 -9
0 0
1 2
-2 1
-1 -1
3 4
4 3
-5 4
6 5


72
0 0 1 2 -2 1 -1 -1 3 4 4 3 -5 4 6 5 7 7 7 -7 -7 -7 -7 7 9 0 -9 0 0 9 0 -9 -8 0 8 0 -7 0 7 0 -6 0 6 0 -5 0 5 0 -4 0 4 0 -3 0 3 0 -2 0 2 0 -1 0 1 0 0 -8 0 8 0 -7 0 7 0 -6 0 6 0 -5 0 5 0 -4 0 4 0 -3 0 3 0 -2 0 2 0 -1 0 1 1 1 2 2 3 3 4 4 5 5 6 6 1 -1 2 -2 3 -3 4 -4 5 -5 6 -6 -1 1 -2 2 -3 3 -4 4 -5 5 -6 6 -1 -1 -2 -2 -3 -3 -4 -4 -5 -5 -6 -6


*/
