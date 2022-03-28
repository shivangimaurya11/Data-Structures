// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
typedef vector<int> vv;
#define pb push_back
class Solution {
  public:
  void dfs(int node,int parent,vv &artp,vv &tin,vv &low,vv &vis,vv adj[],int &timer)
  {
      vis[node]=1;
      tin[node]=low[node]=timer++;
      int child=0;
      for(auto it:adj[node])
      {
          if(it==parent)
          continue;
          if(!vis[it])
          {
              
              dfs(it,node,artp,tin,low,vis,adj,timer);
              low[node]=min(low[node],low[it]);
              if(low[it]>=tin[node] && parent!=-1)
              artp[node]=1;
              child++;
          }
          else 
          {
              low[node]=min(low[node],tin[it]);
          }
          if(parent==-1 && child>1)
          artp[node]=1;
      }
      
  }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int>artp(V,0);
        vector<int>tin(V,-1);
        vector<int>low(V,-1);
        vector<int>vis(V,0);
        int timer=0;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            dfs(i,-1,artp,tin,low,vis,adj,timer);
        }
        vv articulation;
        for(int i=0;i<artp.size();i++)
        {
            if(artp[i]==1)
            articulation.pb(i);
        }
        if(articulation.size()!=0)
        return articulation;
        articulation.pb(-1);
        return articulation;
    }
};

// { Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends