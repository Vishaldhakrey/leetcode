class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        unordered_map<int, int>um;
        um[0] = 1; //already seen
        int result = 0;
        int currSum = 0;
        
        for (int &num : nums) {
            currSum += num;
            
            int remainingSum = currSum - goal;

            if (um.find(remainingSum) != um.end()) {
                result += um[remainingSum];
            }
            um[currSum]++;
        }
        return result;
    }
};