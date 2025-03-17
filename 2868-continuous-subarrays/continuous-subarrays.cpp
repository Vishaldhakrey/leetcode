class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();

        long long result = 0;
        map<int, int>mp;

        int l=0, r=0;
        while(r<n) {
            mp[nums[r]]++;

            while (abs(mp.rbegin()->first - mp.begin()->first) > 2) {
                mp[nums[l]]--;
                if(mp[nums[l]] == 0) {
                    mp.erase(nums[l]);
                }
                l++;
            }
            result += r-l+1;
            r++;
        }
        return result;
    }
};