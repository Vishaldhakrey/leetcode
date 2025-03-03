class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_set<int>st;

        int i=0, j=0; 
        while (j < n) {
            if (abs(j-i) > k) {
                st.erase(nums[i]);
                i++;
            }
            if (st.count(nums[j])) {
                return true;
            }
            st.insert(nums[j]);
            j++;
        }
        return false;
    }
};