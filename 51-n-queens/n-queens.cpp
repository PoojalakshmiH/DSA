class Solution {
public:
   void solve( int col,int n,vector<vector<string>> &allsol,vector<string>&board,vector<int>&leftrow,
    vector<int>&upperdiagonal,vector<int>&lowerdiagonal)

    {
        if(col==n)
        {
            allsol.push_back(board);
            return;
        }

        for(int row=0;row<n;row++)
        {
            if(leftrow[row]==0&&lowerdiagonal[row+col]==0&&upperdiagonal[(n-1)+(col-row)]==0)
            {
                board[row][col]='Q';
                leftrow[row]=1;
                upperdiagonal[(n-1)+(col-row)]=1;
                lowerdiagonal[col+row]=1;
                solve(col+1,n,allsol,board,leftrow,upperdiagonal,lowerdiagonal);
                 board[row][col]='.';
                leftrow[row]=0;
                upperdiagonal[(n-1)+(col-row)]=0;
                lowerdiagonal[col+row]=0;
            }
        }
    }


    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>allsol;
        vector<string>board(n);
        string s(n,'.');

        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        vector<int>leftrow(n,0);
        vector<int>upperdiagonal(2*n-1,0);
        vector<int>lowerdiagonal(2*n-1,0);
        solve( 0,n,allsol,board,leftrow,upperdiagonal,lowerdiagonal);
        return allsol;
    }
};