class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>ch1;
        stack<char>ch2;
        int i,j;
        for(i=0;i<s.length();i++)
        {
            if(s[i]=='#' && !ch1.empty())
                ch1.pop();
            else if(s[i]!='#')
                ch1.push(s[i]);
        }
        for(j=0;j<t.length();j++)
        {
            if(t[j]=='#' && !ch2.empty())
                ch2.pop();
            else if(t[j]!='#')
                ch2.push(t[j]);
        }
        string s1,s2;
        while(!ch1.empty())
        {
            s1.push_back(ch1.top());
            ch1.pop();
        }
        while(!ch2.empty())
        {
            s2.push_back(ch2.top());
            ch2.pop();
        }
        return s1==s2;
    }
};