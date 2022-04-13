class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int c=1;
        int left=0,right=n-1;//column
        int top=0,bottom=n-1;//row
        vector<vector<int>>ans(n,vector<int>(n,0));
        int val=0;
        while(left<=right && top<=bottom)
        {
            for(int i=left;i<=right;i++)
                ans[top][i]=++val;
                top++;
            for(int i=top;i<=bottom;i++)
                ans[i][right]=++val;
            right--;
            for(int i=right;i>=left;i--)
                ans[bottom][i]=++val;
            bottom--;
            for(int i=bottom;i>=top;i--)
                ans[i][left]=++val;
            left++;
    
        }
        return ans;
    }
};