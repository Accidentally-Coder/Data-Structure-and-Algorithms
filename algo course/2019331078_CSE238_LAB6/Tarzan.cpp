#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int sz = (int)(1e3)+5;

int n,m;
int adj[sz][sz];

void addEdge(int a, int b) {
    adj[a][b] = 1;
}

void findComponent(int u, int disc[], int low[], stack<int>&s, bool stk[]) {
    static int time = 0;
    disc[u] = low[u] = ++time;
    s.push(u);
    stk[u] = true;
    for (int v = 0; v < n; v++) {
        if (adj[u][v]) {
            if (disc[v] == -1) {
                findComponent(v,disc,low,s,stk);
                low[u] = min(low[u],low[v]);
            } else if(stk[v]) {
                low[u] = min(low[u],disc[v]);
            }
        }
    }
    int popx = 0;
    if (low[u] == disc[u]) {
        while(s.top() != u) {
            popx = s.top();
            cout << popx << ' ';
            stk[popx] = false;
            s.pop();
        }
        popx = s.top();
        cout << popx << '\n';
        stk[popx] = false;
        s.pop();
    }
}

void SCC() {
    int disc[n+5],low[n+5];
    bool stk[n+5];
    stack<int>s;
    for (int i = 0; i < n; i++) {
        disc[i] = low[i] = -1;
        stk[i] = false;
    }
    for (int i = 0; i < n; i++) {
        if (disc[i] == -1) {
            findComponent(i,disc,low,s,stk);
        }
    }
}

int main() {
    cin >> n >> m; // n = node, m = edges
    for (int i = 1; i <= m; i++) {
        int u,v; cin >> u >> v;
        addEdge(u,v);
    }
    cout << "Following are the Strongly Connected Components in given graph : \n";
    SCC();
    return 0;
}


/**


Test Cases :
____________

8 12
0 1
7 1
1 6
6 7
6 0
0 4
6 4
6 5
5 3
3 4
4 2
2 3


5 5
0 3
1 0
2 1
0 2
3 4

*/
