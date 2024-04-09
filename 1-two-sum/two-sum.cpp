class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>um;
        for(int i=0; i<nums.size(); i++){
            int num = nums[i];
            int rem = target - num;
            if(um.find(rem) != um.end()){
                return {um[rem], i};
            }
            um[num] = i;
        }
        return {-1, -1};

    }
};