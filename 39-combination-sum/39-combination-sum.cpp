class Solution {
public:
    void solve(vector<int>&arr,int target,vector<vector<int>>&ans,vector<int>&ds,int index)
    {
        if(index==arr.size())
        {
            if(target==0)
            {
                ans.push_back(ds);
            }
            return;
        }
        if(arr[index]<=target)
        {
            ds.push_back(arr[index]);
                solve(arr,target-arr[index],ans,ds,index);
            ds.pop_back();
        }
        solve(arr,target,ans,ds,index+1);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        int index=0;
        solve(arr,target,ans,ds,index);
        return ans;
    }
};