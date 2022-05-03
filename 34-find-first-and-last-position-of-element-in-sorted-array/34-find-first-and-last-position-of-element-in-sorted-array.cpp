class Solution {
public:
    void find_last(vector<int>nums,int target,vector<int>&index)
    {
        int start=0;
        int end=nums.size()-1;
        int res=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]==target)
            {
                res=mid;
                end=mid-1;
            }
            else if(nums[mid]<target)
                start=mid+1;
            else
                end=mid-1;
            
        }
        if(res!=-1)
        index.push_back(res);
        else
            index.push_back(-1);
    }
    void find_first(vector<int>nums,int target,vector<int>&index)
    {
        int start=0;
        int end=nums.size()-1;
        int res=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]==target)
            {
                res=mid;
                start=mid+1;
            }
            else if(nums[mid]<target)
                start=mid+1;
            else
                end=mid-1;
        }
        if(res!=-1)
        index.push_back(res);
        else
            index.push_back(-1);
    }
    vector<int> searchRange(vector<int>& nums, int target) {
       vector<int>index;
        find_first(nums,target,index);
        find_last(nums,target,index);
        sort(index.begin(),index.end());
        return index;
    }
};