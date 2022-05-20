class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
   unordered_map<int,int>freq;
        vector<int>vec;
        for(auto it:nums1)
        {
            freq[it]++;
        }
        for(auto it:nums2)
        {
            cout<<it<<endl;
            if(freq[it])
            {
                vec.push_back(it);
                freq[it]--;
            }
        }
        return vec;
    }
};