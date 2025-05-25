class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        int maxJumpPos = 0;
        int i=0;
        int indx = 0;
        while (i < n-1) {
            int jump_idx = i + nums[i];

            if (i == jump_idx) return false;
            for (int j=i+1; j <= jump_idx; j++) {
                
                if ((j+nums[j] >= n-1)) {
                    return true;
                }
                if ((j+nums[j]) >= maxJumpPos) {
                    indx = j;
                    maxJumpPos = j+nums[j];
                }
            }

            i = indx;
        }

        return i >= n-1;
    }
};