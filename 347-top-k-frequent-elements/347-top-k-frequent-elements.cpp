typedef pair<int,int> p;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]++;
        priority_queue<p,vector<p>,greater<p>>h;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            h.push({it->second,it->first});
            if(h.size()>k)
                h.pop();
        }
        vector<int>s;
        while(!h.empty())
        {
            s.push_back(h.top().second);
            h.pop();
        }
        return s;
    }
};