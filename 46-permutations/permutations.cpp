class Solution {
public:
    void findPermutation(vector<int>& nums, vector<vector<int>>&ans, int ind){
        if(nums.size() == ind){
            ans.push_back(nums);
            return;
        }

        for(int i=ind; i<nums.size(); i++){
            swap(nums[ind], nums[i]);
            findPermutation(nums, ans, ind+1);
            swap(nums[ind], nums[i]);
        }
        // if(nums.size() == ds.size()){
        //     ans.push_back(ds);
        //     return;
        // }
        // for(int i=0; i<nums.size(); i++){
        //     if(!freq[i]){
        //         ds.push_back(nums[i]);
        //         freq[i] = 1;
        //         findPermutation(nums, ans, ds, freq);
        //         freq[i] = 0;
        //         ds.pop_back();
        //     }
        // }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector < vector < int >> ans;
        findPermutation(nums, ans, 0);
        return ans;
    }
};