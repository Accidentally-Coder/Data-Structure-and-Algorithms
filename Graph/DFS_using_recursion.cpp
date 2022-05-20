void dfs(int src)
{
    //take a bool visited array and mark all of it false beforehand
    vis[src]=true;
    for(int i=0; i<adj[src].size(); i++){
        int child = adj[src][i];
        if(!vis[child])dfs(child);
    }
}
