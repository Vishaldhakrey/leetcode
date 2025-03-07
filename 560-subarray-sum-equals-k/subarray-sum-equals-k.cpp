class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       int n = nums.size();

        unordered_map<int, int>um;
        um[0] = 1; //already seen

        int result = 0;
        int curr_sum = 0;

       for (auto &num : nums) {
            curr_sum += num;

            int remaining = curr_sum - k;

            result += um[remaining];
            um[curr_sum]++;
       }
       return result;
    }
};