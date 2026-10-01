class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        queue<vector<int>>q;
        vector<vector<int>>ans;
        int n=graph.size();
        q.push({0});

        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int node=it.back();

            if(node==n-1)
            {
                ans.push_back(it);
            }

            
                for(int v:graph[node])
                {
                    it.push_back(v);
                    q.push({it});
                    it.pop_back();
                }
            
        }
    return ans;
    }
};