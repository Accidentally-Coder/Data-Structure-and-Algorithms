/*
Time Complexity : O(N+E)
Space Complexity : O(N+E)+O(N)+O(N) // adj list + vis array + queue
*/

void bfs(int src)
{
    //take bool vis[] and int dis[] or level[] array
    vis[src]=1;
    dis[src]=0;
    queue<int>q;
    q.push(src);
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        for(int i=0; i<adj[cur].size(); i++){
            int child = adj[cur][i];
            if(!vis[child]){
                vis[child]=true;
                q.push(child);
                dis[child]=dis[cur]+1;
            }
        }
    }
}

