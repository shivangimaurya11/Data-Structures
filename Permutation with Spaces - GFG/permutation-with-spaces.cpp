// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:

void solve(vector<string>&ans,string s,string op)
{
    if(s.size()==0)
    {
        ans.push_back(op);
        return;
    }
    string op1=op;
    string op2=op;
    op1.push_back(' ');
    op1.push_back(s[0]);
    op2.push_back(s[0]);
    s.erase(s.begin()+0);
    solve(ans,s,op1);
    solve(ans,s,op2);
}
    vector<string> permutation(string s){
      string op="";
      op.push_back(s[0]);
      s.erase(s.begin()+0);
      vector<string>ans;
      solve(ans,s,op);
      return ans;
        
    }
};

// { Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}
  // } Driver Code Ends