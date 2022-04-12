class Solution {
public:
    void solve(vector<int>&nums,vector<vector<int>>&ans,vector<int>ds,vector<bool>&vis)
    {
        if(ds.size()==nums.size())
        {
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(vis[i]==true)
                continue;
            vis[i]=true;
            ds.push_back(nums[i]);
            solve(nums,ans,ds,vis);
            vis[i]=false;
            ds.pop_back();
            
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        vector<bool>vis(nums.size(),false);
        solve(nums,ans,ds,vis);
        return ans;
    }
};