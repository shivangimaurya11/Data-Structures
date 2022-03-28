// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void dfs(int node,vector<bool> &visited,vector<vector<int>> adj,int N){
    
    visited[node]=true;
    
    for(int nbr=0;nbr<N;nbr++){
        if(adj[node][nbr] && !visited[nbr]){
            dfs(nbr,visited,adj,N);
        }
    }
}
    
        int numProvinces(vector<vector<int>> adj, int N) {
        vector<bool> visited(N,false);
        int count=0;
        for(int i=0;i<N;i++){
            if(!visited[i]){
                count++;
                dfs(i,visited,adj,N);
            }
        }
        return count;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}  // } Driver Code Ends