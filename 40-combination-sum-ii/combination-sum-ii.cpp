class Solution {
public:

void findsubset(int i,vector<int>&ds,vector<vector<int>>&allsubset,vector<int>&arr,int target)
{
    if(target==0)
    {
        allsubset.push_back(ds);
        return;
    }

    if(i==arr.size())
    {
        return;
    }

    if(arr[i]<=target)
    {
        ds.push_back(arr[i]);
        findsubset(i+1,ds,allsubset,arr,target-arr[i]);
         ds.pop_back();
         
         int idx=i+1;
        while(idx<arr.size()&&arr[idx]==arr[idx-1])
        {
            idx++;
        }       

       findsubset(idx,ds,allsubset,arr,target);

    }
    
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>ds;
        vector<vector<int>>allsubset;
         sort( candidates.begin(), candidates.end());
        findsubset(0,ds,allsubset,candidates,target);
       
        return allsubset;
    }
};