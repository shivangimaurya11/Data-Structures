class Solution {
public:
    void solve(int index,vector<int>&nums,vector<int>&v,vector<vector<int>>&ans)
    {
        if(index==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++)
        {
            swap(nums[index],nums[i]);
            solve(index+1,nums,v,ans);
            swap(nums[index],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int>v;
    vector<vector<int>>ans;
        solve(0,nums,v,ans);
        set<vector<int>>s;
        for(auto it:ans)
            s.insert(it);
        ans.clear();
        for(auto it:s)
            ans.push_back(it);
        return ans;
    }
};