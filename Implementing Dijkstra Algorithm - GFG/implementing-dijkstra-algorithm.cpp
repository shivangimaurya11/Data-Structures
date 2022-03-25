// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

typedef pair<int,int> pi;
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int>dist(V+1,INT_MAX);
        priority_queue<pi,vector<pi>,greater<pi>>pq;
        dist[S]=0;
        pq.push(make_pair(0,S));
        while(!pq.empty())
        {
            int curr=pq.top().second;
            int curr_dist=pq.top().first;
            pq.pop();
            for(auto it:adj[curr])
            {
                int next=it[0];
                int next_dist=it[1];
                if(curr_dist+next_dist<dist[next])
                {
                    dist[next]=curr_dist+next_dist;
                    pq.push(make_pair(dist[next],next));
                }
                
            }
        }
        return dist;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends