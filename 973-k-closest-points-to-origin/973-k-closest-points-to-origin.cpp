class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>>h;
        for(int i=0;i<points.size();i++)
        {
            h.push({(points[i][0]*points[i][0])+(points[i][1]*points[i][1]),{points[i][0],points[i][1]}});
            if(h.size()>k)
                h.pop();
        }
        vector<vector<int>>t;
        while(!h.empty())
        {
            vector<int>ans;
            ans.push_back(h.top().second.first);
            ans.push_back(h.top().second.second);
            t.push_back(ans);
            h.pop();
        }
        return t;
    }
};