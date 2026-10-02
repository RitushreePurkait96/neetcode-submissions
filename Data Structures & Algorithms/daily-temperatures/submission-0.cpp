class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        int n = temperatures.size();
        vector<int> output(n, 0);
        stack<int> indexSt;
        for(int i = 0; i < n; i++)
        {
            while(!indexSt.empty() && temperatures[i] > temperatures[indexSt.top()])
            {
                int prevIndex = indexSt.top();
                indexSt.pop();

                output[prevIndex] = i - prevIndex;    
            }
            indexSt.push(i);
        }
        return output;
    }
};
