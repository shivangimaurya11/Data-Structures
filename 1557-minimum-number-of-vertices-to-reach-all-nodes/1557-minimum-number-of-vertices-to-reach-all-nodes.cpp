typedef vector<int> v;
#define pb push_back
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
       v ans;
        v indegree(n,0);
        for(auto it:edges)
        {
            indegree[it[1]]++;
        }
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i]==0)
                ans.push_back(i);
        }
        return ans;
    }
};