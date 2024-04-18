class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       int cnt=0;
        int prevSum = 0;
        unordered_map<int, int>um;
        um[0] = 1;
       for(int i=0; i<nums.size(); i++){
        prevSum += nums[i];
        int remove = prevSum - k;
        cnt += um[remove];
        um[prevSum]++;
       }
       return cnt; 
    }
};