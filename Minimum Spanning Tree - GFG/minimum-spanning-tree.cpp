// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

typedef pair<int,int>  pi;
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int key[V];
        int parent[V];
        bool MST[V];
           for(int i=0;i<V;i++)
        {
          key[i]=INT_MAX;
          MST[i]=false;
          parent[i]=-1;
        }
        key[0]=0;
        parent[0]=-1;
        MST[0]=true;
        priority_queue<pi,vector<pi>,greater<pi>>pq;
        pq.push(make_pair(0,0));
        while(!pq.empty())
        {
            int u=pq.top().second;
            pq.pop();
            MST[u]=true;
            
                for(auto it:adj[u])
                {
                    int v=it[0];
                    int w=it[1];
                    if(MST[v]==false && w<key[v])
                    {
                        parent[v]=u;
                        key[v]=w;
                        pq.push(make_pair(key[v],v));
                    }
                }
            
        }
        int sum=0;
           for(int i=0;i<V;i++ )
      {
          
          if(key[i]!=INT_MAX)
          sum=sum+key[i];
          
      }
        return sum;
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
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends