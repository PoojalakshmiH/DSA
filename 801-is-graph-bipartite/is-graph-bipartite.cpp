class Solution {
public:

   

    bool bfs(vector<vector<int>>& graph,vector<int>&color,int n,int i)
    {
        queue<int>q;
         color[i]=0;
        q.push(i);
       
        while(!q.empty())
        {
            int u=q.front();
            q.pop();

            for(auto v:graph[u])
            {
                if(color[v]==-1)
                {
                    color[v]=!color[u];
                    q.push(v);
                }
                else if(color[u]==color[v])
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {

     int n=graph.size();
     vector<int>color(n,-1);

     for(int i=0;i<n;i++)
     {
        if(color[i]==-1)
        {
            if(bfs(graph,color,n,i)==false)
             return false;
        }
     }    
    
    return true;

    }
};