// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    int cx[8]={-1,-1,-1,0,0,1,1,1};
    int cy[8]={-1,0,1,-1,1,-1,0,1};
    bool isvalid(int x,int y,int m ,int n)
    {
        if(x<0 || y<0 || x>=m || y>=n)
        return false;
        
        return true;
    }
    void dfs(vector<vector<int>>& grid ,int i,int j,int m,int n,int &c)
    {
          grid[i][j]=2;
            
        for(int k=0;k<8;k++)
        {
            int X=cx[k]+i;
            int Y=cy[k]+j;
            if(isvalid(X,Y,m,n) && grid[X][Y]==1)
            {  
                c++;
                dfs(grid,X,Y,m,n,c);
            }
            
            
            
        
        }
        
        
    }
    int findMaxArea(vector<vector<int>>& grid) {
        
    int m=grid.size();
    int n=grid[0].size();
    int ans=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            int c=1;
            if(grid[i][j]==1)
            {   
                dfs(grid,i,j,m,n,c);
                ans=max(ans,c);
            }
        }
    }
   return ans;
         
    } 
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends