class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> allPerms;
        vector<int> currPath;
        vector<bool> used(nums.size(), false);
        
        getPermutations(nums, used, currPath, allPerms);
        return allPerms;   
    }

    void getPermutations(vector<int>&nums, vector<bool>& used, vector<int>& currPath, vector<vector<int>>& allPerms)
    {
        if(currPath.size() == nums.size())
        {
            allPerms.push_back(currPath);
            return;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(used[i])
                continue;
            used[i] = true;
            // Select
            currPath.push_back(nums[i]);
            // Add
            getPermutations(nums, used, currPath, allPerms);
            //Backtrack
            currPath.pop_back();
            used[i] = false;
        }
    }
};
