class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> m;
        for(auto k:arr)m[k]++;
        int ans=-1;
        for(auto k:m){
            if(k.second==k.first){
                ans=max(ans,k.first);
            }
        }
        return ans;
    }
};