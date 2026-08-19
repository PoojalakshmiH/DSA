class Solution {
public:
    int majorityElement(vector<int>& nums) {
        

        unordered_map<int,int>m;

        for(int i=0;i<nums.size();i++)
        {
            if(m.find(nums[i])==m.end())
            {
                m[nums[i]]=0;
            }
            m[nums[i]]++;
        }

        for(int i=0;i<nums.size();i++)
         {
            if(m[nums[i]]>(nums.size()/2))
               return nums[i];
         }
         return -1;
    }
};