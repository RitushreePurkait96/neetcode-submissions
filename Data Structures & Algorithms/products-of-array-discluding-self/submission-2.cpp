/*
Algorithm (Prefix & Suffix Pass)
Since division is not allowed, we compute two products for each index i:
Prefix product: The product of all numbers to the left of nums[i].
Suffix product: The product of all numbers to the right of nums[i].
By storing the prefix products directly inside the result vector during the first pass and then multiplying by a running suffix product during a second pass from right to left, we solve the problem in O(n) time and O(1) extra space (excluding the output array).

*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = nums.size();
        
        vector<int> prefix(n);
        vector<int> suffix(n);
        // Pass 1: Fill result with prefix products
        // result[i] contains product of all elements to the left of nums[i]
        prefix[0] = 1;
        for(int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i-1] * nums[i-1];
        }
        // Pass 2: Multiply by suffix products
        // Multiply result[i] by product of all elements to the right of nums[i]
        suffix[n-1] = 1;
        for(int j = n-2; j >= 0; j--)
        {
            suffix[j] = suffix[j+1] * nums[j+1];
        }
        vector<int> result;
        for(int i = 0; i < n; i++)
        {
            result.push_back(prefix[i] * suffix[i]);
        }
        return result;
    }
};
