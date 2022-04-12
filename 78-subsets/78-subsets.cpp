class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>&ds,vector<int>&nums,int index)
    {
        if(index==nums.size())
        {
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[index]);
            solve(ans,ds,nums,index+1);
        ds.pop_back();
        solve(ans,ds,nums,index+1);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        solve(ans,ds,nums,0);
        return ans;
        
    }
};