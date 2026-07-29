class Solution {
public:

    string encode(vector<string>& strs) 
    {
        string encodedStr;
        for(const string& str : strs)
        {
            encodedStr += to_string(str.size()) + "#" + str;
        }
        return encodedStr;
    }

    vector<string> decode(string s) 
    {
        vector<string> decodedStrs;
        int i = 0;
        while(i < s.size())
        {
            int j = i;
            while(s[j] != '#')
                j++;
            int length = stoi(s.substr(i, j-i));
            string str = s.substr(j+1, length);
            decodedStrs.push_back(str);
            i = j+ length + 1;
        }
        return decodedStrs;
    }
};
