class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
      unordered_map<int,int>m;
      vector <int>ans;

       for(int i=0;i<nums.size();i++)
       {
          int first =nums[i];
          int second=target-nums[i];
           
           if(m.find(second)!=m.end())
           {
                return {i, m[second]};
           }

        m[first]=i;

       }
       return {};
    }    
};