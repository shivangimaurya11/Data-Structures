class Solution {
public:
    void dfs(vector<int>&vis,int node,vector<int>adj[])
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                dfs(vis,it,adj);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        int edges=0;
        for(int i=0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
            edges++;
        }
        vector<int>vis(n,0);
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                count++;
                dfs(vis,i,adj);
            }  
        }
        if(edges<n-1)
            return -1;
        int red=edges-((n-1)-(count-1));
        if(red>=count-1)
            return count-1;
        return -1;
        
    }
};