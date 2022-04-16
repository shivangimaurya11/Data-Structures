class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string>ans;
        vector<vector<string>>res;
        solve(0,s,ans,res);
        return res;
    }
    void solve(int index,string s,vector<string>&ans,vector<vector<string>>&res)
    {
        if(index==s.size())
        {
            res.push_back(ans);
            return;
        }
        for(int i=index;i<s.size();i++)
        {
            if(isPalindrome(s,index,i))
            {
                 ans.push_back(s.substr(index,i-index+1));
                solve(i+1,s,ans,res);
                ans.pop_back();
            }
               
        }
    }
    bool isPalindrome(string s,int start,int end)
    {
        while(start<=end)
        {
            if(s[start++]!=s[end--])
            {
                return false;
            }
                
        }
        return true;
    }
};