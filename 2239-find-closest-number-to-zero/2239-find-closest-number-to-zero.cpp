class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int d=0;
        int min=abs(nums[0]);
        int near;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            d=abs(nums[i]);
            if(d<=min)
            {
                min=d;
                near=i;
            }
        }
        return nums[near];
    }
};