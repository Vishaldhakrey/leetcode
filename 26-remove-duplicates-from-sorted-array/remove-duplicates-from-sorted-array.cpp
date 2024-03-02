class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
         std::set<int> seen;
    std::vector<int> result;

    for (int num : nums) {
        if (seen.find(num) == seen.end()) {
            seen.insert(num);
            result.push_back(num);
        }
    }

    nums = result;
    return result.size();

        // int count=0;
        // for(int i=1; i<n; i++){
        //     if(nums[i] != nums[count]){
        //         nums[count+1] = nums[i];
        //         count++;
        //     }
        // } 
        // return count+1;
    }
};