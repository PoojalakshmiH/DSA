class Solution {
public:
    
 bool isIdealPermutation(vector<int>& nums) {
    int n=nums.size();
    int maxval=nums[0];

    for(int i=2;i<n;i++)
    {
        maxval=max(maxval,nums[i-2]);
        if(maxval>nums[i])
        {
            return false;
        }
      
    }
      return true;
    }
};