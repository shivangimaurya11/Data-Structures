class Solution {
public:
    int parent[1000];
    int rank[1000];
    int findpar(int x,int parent[])
    {
        if(parent[x]==x)
            return x;
        return parent[x]=findpar(parent[x],parent);
    }
    void unio(int parent[],int rank[],int x,int y)
    {
        int u=findpar(x,parent);
        int v=findpar(y,parent);
        if(rank[u]<rank[v])
            parent[u]=v;
        else if(rank[v]<rank[u])
            parent[v]=u;
        else
        {
            parent[v]=u;
            rank[u]++;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        memset(rank,0,sizeof(rank));
        vector<int>ans;
        int n=edges.size();
        for(int i=0;i<n;i++)
            parent[i]=i;
        for(int i=0;i<n;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            if(findpar(u,parent)==findpar(v,parent))
            {
                ans.push_back(u);
                ans.push_back(v);
                break;
            }
            else
                unio(parent,rank,u,v);
        }
        return ans;
    }
};