class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
      int infinity =1e9;
       
        vector<vector<int>>dist(n,vector<int>(n,infinity));

        
        for(int i=0;i<n;i++)
        {
            dist[i][i]=0;
        }

        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
           

           dist[u][v]=wt;
           dist[v][u]=wt;

        }


    

       




        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for( int j=0;j<n;j++)
                {
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                     
                    
                }
            }
        }

        vector<int>mincities(n,0);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j && dist[i][j]<=distanceThreshold){
                    
                    mincities[i]+=1;
                }
            }
        }

       int ans=-1;
       int  mini=infinity;
       for(int i=0;i<n;i++)
       {
       if(mincities[i] <= mini)
        {
             mini = mincities[i];
                ans = i;
        }
       }
       return ans; 
        
    }
};