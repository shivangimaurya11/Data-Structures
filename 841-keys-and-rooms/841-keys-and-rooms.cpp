typedef vector<vector<int>> vvi;
typedef vector<int> vi;
class Solution {
public:
    public:
    void dfs(vvi &adj, int i, vi &visited) {
        visited[i] = 1;
        for(auto x: adj[i]) {
            if(visited[x]==0) dfs(adj, x, visited);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vi visited(n);
        
        dfs(rooms, 0, visited);
        for(auto x: visited) {
            if(x==0) return false;
        }
        return true;
    }
};