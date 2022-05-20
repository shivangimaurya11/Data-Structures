class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>s1,s2;
        vector<int>v;
        for(auto it:nums1)
            s1.insert(it);
        for(auto it:nums2)
            s2.insert(it);
        for(auto val:s2)
        {
            if(s1.find(val)!=s1.end())
                v.push_back(val);
                
        }
        return v;
        
    }
};