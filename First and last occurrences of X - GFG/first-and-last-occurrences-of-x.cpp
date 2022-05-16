// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    vector<int> firstAndLast(vector<int> &arr, int n, int x) {
        int start=0;
        int end=n;
        vector<int>v;
        int ans1=-1;
        int ans2=-1;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(arr[mid]==x)
            {
                ans1=mid;
                end=mid-1;
            }
            else if(arr[mid]<x)
            start=mid+1;
            else
            end=mid-1;
        }
        start=0;
        end=n;
        while(start<=end)
        {
            int  mid=(start+end)/2;
            if(arr[mid]==x)
            {
                ans2=mid;
                start=mid+1;
            }
            else if(arr[mid]<x)
            start=mid+1;
            else
            end=mid-1;
        }
        if(ans1==-1 && ans2==-1)
        v.push_back(-1);
        else{
            v.push_back(ans1);
        v.push_back(ans2); 
        }
       
        return v;
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> ans= obj.firstAndLast(arr, n, x) ;
        for(int i:ans){
            cout<<i<<" ";
        }
        cout<< endl;
    }
    return 0;
}
  // } Driver Code Ends