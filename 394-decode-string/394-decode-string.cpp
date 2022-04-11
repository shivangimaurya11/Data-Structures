class Solution {
public:
    string decodeString(string ip) {
        stack<char>st;
        string ans="";
        for(int i=0;i<ip.size();i++)
        {
            if(ip[i]!=']')
            {
                st.push(ip[i]);
            }
            else{
                string s="";
                while(st.top()!='[')
                {
                    s=st.top()+s;
                    st.pop();
                }
                st.pop();
                string num="";
                while(!st.empty() && isdigit(st.top()))
                {
                    num=st.top()+num;
                    st.pop();
                }
                int k=stoi(num);
                while(k--)
                {
                    for(int j=0;j<s.size();j++)
                    {
                        st.push(s[j]);
                    }
                }
            }
        }
        while(!st.empty())
        {
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};