/*

The Correct Approach (Mental Model)
Maintain a stack that stores indices of temperatures in strictly decreasing order.

As you iterate through the array at index i, check if the current temperature is warmer than the temperature at the index stored at st.top().

If it is, that means you've found the "next warmer day" for st.top(). Pop it from the stack, calculate the distance (i - st.top()), and repeat this check in a while loop until the stack is empty or the top temperature is warmer than or equal to the current one.

Push the current index i onto the stack.
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> output(n, 0);
        stack<int> st; // Stores indices of the temperatures
        
        for (int i = 0; i < n; i++) {
            // While the stack isn't empty and the current temperature 
            // is warmer than the temperature at the top of the stack
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevIndex = st.top();
                st.pop();
                
                // The number of days waited is the difference in indices
                output[prevIndex] = i - prevIndex;
            }
            // Push the current index onto the stack
            st.push(i);
        }
        
        return output;
    }
};
