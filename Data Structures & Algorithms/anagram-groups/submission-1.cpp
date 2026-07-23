class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;

        for (const string& s : strs) {
            // 1. Count character frequencies (26 letters initialized to 0)
            vector<int> count(26, 0);
            for (char c : s) {
                count[c - 'a']++;
            }

            // 2. Build a unique key string out of the frequency array
            // Example: "1#0#1#0#..." 
            string key = "";
            for (int i = 0; i < 26; i++) {
                key += to_string(count[i]) + "#";
            }

            // 3. Group the original string by its frequency key
            anagramGroups[key].push_back(s);
        }

        // Collect all groups into the final result
        vector<vector<string>> result;
        for (auto& pair : anagramGroups) {
            result.push_back(pair.second);
        }

        return result;
    }
};