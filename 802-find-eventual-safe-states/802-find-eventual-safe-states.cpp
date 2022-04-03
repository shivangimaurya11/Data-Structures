class Solution {
public:
    bool dfs(int node,vector<vector<int>>&graph,vector<int>&vis,vector<int>&dfsvis,vector<bool>&cycle)
    {
    vis[node]=1;
        dfsvis[node] = 1;
        
        vector<int>data = graph[node];
        for(auto x: data){
            if(!vis[x]){
                if(dfs(x,graph,vis,dfsvis,cycle)){
                    return cycle[node] = true;
                }
            }
            else if(vis[x] && dfsvis[x]){
                return cycle[node] = true;
            }
        }
        
        dfsvis[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,0);
        vector<int>dfsvis(n,0);
        vector<bool>cycle(n,false);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
                dfs(i,graph,vis,dfsvis,cycle);
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(!cycle[i])
                ans.push_back(i);
        }
        return ans;
        
    }
};