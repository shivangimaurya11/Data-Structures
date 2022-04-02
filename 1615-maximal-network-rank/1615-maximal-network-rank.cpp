class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int rank=0;
        vector<vector<int>>direction(n,vector<int>(n));
        vector<int>count(n);
        for(auto it:roads)
        {
            count[it[0]]++;
            count[it[1]]++;
            direction[it[0]][it[1]]=1;
            direction[it[1]][it[0]]=1;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                rank=max(rank,count[i]+count[j]-direction[i][j]);
            }
        }
        return rank;
    }
};