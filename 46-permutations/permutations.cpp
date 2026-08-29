class Solution {
public:


    void findperm( int idx , vector<int>& nums,vector<vector<int>> &allper)
    {
      
      if(idx==nums.size())
      {
        allper.push_back(nums);
        return;
      }

      for(int i=idx;i<nums.size();i++)
      {
        swap(nums[i],nums[idx]);
        findperm(idx+1,nums,allper);
        swap(nums[i],nums[idx]);
      }

    }


    vector<vector<int>> permute(vector<int>& nums) {

     vector<vector<int>>allper;
     findperm(0,nums,allper);

     return allper;

    }
};