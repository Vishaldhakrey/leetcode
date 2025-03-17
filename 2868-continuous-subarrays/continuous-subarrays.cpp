class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long result = 0;
        multiset<int> st;  // Stores elements in sorted order

        int l = 0, r = 0;
        while (r < n) {
            st.insert(nums[r]);  // Expand window by inserting nums[r]

            // Shrink window if max - min > 2
            while (*st.rbegin() - *st.begin() > 2) {  
                st.erase(st.find(nums[l])); // Remove nums[l]
                l++;
            }

            result += (r - l + 1);  // Count valid subarrays
            r++;  // Move right pointer
        }
        return result;
    }
};
