class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        int size=prerequisites.size();
        vector<int>adj[n];
        for(int i=0;i<size;i++)
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        queue<int>q;
        vector<int>indeg(n,0);
        for(int i=0;i<n;i++)
        {
            for(auto it:adj[i])
                indeg[it]++;
        }
        for(int i=0;i<indeg.size();i++)
            if(indeg[i]==0)
                q.push(i);
        vector<int>topo;
        int count=0;
        while(!q.empty())
        {
            int node=q.front();
            topo.push_back(node);
            q.pop();
            for(auto it:adj[node])
            {
                if(--indeg[it]==0)
                    q.push(it);
            }
            count++;
        }
        return count==n;
    }
};