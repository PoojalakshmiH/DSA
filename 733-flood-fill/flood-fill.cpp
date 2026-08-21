class Solution {
public:

    void dfs(vector<vector<int>>& image, int i, int j, int newcolor,int orgcolor) 
   {  int n=image.size();
      int m=image[0].size();


        if(i<0||i>=n||j<0||j>=m||image[i][j]==newcolor||image[i][j]!=orgcolor)
        {
            return;
        }


      image[i][j]=newcolor;

      dfs(image,i-1,j,newcolor,orgcolor);
      dfs(image,i+1,j,newcolor,orgcolor);
       dfs(image,i,j-1,newcolor,orgcolor);
       dfs(image,i,j+1,newcolor,orgcolor);
   }


   


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
      
      int orgcolor = image[sr][sc];

        if(orgcolor == color)
            return image;
            
       dfs(image,sr,sc,color,image[sr][sc]);
       return image; 
    }
};