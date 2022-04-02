class Solution {
public:
    void dfs(vector<int>&vis,int node,vector<int>adj[],int &count)
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[abs(it)])
            {
                if(it>0)
                {
                count++;
                }
                dfs(vis,abs(it),adj,count); 
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int>adj[n+1];
        vector<int>vis(n+1,0);
        for(int i=0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
             adj[connections[i][1]].push_back(-connections[i][0]);
            
        }
        int count=0;
        dfs(vis,0,adj,count);
        return count;
    }
};