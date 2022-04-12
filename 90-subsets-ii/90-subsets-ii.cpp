class Solution {
public:
    void solve(vector<int>&nums,vector<vector<int>>&ans,vector<int>ds,int index)
    {
        if(index==nums.size())
        {
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[index]);
        solve(nums,ans,ds,index+1);
        ds.pop_back();
         solve(nums,ans,ds,index+1);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        vector<int>ds;
        set<vector<int>>s;
        solve(nums,ans,ds,0);
        for(auto it:ans)
            s.insert(it);
        ans.clear();
        for(auto it:s)
            ans.push_back(it);
        return ans;
    }
};