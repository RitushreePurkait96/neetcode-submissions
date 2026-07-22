class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numsMap;
        vector<int> result;
        for(int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if(numsMap.find(complement) != numsMap.end())
            {
                result.push_back(numsMap.find(complement)->second);
                result.push_back(i);
                return result;
            }
            numsMap[nums[i]] = i;
        }
        return {0};
    }
};
