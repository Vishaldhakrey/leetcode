class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        if (k > n) return {};
        vector<int>result(n-k+1, -1);
        for (int i=0; i<=n-k; i++){
            bool isTrue = true;
            for (int j=i; j<k+i-1; j++) {
                if (nums[j]+1 != nums[j+1]) {
                    isTrue = false;
                    break;
                }
            }
            if (isTrue) {
                result[i] = nums[i+k-1];
            }
        }
        return result;
    }
};