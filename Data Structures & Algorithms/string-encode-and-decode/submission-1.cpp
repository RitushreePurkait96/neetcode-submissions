/*
The Standard Solution: Length Prefixing (Length#String)
To make the encoding stateless and reliable regardless 
of what characters are inside the strings 
(spaces, symbols, or even empty strings), 
prefix each string with its length, 
followed by a delimiter like #.
For example:
["hello", "world"] --> "5#hello5#world"
[""] --> "0#"
["a#b", "c"] --> "3#a#b1#c" 
(Notice the inner # doesn't break decoding because we explicitly read 3 characters!)
*/

class Solution {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encodedStr = "";
        for (const string& str : strs) {
            encodedStr += to_string(str.size()) + "#" + str;
        }
        return encodedStr;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> decodedStrs;
        int i = 0;

        while (i < s.size()) {
            // Find where the '#' delimiter is
            int j = i;
            while (s[j] != '#') {
                j++;
            }

            // Extract the length of the upcoming string
            int length = stoi(s.substr(i, j - i));

            // Extract the actual string using the length
            string str = s.substr(j + 1, length);
            decodedStrs.push_back(str);

            // Move pointer past the extracted string
            i = j + 1 + length;
        }

        return decodedStrs;
    }
};