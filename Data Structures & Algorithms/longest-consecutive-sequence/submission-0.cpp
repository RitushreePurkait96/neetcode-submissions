class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int n = nums.size();
        if(n == 0) return 0;
        int longest = 0;
        unordered_set<int> uniqueNums;
        for(int i = 0; i < n; i++)
        {
            uniqueNums.insert(nums[i]);
        }
        for(auto itr : uniqueNums)
        {
            if(uniqueNums.find(itr - 1) == uniqueNums.end())
            {
             int count = 1;
             int currElement = itr;
             while(uniqueNums.find(currElement + 1) != uniqueNums.end())
             {
                count++;
                currElement += 1;
             }
             longest = max(longest, count);
            }
        }
        return longest;   
    }
};
