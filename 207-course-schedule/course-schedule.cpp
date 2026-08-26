class Solution {
public:

    bool  dfs(int src,int numCourses, vector<vector<int>>& edge,vector<bool> &vis,vector<bool> &recpath)
    {
        vis[src]=true;
        recpath[src]=true;
        
        for(int i=0;i<edge.size();i++)
        {
            int u=edge[i][1];
            int v=edge[i][0];
            

            if(src==u)
            {
                if(!vis[v])
                {
                    if(dfs(v,numCourses,edge,vis,recpath))
                    {
                        return true;
                    }

                }
                else if(recpath[v])
                {
                    return true;
                }
            }

        }
        recpath[src]=false;
            return false;

    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool>vis(numCourses,false);
       vector<bool>recpath(numCourses,false);

       for(int i=0; i<numCourses;i++)
       {
        if(!vis[i])
        {
            if(dfs(i,numCourses,prerequisites,vis,recpath))
            {
                return false;
            }
        }
       }

       return true;  

    }
};