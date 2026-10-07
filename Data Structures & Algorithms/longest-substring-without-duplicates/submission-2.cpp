class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int n = s.size();
        unordered_map<char, int> mp;
        int left = 0;
        int maxLength = 0;
        for(int i = 0; i < n; i++)
        {
            if(mp.find(s[i]) != mp.end() && mp[s[i]] >= left)
            {
                
                left = mp[s[i]] + 1;
            }
            mp[s[i]] = i;
            maxLength = max(maxLength, (i - left + 1));
        }  
        return maxLength;  
    }
};
