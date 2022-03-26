class Solution {
public:
   private:
    void dfs(int i, vector<int>& visited, vector<vector<int>>& isConnected) {
        visited[i] = 1;
        
        for(int j = 0; j < isConnected[i].size(); j++) {
            if(isConnected[i][j] == 1 and !visited[j]) {
                dfs(j, visited, isConnected);
            }
        }
    }
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces = 0;
        
        int n = isConnected.size();
        vector<int> visited(n, 0);
        
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(i, visited, isConnected);
                provinces++;
            }
        }
        
        return provinces;
    }
};