class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int>adj[n];
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int>indeg(n,0);
        vector<int>topo;
        for(int i=0;i<n;i++)
            for(auto it:adj[i])
                indeg[it]++;
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(indeg[i]==0)
                q.push(i);
        }
        int count=0;
        while(!q.empty())
        {
            count++;
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node])
            {
                if(--indeg[it]==0)
                    q.push(it);
            }
        }
      if(count==n)
          return topo;
        else
            return {};
    }
};