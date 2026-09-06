class Solution {
public:
   bool solve( int i,int j,vector<vector<bool>>&vis,vector<vector<char>>& board,string &word,int stridx,   int di  [],int dj[])
   {    
      if(stridx==word.size())
      {
        return true;
      }
        int n=board.size();
        int m=board[0].size();
        
        for(int idx=0;idx<4;idx++)
        {
            int nexti=i+di[idx];
            int nextj=j+dj[idx];
            if(nexti>=0&&nextj>=0&&nexti<n&&nextj<m&&!vis[nexti][nextj]&&board[nexti][nextj]==word[stridx])
            {
                vis[i][j]=1;
                if(solve(nexti,nextj,vis,board,word,stridx+1,di,dj)==true)
                {
                    return true;

                }
                vis[i][j]=0;
            }
        }
        return false;
   }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        
        int di[] ={+1,0,0,-1};
        int dj[]={0,-1,+1,0};
        string ans =to_string(word[0]);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {   

                     if(solve(i,j,vis,board,word,1,di,dj)==true)
                     return true;
                }
            }
        }
        

        return false;
       
    }
};