class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        return searchHelper(nums, 0, n - 1, target);
    }
    
    int searchHelper(vector<int>& nums, int start, int end, int target) {
        // Base case should only trigger when the range is invalid (start > end)
        if (start > end) {
            return -1;
        }
        
        // Must add 'start' offset to get the correct middle index
        int mid = start + (end - start) / 2;
        
        // Check if we found the target
        if (nums[mid] == target) {
            return mid;
        }
        // If target is smaller, search the left half
        else if (nums[mid] > target) {
            return searchHelper(nums, start, mid - 1, target);
        }
        // If target is larger, search the right half
        else {
            return searchHelper(nums, mid + 1, end, target);
        }
    }
};