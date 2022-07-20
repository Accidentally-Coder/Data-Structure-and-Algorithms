#include<bits/stdc++.h>
using namespace std;
const int MXN = 1010;
const int inf = 1e9 + 7;

int capacity[MXN][MXN];
int N, E;

int vis[MXN], parent[MXN];

vector<int> findPath(int src, int dst)
{
    memset(vis,0,sizeof(vis));
    memset(parent,-1,sizeof(parent));
    vis[src]=1;
    queue<int>q;
    q.push(src);
    vector<int>path;
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        if(cur==dst) break;
        for(int i=0; i<N; i++){
            if(!vis[i] && capacity[cur][i] > 0){
                vis[i]=true;
                q.push(i);
                parent[i]=cur;
            }
        }
    }
    if(vis[dst]){
        while(dst!=-1){
            path.push_back(dst);
            dst=parent[dst];
        }
        reverse(path.begin(),path.end());
    }
    return path;
}

int findFlow(int srce, int sink)
{
    int flow = 0;
    while(true){
        vector<int>path = findPath(srce,sink);
        if(path.size() == 0) return flow;

        int cost = INT_MAX;

        for(int i = 1; i < path.size(); i++) {
            int v = path[i], u = path[i-1];
            cost = min(cost, capacity[u][v]);
        }
        flow+=cost;
        for(int i = 1; i < path.size(); i++) {
            int v = path[i], u = path[i-1];
            capacity[u][v] -= cost;
            capacity[v][u] += cost;
        }
    }
    return flow;
}

int main()
{
    //freopen("00_input.txt", "r", stdin);
    while(scanf("%d%d", &N,&E) == 2){
        memset(capacity, 0, sizeof(capacity));
        int a, b, w;
        while(E--){
            scanf("%d%d%d", &a, &b, &w);
            capacity[a][b] += w;
        }
        int srce, sink;

        scanf("%d%d", &srce, &sink);

        int flow = findFlow(srce, sink);

        cout<<flow<<endl;
    }
    return 0;
}

/*
6 8
0 1 11
0 2 12
2 1 1
1 3 12
2 4 11
4 3 7
4 5 4
3 5 19
0 5

4 5
0 1 6
0 2 4
1 2 10
1 3 2
2 3 5
0 3

*/
