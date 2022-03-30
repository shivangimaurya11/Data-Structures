class Solution {
public:
    bool dfs(vector<vector<char>>&board,string word,int i,int j,int count)
    {
        if(count>=word.size())
            return true;
        if(i<0||j<0||i>=board.size()||j>=board[i].size()||board[i][j]!=word[count])
            return false;
       
        board[i][j]='#';
        bool found=dfs(board,word,i+1,j,count+1)||dfs(board,word,i-1,j,count+1)||dfs(board,word,i,j+1,count+1)||dfs(board,word,i,j-1,count+1);
        board[i][j]=word[count];
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size();
        int col=board[0].size();
        for(int i=0;i<row;i++)
            for(int j=0;j<board[i].size();j++)
                if(board[i][j]==word[0] && dfs(board,word,i,j,0))
                    return true;
        return false;
    }
};