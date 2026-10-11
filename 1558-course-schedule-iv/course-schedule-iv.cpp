class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        vector<vector<bool>>matrix(numCourses,vector<bool>(numCourses,false));

        for(int i=0;i<prerequisites.size();i++)
        {
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];

            matrix[u][v]=1;
        }
        

        for(int k=0;k<numCourses;k++)
        {
            for(int i=0;i<numCourses;i++)
            {
                for(int j=0;j<numCourses;j++)
                {
                    if(matrix[i][k]==true && matrix[k][j]==true)
                    {
                        matrix[i][j]=true;
                    }
                }
            }
        }
         
         vector<bool>ans;

         for( auto &q:queries)
         {
            ans.push_back(matrix[q[0]][q[1]] ==true);
         }
        
        return ans;
    }
};