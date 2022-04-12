class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int mid=n;
        vector<int>arr;
        int j=mid;
        for(int i=0,j=mid;i<n,j<2*n;i++,j++)
        {
            arr.push_back(nums[i]);
            arr.push_back(nums[j]);
        }
        return arr;
    }
};