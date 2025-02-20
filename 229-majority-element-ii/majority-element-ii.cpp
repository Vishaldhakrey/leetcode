class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int, int>um;
        unordered_set<int>st;
        for(int i=0; i<n; i++) {
            um[nums[i]]++;
            
            if (um[nums[i]] > n/3) {
                st.insert(nums[i]);
            }
        }
        return vector<int>(st.begin(), st.end());
    }
};