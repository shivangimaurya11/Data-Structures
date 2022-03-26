#define vv vector<vector<int>>
#define v vector<int>
class Solution {
public:
    void dfs(vv &rooms,v &vis,int node)
    {
        vis[node]=1;
        for(auto it:rooms[node])
        {
            if(vis[it]==0)
                dfs(rooms,vis,it);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        v vis(n,0);
        dfs(rooms,vis,0);
        for(auto i:vis)
        {
            if(i==0)
            {
        
                return false;
            }
        }
        return true;
        
    }
};