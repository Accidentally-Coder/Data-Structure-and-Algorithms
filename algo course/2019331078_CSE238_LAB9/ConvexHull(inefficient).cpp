#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Point {
    int x,y;
};

int orientation(Point p, Point q, Point r) {
    // 0-> collinear, 1-> clockwise, -1-> anti-clockwise
    int slope = (q.y - p.y)*(r.x - q.x) - (q.x - p.x)*(r.y - q.y);
    if(slope == 0)return 0;
    else if(slope > 0) return 1;
    else return -1;
}

void convexHull(Point pnt[], int n) {
    if(n < 3) return;

    vector<Point> ans;

    int left = 0;
    for(int i = 1; i < n; i++) {
        if(pnt[left].x > pnt[i].x)
            left = i;
    }

    int p = left, q;
    do{
        ans.push_back(pnt[p]);
        q = (p+1)%n;
        for(int i = 0; i < n; i++) {
            if(orientation(pnt[p],pnt[i],pnt[q]) == -1)
                q = i;
        }
        p = q;

    }while(p!=left);

    for(int i = 0; i < ans.size(); i++) {
        cout << "(" << ans[i].x << ", " << ans[i].y << ")" << " \n"[i==n-1];
    }
    ans.clear();
}

int main() {
    int n;
    while(cin >> n){
        Point pnt[n+10];
        for(int i = 0; i < n; i++) {
            int x,y; cin >> x >> y;
            pnt[i] = {x,y};
        }
        convexHull(pnt,n);
    }
    return 0;
}

/**

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
