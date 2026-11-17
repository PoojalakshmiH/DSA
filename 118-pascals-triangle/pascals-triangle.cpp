class Solution {
public:
    vector<int> generaterow(int n)
    {
        vector<int>ans;

        ans.push_back(1);

        int res=1;
        for(int i=1;i<n;i++)
        {
            res=res*(n-i);
            res=res/i;
            ans.push_back(res);
        }
        return  ans;
    }
   
    vector<vector<int>> generate(int numRows) {
    vector<vector<int>>ans;

    for(int i=1;i<=numRows;i++) 
    {
          ans.push_back(generaterow(i));
    }          
  
     return ans;

    }
};