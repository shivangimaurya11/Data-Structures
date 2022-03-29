class Solution {
    void dfs(int node,vector<int> &vis,vector<vector<int> > &v){
        vis[node]=1;
        for(auto child:v[node]){
            if(vis[child]==0){
                dfs(child,vis,v);
            }
        }
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        int i;
        vector<int>vis(n,0);
        vector<vector<int> >v(n);
        for(i=0;i<edges.size();i++){
            v[edges[i][0]].push_back(edges[i][1]);
            v[edges[i][1]].push_back(edges[i][0]);
            
        }
        for(i=0;i<n;i++){
            if(vis[start]==0){
                dfs(start,vis,v);
                if(vis[end]==0){
                    return false;
                }
                
            }
        }
        return true;
    
    }
};