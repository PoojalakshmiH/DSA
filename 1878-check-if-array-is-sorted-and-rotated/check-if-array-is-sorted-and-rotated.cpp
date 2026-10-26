class Solution {
public:
    bool check(vector<int>& nums) {

        int j=-1;
        int n=nums.size();
        for(int i=0;i<n-1;i++)
        {
           if(nums[i]>nums[i+1])
           {
            j=i+1;
            break;
           }
        }

        if(j==-1)
        {
            return true;
        }
        reverse(nums.begin(),nums.begin()+j);
        reverse(nums.begin()+j,nums.end());
        reverse(nums.begin(),nums.end());

        for(int i=0;i<n-1;i++)
        {
            if(nums[i]>nums[i+1])
            {
                return false;
            }
        }
        return true;
        
    }
};