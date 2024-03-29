class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // int count = 0;
        // int val = -1;
        // int votes = 0;
        // int n = nums.size();
        // for(int i=0; i<n; i++){
        //     if(votes == 0){
        //         val = nums[i];
        //         votes=1;
        //     }
        //     else{
        //         if(nums[i] == val){
        //             votes++;
        //         }
        //         else{
        //             votes--;
        //         }
        //     }
        // }

        // for(int i=0; i<n; i++){
        //     if(nums[i] == val){
        //         count++;
        //     }
        // }
        // if(count>n/2){
        //     return val;
        // }
        // return -1;
/***************************************/
        // sort(nums.begin(), nums.end());

        // int n = nums.size();
        // return nums[n/2];

/****************************************/
        int n = nums.size();
        unordered_map<int, int>m;
        for(int i=0; i<n; i++){
            m[nums[i]]++;
        }
        n=n/2;

        for(auto x : m){
            if(x.second > n){
                return x.first;
            }
        }
        return -1;
    }
};