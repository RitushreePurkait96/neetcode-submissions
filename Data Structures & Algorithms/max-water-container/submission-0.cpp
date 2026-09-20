class Solution {
public:
    int maxArea(vector<int>& heights) 
    {
        int size = heights.size();
        int i = 0;
        int j = size - 1;
        int water;
        int maxWater = INT_MIN;
        while(i < j)
        {
            water = (j - i) * min(heights[i], heights[j]);
            maxWater = max(water, maxWater);
            if(heights[i] < heights[j])
                i++;
            else 
                j--;
        }
        return maxWater;    
    }
};
