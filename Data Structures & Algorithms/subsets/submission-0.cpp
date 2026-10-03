class Solution {
public:
    void getAllSubsets(vector<int>& nums, vector<int>& subSet, int index, vector<vector<int>>& allSubsets)
    {
        if(index == nums.size())
        {
            //push the subset
            allSubsets.push_back({subSet}); 
            return;
        }

        // Include the curent element into the subset
        subSet.push_back(nums[index]);
        getAllSubsets(nums, subSet, index+1, allSubsets);

        //Exclude the current element from subset
        subSet.pop_back();
        getAllSubsets(nums, subSet, index+1, allSubsets);
    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> allSubsets;
        vector<int> subSet;
        getAllSubsets(nums, subSet, 0, allSubsets);
        return allSubsets;    
    }
};
