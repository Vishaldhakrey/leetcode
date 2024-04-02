class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        int n = nums.size();
        k %= n; // Adjust k to be within the range of the vector size
        
        std::reverse(nums.begin(), nums.end()); // Reverse the entire vector
        std::reverse(nums.begin(), nums.begin() + k); // Reverse the first k elements
        std::reverse(nums.begin() + k, nums.end()); // Reverse the remaining elements after k
    }
};