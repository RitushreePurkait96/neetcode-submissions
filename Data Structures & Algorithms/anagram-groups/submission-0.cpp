// The initial solution where we are 
// 1. First sorting each of the strings as per their alphabatical order
// 2. Then storing the strings as values for the map with sorted string as the key
// 3. After that we will iterate over the map to print the value, which will be the strings in groups
// Here the time complexity is O(m * nlogn)
// m = is the number of strings, n = length of the longest string 
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string, vector<string>> anagramGroups;
        for (const string& s : strs)
        {
            string sortedStr = s;
            sort(sortedStr.begin(), sortedStr.end());
            anagramGroups[sortedStr].push_back(s);
        }
        vector<vector<string>> result;
        for(auto& pair : anagramGroups)
        {
            result.push_back(pair.second);
        }
        return result;
        
    }
};
