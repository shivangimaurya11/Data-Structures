class Solution {
public:
    void solve(int n,int col,vector<vector<string>>&ans,vector<string>&board,vector<int>&leftrow,vector<int>&ld,vector<int>&ud)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(leftrow[row]==0 && ld[row+col]==0 && ud[n-1+col-row]==0)
            {
                 board[row][col]='Q';
            leftrow[row]=1;
            ld[row+col]=1;
            ud[n-1+col-row]=1;
                 solve(n,col+1,ans,board,leftrow,ld,ud);
            board[row][col]='.';
            leftrow[row]=0;
            ld[row+col]=0;
            ud[n-1+col-row]=0;
            }
               
            
           
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n);
        vector<vector<string>>ans;
        string s(n,'.');
        for(int i=0;i<n;i++)
            board[i]=s;
        vector<int>leftrow(n,0);
        vector<int>ld(2*n-1,0);
        vector<int>ud(2*n-1,0);
        solve(n,0,ans,board,leftrow,ld,ud);
        return ans;
    }
};