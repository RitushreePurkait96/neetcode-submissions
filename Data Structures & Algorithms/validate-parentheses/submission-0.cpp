class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> st;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                st.push(s[i]);
            }
            else
            {
                if(st.empty())
                {
                    return false;
                }
                char par = st.top();
                if((s[i] == ')' && par != '(') 
                || (s[i] == '}' && par != '{')
                || (s[i] == ']' && par != '['))
                {
                    return false;
                }  
                st.pop();
                }
        }
        return st.empty();
    }
};
