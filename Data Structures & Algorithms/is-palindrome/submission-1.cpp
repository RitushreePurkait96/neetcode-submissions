class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;
        for(char &c : s)
        {
            c = tolower(static_cast<unsigned char>(c));
        }
        while(start < end)
        {
           while(start < end && (!isAlphanumeric(s[start])))
            start++;
            while(start < end && (!isAlphanumeric(s[end])))
            end--;
            if(s[start] != s[end])
                return false;
            else 
            {
                start++;
                end--;
            }

        }
        return true;    
    }

    private:
    bool isAlphanumeric(char c)
    {
     if((c < 'a' || c > 'z') && 
        (c < 'A' || c > 'Z') && 
        (c < '0' || c > '9')) 
        return false;
     else 
        return true;  
    }
};
