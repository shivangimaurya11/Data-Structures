// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
void solve(int one,int zero,vector<string>&ans,int n,string op)
{
    if(n==0)
    {
        ans.push_back(op);
        return;
    }
    string op1=op;
    op1.push_back('1');
    solve(one+1,zero,ans,n-1,op1);
    if(one>zero)
    {
        string op2=op;
        op2.push_back('0');
        solve(one,zero+1,ans,n-1,op2);
    }
    return;
}
	vector<string> NBitBinary(int N)
	{
	    int one=0;
	    int zero=0;
	    vector<string>ans;
	    string op="";
	    solve(one,zero,ans,N,op);
	    return ans;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}  // } Driver Code Ends