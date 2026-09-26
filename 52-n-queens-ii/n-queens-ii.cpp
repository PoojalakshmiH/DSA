class Solution {
public:

    void solve(int col,vector<string>&board,int &ans,int n,vector<int>&leftrow, vector<int> &lowerdiagonal,vector<int>&upperdiagonal){
       
    if(col==n)
    {
        ans+=1;
        return;
    }
    for(int row =0;row<n;row++)
    {
        if(leftrow[row]==0 && upperdiagonal[(n-1)+(col-row)]==0 &&lowerdiagonal[row+col]==0)
        {
            board[row][col]='Q';
            leftrow[row]=1;
            upperdiagonal[(n-1)+(col-row)]=1;
            lowerdiagonal[row+col]=1;
            solve(col+1,board,ans,n,leftrow,lowerdiagonal,upperdiagonal);
            board[row][col]='.';
            leftrow[row]=0;
            upperdiagonal[(n-1)+(col-row)]=0;
            lowerdiagonal[row+col]=0;

        }
    }
    }

    int totalNQueens(int n) {
        vector<string>board(n);
        vector<int>leftrow(n,0);
        vector<int>upperdiagonal(2*n-1,0);
        vector<int>lowerdiagonal(2*n-1,0);
        string s(n,'.');

        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        int ans=0;

        solve(0,board,ans,n,leftrow,lowerdiagonal,upperdiagonal);
        return ans;

    }
};