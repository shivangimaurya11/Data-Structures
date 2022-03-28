// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

   class Node{
    
    public:
    int u,v,wt;
    Node(int first,int second,int weight){
        u = first;
        v = second;
        wt = weight;
    }
};
class Compare{
    public:
    inline bool operator()(Node &a,Node &b){
        return a.wt<b.wt;
    }
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	 
	int findPar(int u,vector<int> &parent){
	    if(u == parent[u]){
	        return u;
	    }
	    return parent[u] = findPar(parent[u],parent);
	}
	int unite(int u,int v,vector<int> &parent,vector<int> &rank){
	    u = findPar(u,parent);
	    v = findPar(v,parent);
	    if(rank[u] == rank[v]){
	        rank[u] += 1;
	        parent[v] = u;
	    }
	    else if(rank[u]>rank[v]){
	        parent[u] = v;
	    }
	    else{
	        parent[v] = u;
	    }
	}
    int spanningTree(int V, vector<vector<int>> adj[])
    {
       
        
        int cost = 0;
        vector<int> rank(V);
        vector<int> parent(V);
        vector<pair<int,int>> mstSet;
        for(int i=0; i<V; i++){
            rank[i] = 0;
            parent[i] = i;
        }
        vector<Node> edges;
        for(int i=0; i<V; i++){
            for(auto vec:adj[i]){
                edges.push_back(Node(i,vec[0],vec[1]));
            }
        }
        sort(edges.begin(),edges.end(),Compare());
        for(auto it:edges){
            if(findPar(it.u,parent) != findPar(it.v,parent)){
                mstSet.push_back(make_pair(it.u,it.v));
                unite(it.u,it.v,parent,rank);
                cost += it.wt;
            }
        }
        return cost;
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