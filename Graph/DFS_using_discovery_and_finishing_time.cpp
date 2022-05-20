#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz 1010

vector<int> adj[sz];
int color[sz], time_in[sz], time_out[sz], t=0;

/*

0 -> vertex is not processed yet. Initially all vertice are of color 0
1 -> vertex is being processed, all its descendants are not processed yet
2 -> vertex and all its descendants are processed

*/

void dfs(int src) {
    time_in[src] = ++t;
    color[src] = 1;
    for(int child : adj[src]) {
        if(color[child] == 0) {
            dfs(child);
        }
    }
    color[src] = 2;
    time_out[src] = ++t;
}

int main() {
    int n,m; cin >> n >> m;
    while(m--) {
        int x,y; cin >> x >> y;
        adj[x].push_back(y); //x from, y to
        //adj[y].push_back(x);
    }
    for(int i = 1; i <= n ; i++)
        if(color[i] == 0)dfs(i);
    for (int i = 1; i <= n; i++) cout << time_out[i] << ' ';
}


/***


4 4
2 1
2 3
3 4
1 4

*/
