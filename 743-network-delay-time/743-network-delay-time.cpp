typedef pair<int,int> pi;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1,INT_MAX);
        priority_queue<pi,vector<pi>,greater<pi>>pq;
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<times.size();i++)
            adj[times[i][0]].push_back(make_pair(times[i][1],times[i][2]));
        pq.push(make_pair(0,k));
        dist[k]=0;
        while(!pq.empty())
        {
            int curr_dis=pq.top().first;
            int curr_node=pq.top().second;
            pq.pop();
            for(auto it:adj[curr_node])
            {
                int next_dis=it.second;
                int next_node=it.first;
                if(curr_dis+next_dis<dist[next_node])
                {
                    dist[next_node]=curr_dis+next_dis;
                    pq.push(make_pair(dist[next_node],next_node));
                }
                    
            }
        }
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            if(dist[i]==INT_MAX)
                return -1;
            sum=max(sum,dist[i]);
        }
        return sum;
    }
};