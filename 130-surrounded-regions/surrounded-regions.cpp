class Solution {
public:

    void dfs(vector<vector<char>>& board,vector<vector<bool>>&vis,int i ,int j)
    {
        if(i<0||i>=board.size()||j<0||j>=board[0].size()||vis[i][j]||
        board[i][j]=='X')
          return;
        vis[i][j]=true;

        dfs(board,vis,i-1,j);
        dfs(board,vis,i+1,j);
        dfs(board,vis,i,j-1);
        dfs(board,vis,i,j+1);
    }
    void solve(vector<vector<char>>& board) {
        int n= board.size();
        int m=board[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0||j==m-1||j==0||i==n-1)
                {
                    if(!vis[i][j]&&board[i][j]=='O')
                    {
                        dfs(board,vis,i,j);
                    }
                }
            }
        }


        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && board[i][j]=='O')

                {   vis[i][j]=true;
                    board[i][j]='X';
                }
            }
        }
    }
};