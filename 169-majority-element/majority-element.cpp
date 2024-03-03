class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int val = -1;
        int votes = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(votes == 0){
                val = nums[i];
                votes=1;
            }
            else{
                if(nums[i] == val){
                    votes++;
                }
                else{
                    votes--;
                }
            }
        }

        for(int i=0; i<n; i++){
            if(nums[i] == val){
                count++;
            }
        }
        if(count>n/2){
            return val;
        }
        return -1;
    }
};