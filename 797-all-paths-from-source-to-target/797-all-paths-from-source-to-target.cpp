class Solution {
public:
    vector<vector<int>>ans;
    void dfs(vector<vector<int>>graph,vector<int>&temp,int dest,int node)
    {
       if (node==dest){
            ans.push_back(temp);
            return;
        }
        
        // go all paths one by one 
        for (auto i : graph[node]){
            temp.push_back(i); 
            dfs(graph,temp,dest,i);
            temp.pop_back(); // backtracking 
        }
        return; 
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>temp;
        temp.push_back(0);
        int dest=graph.size()-1;
        dfs(graph,temp,dest,0);
        return ans;
    }
};