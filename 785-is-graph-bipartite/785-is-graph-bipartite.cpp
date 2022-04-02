class Solution {
public:
    bool dfs(vector<vector<int>> &g, int node, int col, vector<bool> &vis, vector<int> &color)
    {
        vis[node]=true;
        color[node]=col;
        
        for(auto child: g[node])
        {
            // if not visited and dfs returns false
            if(!vis[child] && !dfs(g, child, 1-col, vis, color))
                return false;
            // if color of adjacent child is same as color of current node return false
            if(color[node]==color[child])
                return false;
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> vis(n, 0);
        vector<int> color(n, -1);
        for(int i=0; i<n; i++)
        {
            // If not visited and dfs returns false
            if(vis[i]==0 && dfs(graph, i, 1, vis, color)== false)
                return false;
        }
        
        return true;
    }
};