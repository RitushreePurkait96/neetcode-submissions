class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> allSubsets;
        vector<int> currentSubset;
        getSubsets(nums, 0, currentSubset, allSubsets);
        return allSubsets;    
    }

    void getSubsets(vector<int>& nums, int index, vector<int>& currentSubset, vector<vector<int>>& allSubsets)
    {
        allSubsets.push_back(currentSubset);
        for(int i = index; i < nums.size(); i++)
        {
            if(i > index && (nums[i] == nums[i-1]))
            {
                continue;
            }
            else
            {
                currentSubset.push_back(nums[i]);
                getSubsets(nums, i+1, currentSubset, allSubsets);
                currentSubset.pop_back();
                
            }
        }
    }
};
