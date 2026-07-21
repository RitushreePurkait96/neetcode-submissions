class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int, int> m;
        for(int i = 0; i < nums.size(); i++)
        {
            auto itr = m.find(nums[i]);
            if(itr != m.end())
                return true;
            m.insert({nums[i], i});
        }
        return false;
        
    }
};