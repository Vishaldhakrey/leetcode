class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        unordered_set<int>st;
        for(int i=0; i<n; i++) {
            int count = 0;
            for (int j=0; j<n; j++) {
                if (nums[i] == nums[j]) {
                    count++;
                }
            }
            if (count > n/3) {
                st.insert(nums[i]);
            }
        }
        return vector<int>(st.begin(), st.end());
    }
};