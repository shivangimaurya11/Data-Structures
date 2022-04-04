class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>m;
        set<int>s;
        for(auto it:matches)
        {
            s.insert(it[0]);
            s.insert(it[1]);
            m[it[1]]++;
        }
        vector<vector<int>>ans(2);
        for(auto it:s)
        {
            if(m[it]==1)
                ans[1].push_back(it);
        }
        for(auto it:s)
            if(!m[it])
                ans[0].push_back(it);
        return ans;
    }
};