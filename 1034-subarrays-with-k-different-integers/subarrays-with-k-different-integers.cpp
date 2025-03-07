class Solution {
public:
    int slidingWindow(vector<int>&nums, int k) {
        int n = nums.size();

        unordered_map<int,int>mp;
        int cnt = 0;

        int l=0, r=0;
        while (r < n) {
            mp[nums[r]]++;

            //If map size is greater than the k distinct element than shrinking the window 
            while (mp.size() > k) {
                mp[nums[l]]--;
                if (mp[nums[l]] == 0) {
                    mp.erase(nums[l]);
                }
                l++;
            }

            //stored all the possible subarray
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return slidingWindow(nums, k) - slidingWindow(nums, k-1);
    }
};