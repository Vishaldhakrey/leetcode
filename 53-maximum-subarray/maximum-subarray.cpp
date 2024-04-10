class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        //using kadan's algorithm
        int maxSum = INT_MIN;
        int sum = 0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            if(sum > maxSum){
                maxSum = sum;
            }
            if(sum<0){
                sum = 0;
            }
        }
        return maxSum;
    }
};