class Solution {
public:
    int maxProduct(vector<int>& nums) {
     priority_queue<int,vector<int>,greater<int>>min;
        int k=2;
        for(int i=0;i<nums.size();i++)
        {
            min.push(nums[i]);
            if(min.size()>k)
                min.pop();
            
        }
        int first=min.top();
        min.pop();
        int second=min.top();
        return (first-1)*(second-1);
        
    }
};