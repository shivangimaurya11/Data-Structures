// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

#include<cmath>
class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	     int n = nums.size();
	    vector <pair<int,int>> v;
	    for(int i=0; i<n; i++){
	        v.push_back({nums[i], i});
	    }
	    sort(v.begin(), v.end());
	    int c = 0;
	    for(int i=0; i<n; i++){
	        if(i != v[i].second){
	            c += 1;
	            swap(v[i], v[v[i].second]);
	            i--;
	        }
	    }
	    return c;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends