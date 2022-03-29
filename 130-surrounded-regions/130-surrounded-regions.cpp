class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    bool isvalid(int x,int y,int row,int col,vector<vector<char>>&board)
    {
        if(x<0||x>=row||y<0||y>=col||board[x][y]!='O')
            return false;
        return true;
    }
    void dfs(int x,int y,int row,int col,vector<vector<char>>&board)
    {
        
            board[x][y]='#';
        for(int i=0;i<4;i++)
        {
            if(isvalid(x+dx[i],y+dy[i],row,col,board))
                dfs(x+dx[i],y+dy[i],row,col,board);
        }
    }
    void solve(vector<vector<char>>& board) {
        int row=board.size();
        int col=board[0].size();
       if(board.size()== 0) return;
        for(int i = 0; i < board[0].size(); i++){
            if(board[0][i] == 'O')
                dfs(0, i,row,col,board);
            if(board[board.size() - 1][i] == 'O')
                dfs(board.size() - 1, i,row,col,board);
        }
        
        for(int i = 0; i < board.size(); i++){
            if(board[i][0] == 'O')
                dfs(i, 0,row,col,board);
            if(board[i][board[0].size() - 1] == 'O')
                dfs(i, board[0].size() - 1,row,col,board);
        }
        
       for(int i =0; i <board.size(); i++){
           for(int j =0; j <board[0].size(); j++){
               if(board[i][j] == '#')
                   board[i][j] = 'O';
               else if(board[i][j] == 'O')
                   board[i][j] = 'X';
           }
       }
       
       
        return; 
        
    }
};