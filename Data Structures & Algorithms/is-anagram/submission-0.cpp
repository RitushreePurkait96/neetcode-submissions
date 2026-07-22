class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        map<char, int> sMap;
        if(s.size() != t.size())
            return false;
        for(int i = 0; i < s.size(); i++)
        {
            sMap[s[i]]++;
        }
        for (int i = 0; i < t.size(); i++)
        {
            sMap[t[i]]--;
        }
        for(auto itr : sMap)
        {
            if(itr.second != 0)
                return false;
        }
        return true;
    }
};
