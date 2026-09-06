class Solution {
public:
    void merge(vector<pair<int,int>>& nums,int low,int mid ,int high,vector<int>& count)
    {
        int left=low;
        int right=mid+1;
        int rightcount=0;
        vector<pair<int,int>>temp;
        while(left<=mid&&right<=high) 
        {
            if(nums[left].first<=nums[right].first)
            {
                count[nums[left].second]+=rightcount;
                temp.push_back({nums[left].first,nums[left].second});
                left++;
            }
            else
            {
                rightcount+=1;
                temp.push_back({nums[right].first,nums[right].second});
                right++;
            }
        }
        while(left<=mid)
        {
            count[nums[left].second]+=rightcount;
              temp.push_back({nums[left].first,nums[left].second});
            left++;
        }

        while(right<=high)
        {
           temp.push_back({nums[right].first,nums[right].second});
            right++;
        }

        for(int i=low;i<=high;i++)
        {
            nums[i]=temp[i-low];
        }
    }

    void mergesort(vector<pair<int,int>>& nums,int low,int high,vector<int>& count)
    {
        if(low>=high)
        {
            return;
        }
        int mid = low + (high-low)/2;
         mergesort(nums,low,mid,count);
         mergesort(nums,mid+1,high,count);
        
        merge(nums,low,mid,high,count);
    }



    vector<int> countSmaller(vector<int>& arr) {
        int n=arr.size();
        vector<int>count(n,0);
        vector<pair<int,int>>nums;
        for(int i=0;i<n;i++)
        {
            nums.push_back({arr[i],i});
        }

       mergesort(nums,0,n-1,count);
       return count;

    }
};