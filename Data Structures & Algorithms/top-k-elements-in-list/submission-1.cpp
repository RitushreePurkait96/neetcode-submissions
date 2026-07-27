class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> num_freq_map;
        for(int i = 0; i < nums.size(); i++)
        {
            num_freq_map[nums[i]]++;
        }
        unordered_map<int, vector<int>> freq_num_map;
        for(auto itr : num_freq_map)
        {
            freq_num_map[itr.second].push_back(itr.first);
        }
        vector<int> freq;
        for(auto itr : freq_num_map)
            freq.push_back(itr.first);
        sort(freq.begin(), freq.end(), greater<int>());
        vector<int> result;
        for(int f : freq)
        {
            for(int num : freq_num_map[f])
            {
                result.push_back(num);
                if(result.size() == k)
                    return result;
            }
        }
        return result;
    }
};
