class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxEle = *max_element(nums.begin(), nums.end());

        int n = nums.size();
        int cnt = 0;
        long result = 0;
        int l=0, r=0;

        while (r < n) {
            if (nums[r] == maxEle) {
                cnt += 1;
            }

            while (cnt >= k) {
                result += (n-r);
                if (nums[l] == maxEle) {
                    cnt--;
                }
                l++;
            }
            r++;
        } 
        return result;
    }
};